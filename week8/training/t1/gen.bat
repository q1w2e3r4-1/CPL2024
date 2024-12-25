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
gen.exe > data/%1.in
echo Test case %1.in generated.

std.exe < data/%1.in > data/%1.out
echo Output file %1.out generated.
goto :eof