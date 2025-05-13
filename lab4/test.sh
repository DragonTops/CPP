#!/bin/bash

export LANG=en_US.UTF-8

echo "=== Тесты программы ==="
./build/tests/argparser_tests

echo

read -p "Press any key to continue..." -n1 -s
