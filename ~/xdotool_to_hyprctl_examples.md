# xdotool 到 hyprctl 窗口操作转换指南

## 🎯 你的具体问题

### 原始 xdotool 命令:

```bash
xdotool search --name "FightForYourDreamOri" windowactivate
```

### ✅ Wayland/Hyprland 等价命令:

```bash
# 方法1: 使用 title 标识符 (最精确)
hyprctl dispatch focuswindow "title:FightForYourDreamOri"

# 方法2: 使用 class 标识符
hyprctl dispatch focuswindow "class:kitty"

# 方法3: 先搜索再激活 (调试用)
hyprctl clients | grep -i "FightForYourDreamOri"
hyprctl dispatch focuswindow "title:FightForYourDreamOri"
```

## 📋 完整对照表

| xdotool 命令                                    | hyprctl 等价命令                              | 说明             |
| ----------------------------------------------- | --------------------------------------------- | ---------------- |
| `xdotool search --name "窗口名" windowactivate` | `hyprctl dispatch focuswindow "title:窗口名"` | 按窗口标题激活   |
| `xdotool search --class "类名" windowactivate`  | `hyprctl dispatch focuswindow "class:类名"`   | 按窗口类激活     |
| `xdotool getactivewindow`                       | `hyprctl activewindow`                        | 获取活动窗口信息 |
| `xdotool search --name "名称"`                  | `hyprctl clients \| grep "名称"`              | 搜索窗口         |
| `xdotool windowclose`                           | `hyprctl dispatch killactive`                 | 关闭活动窗口     |

## 🛠️ hyprctl focuswindow 的所有标识符选项

```bash
# 按标题匹配 (推荐用于特定窗口)
hyprctl dispatch focuswindow "title:窗口标题"

# 按类名匹配 (可能匹配多个窗口)
hyprctl dispatch focuswindow "class:应用类名"

# 按窗口地址匹配 (最精确)
hyprctl dispatch focuswindow "address:0x窗口地址"

# 按进程ID匹配
hyprctl dispatch focuswindow "pid:进程ID"

# 正则表达式匹配标题
hyprctl dispatch focuswindow "title:^Fight.*Ori$"
```

## 🚀 实用脚本模板

### 通用窗口激活脚本:

```bash
#!/bin/bash
# 用法: ./activate_window.sh "窗口标题"
WINDOW_TITLE="$1"
hyprctl dispatch focuswindow "title:$WINDOW_TITLE"
```

### 带错误处理的完整脚本:

```bash
#!/bin/bash
WINDOW_NAME="$1"

if [ -z "$WINDOW_NAME" ]; then
    echo "用法: $0 \"窗口名称\""
    exit 1
fi

# 检查窗口是否存在
if hyprctl clients | grep -q "title: $WINDOW_NAME"; then
    hyprctl dispatch focuswindow "title:$WINDOW_NAME"
    echo "✅ 已激活窗口: $WINDOW_NAME"
else
    echo "❌ 未找到窗口: $WINDOW_NAME"
    echo "📋 可用窗口:"
    hyprctl clients | grep "title:" | sed 's/.*title: /  - /'
fi
```

## 🔍 调试技巧

1. **查看所有窗口信息:**

   ```bash
   hyprctl clients
   ```

2. **只看窗口标题:**

   ```bash
   hyprctl clients | grep "title:"
   ```

3. **搜索特定窗口:**

   ```bash
   hyprctl clients | grep -i "关键词"
   ```

4. **获取当前活动窗口:**
   ```bash
   hyprctl activewindow
   ```
