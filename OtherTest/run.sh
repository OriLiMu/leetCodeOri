#!/usr/bin/bash
# 1. 创建构建目录（推荐在项目根目录下）
mkdir build
cd build

# 2. 生成构建系统（在build目录中）
cmake ..

# 3. 编译项目
cmake --build .
# 或者直接使用 make（在Unix系统中）
make

# 4. 运行可执行文件（假设可执行文件名为 myapp）
./myprogram
