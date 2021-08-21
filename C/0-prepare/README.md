# 环境准备

## 一、MSVC

1. 操作系统 Windows 10

2. 编译器[Visual Studio Community 2019](https://visualstudio.microsoft.com/vs/community/)

   版本:16.8 以上( [部分支持C11,C17标准](https://docs.microsoft.com/cpp/overview/install-c17-support) )

   不支持变长数组(variable-length array，VLA),以及[其他不支持](https://devblogs.microsoft.com/cppblog/c11-and-c17-standard-support-arriving-in-msvc/)

3. Windows SDK

   [Windows SDK 10.0.20348.0 (版本 2104)](https://developer.microsoft.com/windows/downloads/windows-10-sdk/)或更高版本

4. 命令行cl.exe编译环境脚本

   [vcdev_x86.bat (32位)](vcdev_x86.bat) 

5. - [ ] **TODO** vscode配置 


6.  [C语言帮助文档](https://docs.microsoft.com/cpp/c-language/)

 

## 二、mingw-w64

1.通过msys2安装mingw-w64

[MSYS2](https://www.msys2.org/)是一个工具集环境，作用是：可以在windows中使用linux中的shell、工具或命令。

把linux下的工具程序的源码编译成windows的可执行文件



可以看作windows下的linux子环境，与wsl1有点类似。

基本原理是：基于[Cygwin项目](https://cygwin.com/)的cygwin1.dll在windows上提供 linux系统所需的POSIX API接口

在windows系统上基于一套翻译接口调用linux的

原理linux程序大多都调用

笔记:[minGw-w64笔记.txt](minGw-w64笔记.txt)

