#!/bin/bash

# Устанавливаем кодировку UTF-8
export LANG=en_US.UTF-8

echo "=== Пример 1: Суммирование чисел 1 2 3 ==="
./build/bin/labwork5 1 2 3 --sum
echo

echo "=== Пример 2: Умножение чисел 4 5 6 ==="
./build/bin/labwork5 4 5 6 --mult
echo

# Пауза
read -p "Press any key to continue..." -n1 -s
