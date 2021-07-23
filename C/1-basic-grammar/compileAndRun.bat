@echo off
cd /d %~pd0
set _NotNeedNewCmd_=1
set srcCharset="utf-8"
call "..\0-prepare\vcdev_x86.bat" %srcCharset% >nul
SETLOCAL ENABLEDELAYEDEXPANSION
set index=0
echo ------- 准备编译, 搜索【src】目录下的C源文件： -------
for /f "tokens=*" %%i in ('dir /o-d /b src\*.c') do (
    set /A index += 1
    echo  [!index!]: %%i
)
if "%index%" == "0" (
    echo 未发现C源文件,按任意键退出！
    goto :end
)
echo.

:chooseSrc
if not "%index%" == "1" (
echo ==^>请选择源文件编号^(默认选1^):
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
echo ------- 准备完毕,即将编译:"%srcFile%" -------
echo.

echo -------------- 开始编译:[%srcFile%] --------------
ping -n 2 127.0.1>nul
cl.exe /Wall  /source-charset:%srcCharset% "src\%srcFile%" /Fo"target\%srcPreName%" /Fe"target\%srcPreName%" /std:c11 /nologo /link /SUBSYSTEM:CONSOLE
echo --------------------- 编译结束 ---------------------
echo.

if "%ERRORLEVEL%" == "0" (
echo -------------- 开始执行:"target\%srcPreName%.exe" --------------
ping -n 2 127.0.1>nul
call "target\%srcPreName%"
echo --------------------- 执行完毕，按任意键退出！ ---------------------
) else (
echo ======== 编译失败！！！ ========
)
:end
pause>nul
