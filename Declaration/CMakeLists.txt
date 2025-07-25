# 设置 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.20)

# 定义项目名称和语言
project(ModernCppGreeter CXX)

# 设置 C++ 标准为 C++23，并要求编译器必须支持
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 打印状态信息，方便调试
message(STATUS "Project Name: ${PROJECT_NAME}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")

# 添加可执行文件，并指定它的源文件
add_executable(
    main
    main.cpp
    greeter.cpp
    greeter.h
)

# ------------------------------------------------------------------
# 核心：解决 std::println 在 MinGW GCC 上的链接问题
# ------------------------------------------------------------------
# 链接 C++ 标准库的实验性功能库 (stdc++exp)，
# 它包含了 std::print 等功能的实现。
target_link_libraries(main PRIVATE stdc++exp)

message(STATUS "Target 'main' created and linked with 'stdc++exp'.")