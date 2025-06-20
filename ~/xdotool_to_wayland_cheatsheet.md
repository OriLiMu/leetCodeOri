# xdotool 到 Wayland 工具迁移指南

## 🔄 工具对应关系

| 功能类别 | xdotool    | Wayland 替代  | 状态      |
| -------- | ---------- | ------------- | --------- |
| 键盘输入 | xdotool    | ydotool/wtype | ✅ 已安装 |
| 鼠标操作 | xdotool    | ydotool       | ✅ 已安装 |
| 剪贴板   | xclip/xsel | wl-clipboard  | ✅ 已安装 |
| 窗口管理 | xdotool    | hyprctl       | ✅ 已安装 |

## 📝 命令对照表

### 键盘输入

```bash
# xdotool 方式
xdotool type "Hello World"
xdotool key ctrl+c
xdotool key alt+Tab

# Wayland 方式
ydotool type "Hello World"        # 需要input组权限
wtype "Hello World"               # 立即可用
ydotool key ctrl+c                # 需要input组权限
wtype -k ctrl c                   # 立即可用
```

### 鼠标操作

```bash
# xdotool 方式
xdotool mousemove 100 200
xdotool click 1
xdotool click --repeat 2 1

# Wayland 方式 (ydotool)
ydotool mousemove 100 200         # 需要input组权限
ydotool click 1                   # 左键点击
ydotool click --repeat 2 1        # 双击
```

### 剪贴板操作

```bash
# X11 方式
echo "text" | xclip -selection clipboard
xclip -selection clipboard -o

# Wayland 方式
echo "text" | wl-copy             # 立即可用
wl-paste                          # 立即可用
```

### 窗口管理

```bash
# xdotool 方式
xdotool getactivewindow
xdotool search --name "firefox"
xdotool windowactivate 123456

# Wayland 方式 (Hyprland)
hyprctl activewindow              # 立即可用
hyprctl clients | grep firefox   # 立即可用
hyprctl dispatch focuswindow firefox # 立即可用
```

## 🛠️ 实用脚本示例

### 1. 自动输入用户名密码

```bash
#!/bin/bash
# X11版本
xdotool type "username"
xdotool key Tab
xdotool type "password"
xdotool key Return

# Wayland版本
wtype "username"
wtype -k Tab
wtype "password"
wtype -k Return
```

### 2. 窗口切换和操作

```bash
#!/bin/bash
# X11版本
xdotool search --name "firefox" windowactivate
xdotool key ctrl+t

# Wayland版本 (Hyprland)
hyprctl dispatch focuswindow firefox
wtype -k ctrl t
```

### 3. 截图后复制到剪贴板

```bash
#!/bin/bash
# X11版本
import -window root /tmp/screenshot.png
xclip -selection clipboard -t image/png < /tmp/screenshot.png

# Wayland版本
grim /tmp/screenshot.png
wl-copy < /tmp/screenshot.png
```

## ⚠️ 注意事项

1. **ydotool 权限**: 需要重新登录后才能使用（已添加到 input 组）
2. **wtype 限制**: 只能输入键盘，不能操作鼠标
3. **hyprctl 限制**: 只在 Hyprland 窗口管理器下工作
4. **安全性**: Wayland 工具通常有更严格的安全限制

## 🔧 当前系统状态

- ✅ ydotool: 已安装（需要重新登录）
- ✅ wtype: 已安装并可用
- ✅ wl-clipboard: 已安装并可用
- ✅ hyprctl: 已安装并可用

## 🚀 快速测试命令

```bash
# 测试文本输入
wtype "Hello from Wayland!"

# 测试剪贴板
echo "测试内容" | wl-copy && wl-paste

# 测试窗口信息
hyprctl activewindow | head -3

# 测试键盘快捷键 (小心使用)
wtype -k ctrl l   # 清除地址栏或终端
```
