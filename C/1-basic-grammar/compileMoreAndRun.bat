@echo off

echo ...
cd /d %~pd0
set _NotNeedNewCmd_=1
set srcCharset=utf-8
@rem set srcCharset=gbk
call "..\0-prepare\vcdev_x86.bat" %srcCharset%>nul
title 编译【多个】源文件
set srcDir=src
set tgtDir=target
if not exist %tgtDir% (
    mkdir %tgtDir%
)
set srcPreNameSave=%tgtDir%\.srcPreName
set srcCFile=%tgtDir%\.c-sources

SETLOCAL ENABLEDELAYEDEXPANSION
set index=0
set num=0
type nul>%srcCFile%
echo ------- 准备进行【多文件】编译 -------
echo.
set recentSrc=
echo ------- 搜索【%srcDir%】目录下的C源文件： -------
for /f "tokens=*" %%i in ('dir /o-d /b %srcDir%\*.c  %srcDir%\*.lib') do (
    set /A index += 1
    if /i !index! GTR 20 (
        goto :endSearch
    )
    if !index! == 1 (
        set recentSrc=%%i
    )
    echo %srcDir%\%%i>>%srcCFile%
    echo  [!index!]: %%i
)
if "%index%" == "0" (
    echo 未发现C源文件,按任意键退出！
    goto :end
)
echo.
:endSearch

:: 是否只编译与"最后编辑文件"有相同前缀(xx_xx_)的c源文件 
if not "lastSamePrefix" == "%~1" (
    goto :chooseSrc
)
set specCnt=0
set charIdx=0
for /l %%i in (0,1,20) do (
    set ch=!recentSrc:~%%i,1!
    if "!ch!" == "" (
        goto :endloop3
    )
    set /a charIdx+=1
    if "!ch!" == "_" (
        set /a specCnt+=1
        if "!specCnt!" == "2" (
            goto :endloop3
        )
    )
)
:endloop3
if not "!specCnt!" == "2" (
    goto :chooseSrc
)
set srcPrefix=!recentSrc:~0,%charIdx%!

echo 你选择前缀为:%srcPrefix%的源文件
type nul>%srcCFile%
for /f "tokens=*" %%i in ('dir /o-d /b %srcDir%\%srcPrefix%*.c  %srcDir%\*.lib') do (
    echo %srcDir%\%%i>>%srcCFile% 
)
goto :showChoose


:chooseSrc
if not "%index%" == "1" (
echo ==^>请选择并输入源文件编号^(空格分隔多个编号,不输入默认选全部^):
set /p chooseIdxes=
)
if "%chooseIdxes%" == "" (
    set chooseIdxes=ALL
    echo 默认选全部!
    goto :showChoose
)
type nul>%srcCFile%
call:matchChoose %chooseIdxes%


:matchChoose
set "chooseIdx=%~1"
if "%chooseIdx%" == "" (
    goto :showChoose
)
set index=0
for /f "tokens=*" %%i in ('dir /o-d /b %srcDir%\*.c %srcDir%\*.lib') do (
    set /A index += 1
    if "!index!" == "!chooseIdx!" (
        echo %srcDir%\%%i>>%srcCFile% 
        goto:endloop1;
    )
)
:endloop1
shift /1
goto:matchChoose


:showChoose
set existSrc=
for /f "tokens=*" %%i in (%srcCFile%) do (
    set "existSrc=%%~ni"
)
if "%existSrc%" == "" (
    echo 选择有误！
    goto :chooseSrc
)
echo ------- 准备完毕,即将编译如下文件: -------
type %srcCFile%
ping -n 2 127.0.1>nul
echo.
ENDLOCAL


for /f "tokens=*" %%i in (%srcCFile%) do (
    set "exeFileName=%tgtDir%\%%~ni.exe"
    goto:endloop2;
)
:endloop2
echo -------------- 开始编译: --------------
::@rem 默认情况下，Visual Studio 检测字节顺序标记以确定源文件是否采用编码的 Unicode 格式 
::@rem 如果未找到字节顺序标记，则假定源文件使用当前用户代码页进行编码，除非您已使用 /utf-8 或 /source-charset 选项指定了代码页。  
::@rem /source-charset:%srcCharset% /execution-charset:%srcCharset%  
::@rem  warning C4819: The file contains a character that cannot be represented in the current code page ^(0^)  
::@rem C4819字符警告在设了/execution-charset:utf-8,且汉字数量为奇数，没法去掉，只好通过/wd4819禁用该告警   
::禁用5045告警，已配置/Qspectre防止cpu预测执行 

set _CL_OPT=/Wall  /wd4819  /wd5045 /Qspectre /source-charset:utf-8 /execution-charset:%srcCharset% /Fo"%tgtDir%\\" /Fe"%exeFileName%" /I include @"%srcCFile%" /std:c11 /nologo /link /SUBSYSTEM:CONSOLE
echo 【环境变量INCLUDE】==^> %INCLUDE%
echo.
echo 【环境变量LIB】==^> %LIB%
echo.
echo 【编译参数】==^> %_CL_OPT%
echo.

cl.exe %_CL_OPT%
set compileResult=%ERRORLEVEL%
echo --------------------- 编译结束 ---------------------
echo.

if "%compileResult%" == "0" (
echo ==--------------------- 开始执行:"%exeFileName%" ---------------------==
call "%exeFileName%"
echo ==--------------------- 执行完毕，按任意键退出！ ---------------------==
) else (
echo ======== 编译失败！！！ ========
)
:end
pause>nul