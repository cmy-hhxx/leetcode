#!/bin/bash

# LeetCode 新题目创建脚本
# 用法: ./new_problem.sh <number> <problem-name>
# 示例: ./new_problem.sh 2 add-two-numbers

if [ $# -ne 2 ]; then
    echo "用法: $0 <题目编号> <题目名称>"
    echo "示例: $0 2 add-two-numbers"
    exit 1
fi

PROBLEM_NUMBER=$(printf "%03d" $1)
PROBLEM_NAME=$2
FILENAME="${PROBLEM_NUMBER}-${PROBLEM_NAME}.cpp"
FILEPATH="problems/${FILENAME}"

if [ -f "$FILEPATH" ]; then
    echo "文件 $FILEPATH 已存在!"
    exit 1
fi

# 创建新的题目文件
cp template.cpp "$FILEPATH"

# 在文件开头添加题目信息注释
sed -i '' "1i\\
/*\\
 * LeetCode ${PROBLEM_NUMBER}: $(echo $PROBLEM_NAME | tr '-' ' ' | awk '{for(i=1;i<=NF;i++){$i=toupper(substr($i,1,1)) tolower(substr($i,2))}}1')\\
 * 难度: [Easy/Medium/Hard]\\
 * 链接: https://leetcode.com/problems/${PROBLEM_NAME}/\\
 * \\
 * 题目描述:\\
 * TODO: 在这里添加题目描述\\
 * \\
 * 解题思路:\\
 * TODO: 在这里添加解题思路\\
 */\\
" "$FILEPATH"

echo "已创建新题目文件: $FILEPATH"
echo "现在可以开始编码了! 🚀"

# 在 VS Code 中打开文件
code "$FILEPATH"
