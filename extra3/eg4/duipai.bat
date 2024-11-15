:again
.\gen.exe
.\test.exe < 1.in > 1.out
.\checker.exe
if not errorlevel 1 goto again
pause
