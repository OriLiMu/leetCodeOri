# 设置最低 CMake 版本
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(MyProject)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置编译器为 clang++
set(CMAKE_CXX_COMPILER clang++)

# 添加 UBSan (Undefined Behavior Sanitizer) 标志
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined")

# 添加可执行文件
add_executable(myprogram main.cpp)
