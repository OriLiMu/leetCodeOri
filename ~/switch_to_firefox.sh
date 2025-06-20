#!/bin/bash
# 使用Wayland工具切换到Firefox窗口

if hyprctl clients | grep -q "class: firefox"; then
    hyprctl dispatch focuswindow firefox
    echo "✅ 已切换到Firefox窗口"
else
    echo "❌ Firefox窗口未找到，正在启动Firefox..."
    firefox &
fi 