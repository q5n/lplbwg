@echo off
title vcdev_x86
@rem prompt [$P]$_$G
if "%1" == "utf-8" ( chcp 65001
)else if "%1" == "big5" ( chcp 950
)else if "%1" == "gb2312" ( chcp 936
)else if "%1" == "gbk" ( chcp 936
)else chcp 65001

@rem 当前编译平台采用架构
set HOST_ARCH=x86
@rem 编码后目标可执行文件支持架构
set TGT_ARCH=x86
@rem vc工具版本
set VCToolsVersion=14.29.30037
@rem vc工具安装目录
set "VCToolsInstallDir=D:\programs\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\%VCToolsVersion%\"
@rem 统一C运行时sdk路径
set "UniversalCRTSdkDir=C:\Program Files (x86)\Windows Kits\10\"
@rem 统一C运行时版本号
set UCRTVersion=10.0.20348.0

@rem 统一C运行时include头文件路径
set "_UcrtInclude=%UniversalCRTSdkDir%include\%UCRTVersion%\"
@rem 统一C运行时lib库文件路径
set "_UcrtLib=%UniversalCRTSdkDir%lib\%UCRTVersion%\"

@rem 在Path上加上vc工具可执行文件cl.exe等的路径
set "Path=%VCToolsInstallDir%bin\Host%HOST_ARCH%\%TGT_ARCH%;%Path%"
@rem 配置INCLUDE环境变量，方便#include预处理指令
set "INCLUDE=%VCToolsInstallDir%include;%_UcrtInclude%ucrt;%_UcrtInclude%shared;%_UcrtInclude%um;%_UcrtInclude%winrt"
@rem 配置LIB环境变量，方便链接
set "LIB=%VCToolsInstallDir%lib\%HOST_ARCH%;%_UcrtLib%ucrt\%HOST_ARCH%;%_UcrtLib%um\%HOST_ARCH%"


if "%_NotNeedNewCmd_%" == "" (
    cmd /k
)