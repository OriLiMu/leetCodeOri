# 设置最低 CMake 版本
cmake_minimum_required(VERSION 3.10)
project(leetCode)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置编译器为 clang++
set(CMAKE_CXX_COMPILER clang++)

# 添加 UBSan 和 ASan 标志
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined,address -g -O1")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined,address -g")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined,address")

# 添加可执行文件
add_executable(leetCode main.cpp)