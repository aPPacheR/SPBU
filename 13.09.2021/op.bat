@ECHO OFF

cd semest1/proga

:1
set /p pset=""
echo %pset% >> %date%.txt
goto 1
