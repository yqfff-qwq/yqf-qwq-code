:loop
makedata.exe
rplexq.exe
baoli.exe
fc rplexq.out rplexq.ans
if errorlevel 1 pause
goto loop