# 设置最低 CMake 版本
cmake_minimum_required(VERSION 3.10)
project(leetCode)

# 设置 C++ 标准（保持不变）
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. 强制设置构建类型为 Debug（关键：确保调试模式）
set(CMAKE_BUILD_TYPE Debug)

# 2. 设置编译器为 clang++（保持不变）
set(CMAKE_CXX_COMPILER clang++)

# 3. 调试模式专用 Flags（核心优化点）
# -O0：关闭所有优化（避免变量被编译器优化掉，确保变量存在于内存中）
# -g3：生成最详细的调试信息（包含宏定义、局部变量、函数参数等）
# -fsanitize=undefined,address：保留用户原有的 sanitizer 需求（不影响调试）
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g3 -fsanitize=undefined,address")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fsanitize=undefined,address")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -U_GLIBCXX_DEBUG")

# 4. 释放模式 Flags（可选，不影响调试）
# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# 添加可执行文件（保持不变）
add_executable(leetCode main.cpp)

# set for zed editor
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
