:loop
makedata.exe
test.exe
checker.exe
fc sort.res sort.txt 
if errorlevel 1 pause
goto loop