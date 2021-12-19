@ECHO OFF

cd semest1/algem

:1
set /p pset=""
echo %pset% >> %date%.txt
goto 1