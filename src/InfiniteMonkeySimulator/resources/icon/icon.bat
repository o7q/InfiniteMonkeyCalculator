@echo off
color 3
windres "icon.rc" -O coff -o "icon.res"
echo.
pause