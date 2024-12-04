@echo off
setlocal enabledelayedexpansion

:: check
:: 检查gen.cpp是否存在
if not exist gen.cpp (
    echo Error: gen.cpp does not exist.
    exit /b
)

g++ gen.cpp -o gen.exe
if errorlevel 1 (
    echo Error: Compilation failed.
    exit /b
)

@REM :: 检查std.c是否存在
@REM if not exist std.c (
@REM     echo Error: std.c does not exist.
@REM     exit /b
@REM )

@REM gcc std.c -o std.exe
@REM if errorlevel 1 (
@REM     echo Error: Compilation failed.
@REM     exit /b
@REM )

if not exist data mkdir data

if "%~1"=="" (
    echo Usage: %0 x y
    exit /b
)
if "%~2"=="" (
    echo Usage: %0 x y
    exit /b
)

set /a start=%1
set /a end=%2

for /l %%i in (%start%, 1, %end%) do (
    set "filename=%%i"
    call :generate "%%i"
)

echo All test cases generated successfully.
goto :eof

:generate
@REM gen.exe > data/%1.in
@REM echo Test case %1.in generated.

std.exe < data/%1.in > data/%1.out
echo Output file %1.out generated.
goto :eof