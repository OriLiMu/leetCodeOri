# ActivateTerminal.py 转换为 Wayland 版本说明

## 📁 文件信息

- **原始文件**: `/home/lizhe/OriNote/wikiScripts/Utils/ActivateTerminal.py`
- **新文件**: `/home/lizhe/OriNote/wikiScripts/Utils/ActivateTerminal_wayland.py`
- **转换日期**: 2024 年 1 月
- **转换类型**: X11/xdotool → Wayland/hyprctl

## 🔄 主要转换内容

### 1. 依赖库变更

```python
# 原版本
import subprocess
import os

# Wayland版本 - 新增
import json           # 解析hyprctl的JSON输出
import time           # 等待窗口启动
```

### 2. 窗口信息获取函数转换

#### 原版本 (X11):

```python
def GetActiveWindowInfo():
    winID = subprocess.check_output(["xprop", "-root", "_NET_ACTIVE_WINDOW"])...
    winClass = subprocess.check_output(["xprop", "-id", winID, "WM_CLASS"])...
    return (winID, subprocess.check_output(["xdotool", "getwindowname", winID])..., winClass)
```

#### Wayland 版本:

```python
def get_active_window_info():
    result = subprocess.check_output(["hyprctl", "activewindow", "-j"], text=True)
    window_data = json.loads(result)
    return (
        window_data.get("address", ""),
        window_data.get("title", ""),
        window_data.get("class", "")
    )
```

### 3. 窗口激活函数转换

#### 原版本 (X11):

```python
def ActivateWindowByName(name):
    os.system(f"xdotool search --name {name}  windowactivate")

def ActivateWindowByPartialName(name):
    os.system(f'xdotool search --name "{name}" windowactivate --sync')
```

#### Wayland 版本:

```python
def activate_window_by_title(title):
    cmd = ["hyprctl", "dispatch", "focuswindow", f"title:{title}"]
    result = subprocess.run(cmd, capture_output=True, text=True)
    return result.returncode == 0

def activate_window_by_partial_name(name):
    return activate_window_by_title(name)
```

### 4. 窗口存在性检查转换

#### 原版本 (X11):

```python
def IfWinExists(name):
    result = subprocess.run(f"xdotool search --name {name}".split(),
                          capture_output=True, text=True).stdout
    return result.strip() != ""
```

#### Wayland 版本:

```python
def if_window_exists(title):
    result = subprocess.check_output(["hyprctl", "clients", "-j"], text=True)
    clients_data = json.loads(result)

    for client in clients_data:
        if title in client.get("title", ""):
            return True
    return False
```

## 🆕 新增功能

### 1. 等待窗口启动功能

```python
def wait_for_window(title, max_wait=5):
    """等待窗口出现，避免竞争条件"""
    for i in range(max_wait * 10):
        if if_window_exists(title):
            return True
        time.sleep(0.1)
    return False
```

### 2. 调试信息功能

```python
def get_window_by_title(title):
    """获取详细窗口信息用于调试"""
    # 返回匹配窗口的详细信息
```

### 3. 更好的错误处理

- 添加了 try-catch 异常处理
- 添加了详细的错误消息和成功提示
- 使用表情符号增强用户体验

## 📊 命令对比表

| 功能         | X11 命令                         | Wayland 命令                                |
| ------------ | -------------------------------- | ------------------------------------------- |
| 获取活动窗口 | `xprop -root _NET_ACTIVE_WINDOW` | `hyprctl activewindow -j`                   |
| 获取窗口属性 | `xprop -id $ID WM_CLASS`         | `hyprctl clients -j`                        |
| 获取窗口标题 | `xdotool getwindowname $ID`      | 包含在 clients JSON 中                      |
| 搜索窗口     | `xdotool search --name "标题"`   | `hyprctl clients -j` + JSON 解析            |
| 激活窗口     | `xdotool windowactivate $ID`     | `hyprctl dispatch focuswindow "title:标题"` |

## ✅ 测试结果

```bash
$ python3 ActivateTerminal_wayland.py
🔍 检查窗口是否存在: FightForYourDreamOri
✅ 找到窗口，正在激活...
✅ 成功激活窗口: FightForYourDreamOri
📋 匹配的窗口信息:
  - 标题: FightForYourDreamOri
    类: kitty
    工作区: 1
🎯 脚本执行完成
```

## 🎯 优势

1. **更可靠**: 使用 JSON 输出，避免字符串解析错误
2. **更快速**: hyprctl 比 xdotool 响应更快
3. **更安全**: 避免 shell 注入风险
4. **更现代**: 适配 Wayland 协议
5. **更友好**: 添加了丰富的用户反馈

## 🔧 使用方法

```bash
# 使用默认终端 (alacritty)
python3 ActivateTerminal_wayland.py

# 使用kitty终端
python3 ActivateTerminal_wayland.py kitty
```

## 📝 注意事项

1. **依赖**: 需要 Hyprland 窗口管理器
2. **JSON**: 使用 `-j` 参数获取 JSON 格式输出
3. **窗口标识**: 使用 `title:` 前缀来精确匹配窗口标题
4. **等待机制**: 新增窗口启动等待，避免竞争条件
