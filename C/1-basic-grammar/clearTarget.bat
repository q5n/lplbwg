@echo off
chcp 65001>nul
echo start clear: target\*...
del /s /q target\*
echo clear over!
ping 127.0.0.1>nul