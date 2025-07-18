#!/bin/bash

# 快速编译运行脚本
# 用法: ./run.sh <cpp文件路径>

if [ $# -eq 0 ]; then
    echo "用法: $0 <cpp文件路径>"
    echo "示例: $0 problems/001-two-sum.cpp"
    exit 1
fi

CPP_FILE=$1
BASE_NAME=$(basename "$CPP_FILE" .cpp)
DIR_NAME=$(dirname "$CPP_FILE")
EXEC_FILE="${DIR_NAME}/${BASE_NAME}_debug"

echo "🔨 编译 $CPP_FILE..."

# 编译文件
clang++ -std=c++14 -g -O0 -Wall -Wextra -I./include "$CPP_FILE" -o "$EXEC_FILE"

if [ $? -eq 0 ]; then
    echo "✅ 编译成功!"
    echo "🚀 运行程序..."
    echo "----------------------------------------"
    "$EXEC_FILE"
    echo "----------------------------------------"
    echo "✨ 程序执行完成!"
else
    echo "❌ 编译失败!"
    exit 1
fi
