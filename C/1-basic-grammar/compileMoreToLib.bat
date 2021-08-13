@echo off

echo ...
cd /d %~pd0
set _NotNeedNewCmd_=1
set srcCharset=utf-8
@rem set srcCharset=gbk
call "..\0-prepare\vcdev_x86.bat" %srcCharset%>nul
title 编译【多个】源文件==^>静态lib库
set srcDir=src
set tgtDir=target
set libDir=lib
if not exist %tgtDir% (
    mkdir %tgtDir%
)
set srcPreNameSave=%tgtDir%\.srcPreName
set srcCFile=%tgtDir%\.c-sources
set libObjects=%tgtDir%\.lib-objects
set cMaxIndex=10
set libMaxIndex=20

SETLOCAL ENABLEDELAYEDEXPANSION
set index=1
set num=0
type nul>%srcCFile%
echo ------- 准备进行【多文件】编译 -------
echo.
set recentSrc=
echo ------- 搜索【%srcDir%】目录下的C源文件： -------
for /f "tokens=*" %%i in ('dir /o-d /b %srcDir%\*.c') do (
    if /i !index! GTR %cMaxIndex% (
        goto :searchlib
    )
    if !index! == 1 (
        set recentSrc=%%i
    )
    echo %srcDir%\%%i>>%srcCFile%
    echo  [!index!]: %%i
    set /A index += 1
)
:searchlib
echo ------- 搜索【%libDir%】目录下的lib库文件： -------
for /f "tokens=*" %%i in ('dir /o-d /b %libDir%\*.lib') do (
    if /i !index! GTR %libMaxIndex% (
        goto :endSearch
    )
    echo %libDir%\%%i>>%srcCFile%
    echo  [!index!]: %%i
    set /A index += 1
)
if "%index%" == "1" (
    echo 未发现C源文件/lib库文件,按任意键退出！
    goto :end
)
echo.
:endSearch

@rem :: 是否只编译与"最后编辑文件"有相同前缀(xx_xx_)的c源文件 
@rem if not "lastSamePrefix" == "%~1" (
@rem     goto :chooseSrc
@rem )
@rem set specCnt=0
@rem set charIdx=0
@rem for /l %%i in (0,1,20) do (
@rem     set ch=!recentSrc:~%%i,1!
@rem     if "!ch!" == "" (
@rem         goto :endloop3
@rem     )
@rem     set /a charIdx+=1
@rem     if "!ch!" == "_" (
@rem         set /a specCnt+=1
@rem         if "!specCnt!" == "2" (
@rem             goto :endloop3
@rem         )
@rem     )
@rem )
@rem :endloop3
@rem if not "!specCnt!" == "2" (
@rem     goto :chooseSrc
@rem )
@rem set srcPrefix=!recentSrc:~0,%charIdx%!
@rem 
@rem echo 你选择前缀为:%srcPrefix%的源文件
@rem type nul>%srcCFile%
@rem for /f "tokens=*" %%i in ('dir /o-d /b %srcDir%\%srcPrefix%*.c  %srcDir%\*.lib') do (
@rem     echo %srcDir%\%%i>>%srcCFile% 
@rem )
@rem goto :showChoose

:chooseSrc
if not "%index%" == "1" (
echo ==^>请输入待编译文件编号^(空格分隔多个编号,不输入默认选全部^):
set /p chooseIdxes=
)
if "%chooseIdxes%" == "" (
    set chooseIdxes=ALL
    echo 默认选全部!
    goto :showChoose
)
type nul>%srcCFile%
call:matchChoose %chooseIdxes%
goto :showChoose

:matchChoose
set "chooseIdx=%~1"
if "%chooseIdx%" == "" (
    exit /b 0
)
set index=1
for /f "tokens=*" %%i in ('dir /o-d /b %srcDir%\*.c') do (
    if /i !index! GTR %cMaxIndex% (
        goto :searchMatchlib
    )
    if "!index!" == "!chooseIdx!" (
        echo %srcDir%\%%i>>%srcCFile% 
        goto:endMatchloop
    )
    set /A index += 1
)
:searchMatchlib
for /f "tokens=*" %%i in ('dir /o-d /b %libDir%\*.lib') do (
    if "!index!" == "!chooseIdx!" (
        echo %libDir%\%%i>>%srcCFile% 
        goto:endMatchloop
    )
    set /A index += 1
)
:endMatchloop
shift /1
goto:matchChoose


:showChoose
set existSrc=
type nul>%libObjects%
for /f "tokens=*" %%i in (%srcCFile%) do (
    echo %tgtDir%\%%~ni.obj>>%libObjects%
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


echo -------------- 开始编译: --------------
::参数自定义编译宏
set DEFINE_OPT=/D"C_R_MODE=2"

::@rem 默认情况下，Visual Studio 检测字节顺序标记以确定源文件是否采用编码的 Unicode 格式 
::@rem 如果未找到字节顺序标记，则假定源文件使用当前用户代码页进行编码，除非您已使用 /utf-8 或 /source-charset 选项指定了代码页。  
::@rem /source-charset:%srcCharset% /execution-charset:%srcCharset%  
::@rem  warning C4819: The file contains a character that cannot be represented in the current code page ^(0^)  
::@rem C4819字符警告在设了/execution-charset:utf-8,且汉字数量为奇数，没法去掉，只好通过/wo4819只显示一次该告警
::禁用5045告警，已配置/Qspectre防止cpu预测执行 

set _CL_OPT=%DEFINE_OPT% /Wall  /wo4819  /wd5045 /Qspectre /source-charset:utf-8 /execution-charset:%srcCharset% /Fo"%tgtDir%\\" /I include @"%srcCFile%" /std:c11 /nologo /c
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

if not "%compileResult%" == "0" (
echo ======== 编译失败！！！ ========
goto :end
)


echo ==--------------------- 开始打包库文件 ---------------------==
echo 请输入打包后的库名： 
set /p libFileName=
set "libFileName=lib\%libFileName%.lib"
@rem lib.exe /def:"%libObjects%" /out:"%libFileName%" //这个是动态库的搞法
lib.exe @"%libObjects%" /out:"%libFileName%"
if "%ERRORLEVEL%" == "0" (
    echo 打包生成库文件:%libFileName%
    echo echo ==------------------ 打包完毕，输入cmd进入命令行，直接回车可退出！ ------------------==
) else (
    echo ======== 打包失败！！！ ========
)
:end
set /p doWhat=
if "%doWhat%" == "cmd" (
    set /p=""%libFileName%""<nul|clip
    cmd /k
)