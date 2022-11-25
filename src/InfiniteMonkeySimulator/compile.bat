@echo off
color 3
g++ *.cpp "resources\icon\icon.res" -Wall -O2 -o "InfiniteMonkeySimulator.exe" -static-libstdc++ -static-libgcc
echo.
pause