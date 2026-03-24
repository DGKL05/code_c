#!/bin/bash

# 编译C++程序
g++ -o my_program my_program.cpp

# 检查是否传递了 --time 参数
if [[ "$1" == "--time" ]]; then
    ./my_program --time  # 启用计时
else
    ./my_program          # 正常执行
fi