#!/bin/bash

# Wayland版本的xdotool search --name "窗口名" windowactivate
# 用法: ./focus_window_script.sh "窗口名称"

WINDOW_NAME="$1"

if [ -z "$WINDOW_NAME" ]; then
    echo "用法: $0 \"窗口名称\""
    echo "示例: $0 \"FightForYourDreamOri\""
    exit 1
fi

echo "🔍 搜索窗口: $WINDOW_NAME"

# 搜索窗口 (不区分大小写)
FOUND_WINDOW=$(hyprctl clients | grep -i "$WINDOW_NAME")

if [ -n "$FOUND_WINDOW" ]; then
    echo "✅ 找到窗口，正在激活..."
    hyprctl dispatch focuswindow "$WINDOW_NAME"
    
    if [ $? -eq 0 ]; then
        echo "🎯 窗口已激活: $WINDOW_NAME"
    else
        echo "❌ 激活窗口失败"
    fi
else
    echo "❌ 未找到窗口: $WINDOW_NAME"
    echo "📋 当前所有窗口:"
    hyprctl clients | grep -E "(class|title)" | grep title
fi 