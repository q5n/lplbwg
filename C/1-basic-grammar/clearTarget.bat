@echo off
chcp 65001>nul
echo 开始清除target\*...
del /s /q target\*
echo 清除完毕！
ping 127.0.0.1>nul