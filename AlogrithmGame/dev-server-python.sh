#!/bin/bash

# 备用开发服务器 - 使用 Python
# 不会有 CSP 问题，但不支持自动刷新

echo "================================"
echo "启动 Python 开发服务器..."
echo "================================"
echo ""
echo "服务器将在 http://localhost:8080 启动"
echo "注意：需要手动刷新浏览器才能看到更改"
echo ""
echo "按 Ctrl+C 停止服务器"
echo ""

python3 -m http.server 8080
