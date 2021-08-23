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

 

## 二、MinGW-W64

### 1. Cygwin、MinGW、MinGW-W64、MSYS、MSYS2

**a)** [Cygwin](https://cygwin.com/)是一个工具集环境，作用是：可以在windows中使用unix中的shell、工具或命令。可以看作windows下的**类unix子环境**，与wsl1有点类似。

基本原理是：基于一个中间库cygwin1.dll在windows上提供 unix系统所需的POSIX API接口，于是原来基于unix的常用工具的源码，可以编译成windows可执行文件；

unix命令行工具一般是基于shell运行的，所以连shell也要一起编译(也有部分需要额外移植的工作)，将常用的shell、unix命令工具编译后集成到一起就成了windows中的一个类似unix的子环境。

基于cygwin编译的程序必须依赖cygwin1.dll库，而且程序经过一层翻译，性能上也有些损耗，于是出现了MinGW

**b)** [MinGW](https://sourceforge.net/projects/mingw/)是对**GNU gcc编译工具及其相关工具链**在windows上的移植(从cygwin发展而来)，不再依赖中间库，直接调用windows api (并不提供某些难以用 Windows API 实现的 POSIX API，如 fork()，mmap() 和 ioctl())。重视简化与性能。

支持交叉编译(如：在linux系统下利用MinGW-GCC可以编译在windows系统运行的可执行文件)

由于gcc是unix程序，所以使用unix-shell环境编译会比较方便，最初用的就是cygmin,但是cygwin太多，扩展性、灵活性又差，所以出现了msys

**c)** MSYS也是基于cygmin的类unix环境，是它的简化版本。提供了MinGW需要的终端、shell等等基本环境。更小巧灵活

由于MinGW和MSYS更新太慢，不支持64位系统等原因，于是出现了相应的替代者

**d)** [MinGW-W64](http://mingw-w64.org/) 是MinGW的替代者，在MinGW只支持32位编译的基础上，又支持了64位。同时更新更快，对gcc较新版本支持更好。支持32位/64位系统应用的交叉编译(如在32位系统上编译64位的应用)

**e)** [MSYS2](https://www.msys2.org/)是MSYS的替代方案，同时支持了Cygwin(新版)，又提供一个包管理器pacman(来自Arch Linux)来管理需要的软件。支持MinGW的32位和64位，同时支持clang(原mac平台的编译器)

**小结**: MinGW-W64是gcc编译工具链在windows系统的移植版本；MSYS2是windows下的类unix命令行环境



### 2. 安装MSYS2与MinGW-W64

可以在[MSYS2](https://www.msys2.org/)首页直接下载`msys2-x86_64-20xxxxxx.exe`安装,也可以直接用[压缩包安装MSYS2](https://www.msys2.org/wiki/MSYS2-installation/)

[msys2分发库](http://repo.msys2.org/distrib/)下有可以选的安装文件

![msy2-distrib-repo](img/msy2-distrib-repo.png)

64位系统选`msys2-x86_64-latest.tar.xz`,解压后有一个msys64文件夹,可以将其放到d盘根目录

第一次启动时可以运行msys64下的msys2_shell.cmd脚本，会有一个初始化的过程

脚本默认以 **MSYS**的Shell环境 和 mintty终端启动 msys2。



msys2中有5个子系统,对应pacman包管理器中的5个库







