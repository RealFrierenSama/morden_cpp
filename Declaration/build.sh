#!/bin/bash

# --- 脚本配置 ---
# 设置构建目录的名称
BUILD_DIR="build"

# --- 脚本主体 ---

# 1. 切换到脚本文件所在的目录
# 这确保了无论从哪里运行脚本，路径都是正确的
cd "$(dirname "$0")" || exit

# 打印当前工作目录，方便调试
echo "==> Current working directory: $(pwd)"

# 2. 清理旧的构建目录
if [ -d "$BUILD_DIR" ]; then
    echo "==> Found old build directory. Removing '$BUILD_DIR'..."
    rm -rf "$BUILD_DIR"
fi

# 3. 创建新的构建目录并进入
echo "==> Creating new build directory: '$BUILD_DIR'"
mkdir "$BUILD_DIR"
cd "$BUILD_DIR" || exit

# 4. 运行 CMake 来配置项目
# -G "MinGW Makefiles" 是为你的环境指定的生成器
echo "==> Configuring project with CMake..."
cmake .. -G "MinGW Makefiles"

# 检查 CMake 配置是否成功
if [ $? -ne 0 ]; then
    echo "==> CMake configuration failed. Aborting."
    exit 1
fi

# 5. 运行构建命令
echo "==> Building project..."
cmake --build .

# 检查构建是否成功
if [ $? -ne 0 ]; then
    echo "==> Build failed. Aborting."
    exit 1
fi

echo "==> Build successful! Executable is in the '$BUILD_DIR' directory."

# 6. (可选) 构建成功后自动运行程序
# 如果想自动运行，请取消下面这行的注释
# echo "==> Running executable..."
# ./main.exe