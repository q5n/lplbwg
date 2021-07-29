@echo off

echo ...
cd /d %~pd0
set _NotNeedNewCmd_=1
set srcCharset=utf-8
@rem set srcCharset=gbk
call "..\0-prepare\vcdev_x86.bat" %srcCharset%>nul
title 编译单个C文件
set srcPreNameSave=target\.srcPreName
SETLOCAL ENABLEDELAYEDEXPANSION
echo ------- 准备进行单文件编译 -------
echo.
set index=0
echo -------  搜索【src】目录下的C源文件： -------
for /f "tokens=*" %%i in ('dir /o-d /b src\*.c') do (
    set /A index += 1
    if /i !index! GTR 10 (
        goto :chooseSrc
    )
    echo  [!index!]: %%i
)
if "%index%" == "0" (
    echo 未发现C源文件,按任意键退出！
    goto :end
)
echo.

:chooseSrc
if "last" == "%~1" (
    set index=1
)
if not "%index%" == "1" (
echo ==^>请输入选择的源文件编号^(不输入默认选1^):
set /p chooseIdx=
)
if "%chooseIdx%" == "" (
    set chooseIdx=1
    echo 默认选[1]
)

set index=0
for /f "tokens=*" %%i in ('dir /o-d /b src\*.c') do (
    set /A index += 1
    if "!index!" == "!chooseIdx!" (
        set srcFile=%%i
        break;
    )
)
if "%srcFile%" == "" (
    echo 选择有误！
    echo.
    set chooseIdx=
    goto :chooseSrc
)
set "srcPreName=%srcFile:~0,-2%"
if not exist target (
    mkdir target
)
echo %srcPreName%>%srcPreNameSave%
title 编译==^>"src\%srcFile%"
echo ------- 准备完毕,即将编译:"%srcFile%" -------
echo.
ENDLOCAL

for /f "tokens=*" %%i in (%srcPreNameSave%) do (
    set srcPreName=%%i
    set srcFile=%%i.c
)
echo -------------- 开始编译:[%srcFile%] --------------

::@rem "ping -n 2 127.0.1>nul"  
::@rem 默认情况下，Visual Studio 检测字节顺序标记以确定源文件是否采用编码的 Unicode 格式 
::@rem 如果未找到字节顺序标记，则假定源文件使用当前用户代码页进行编码，除非您已使用 /utf-8 或 /source-charset 选项指定了代码页。  
::@rem /source-charset:%srcCharset% /execution-charset:%srcCharset%  
::@rem  warning C4819: The file contains a character that cannot be represented in the current code page ^(0^)  
::@rem C4819字符警告在设了/execution-charset:utf-8,且汉字数量为奇数，没法去掉，只好通过/wd4819禁用该告警   
::禁用5045告警，已配置/Qspectre防止cpu预测执行 
set _CL_OPT=/Wall  /wd4819  /wd5045 /Qspectre /source-charset:utf-8 /execution-charset:%srcCharset% "src\%srcFile%" /I include /Fo"target\%srcPreName%" /Fe"target\%srcPreName%" /std:c11 /nologo /link /SUBSYSTEM:CONSOLE
echo 【环境变量INCLUDE】==^> %INCLUDE%
echo.
echo 【环境变量LIB】==^> %LIB%
echo.
echo 【编译参数】==^> %_CL_OPT%
echo.

cl.exe %_CL_OPT%
echo --------------------- 编译结束 ---------------------
echo.

if "%ERRORLEVEL%" == "0" (
echo ==--------------------- 开始执行:"target\%srcPreName%.exe" ---------------------==
@rem ping -n 2 127.0.1>nul
"target\%srcPreName%"
echo ==--------------------- 执行完毕，按任意键退出！ ---------------------==
) else (
echo ======== 编译失败！！！ ========
)
:end
pause>nul