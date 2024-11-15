:again
gcc gen.c -o gen.exe
.\gen.exe > input.txt
.\std.exe < input.txt > biaoda_output.txt
.\test.exe < input.txt > test_output.txt
fc biaoda_output.txt test_output.txt
if not errorlevel 1 goto again
pause
