@echo off
set /p __dir=请输入目录：
set /p __file=请输入要编译的文件的文件名（不带后缀名）：
g++.exe "%__dir%"\\"%__file%.cpp" -o "%__dir%"\\"%__file%.exe" -O2 -std=c++14 -lm -I"E:\MinGW\include" -I"E:\MinGW\mingw32\include" -I"E:\MinGW\lib\gcc\mingw32\9.2.0\include" -I"E:\MinGW\lib\gcc\mingw32\9.2.0\include\c++" -I"E:\MinGW\lib" -L"E:\MinGW\mingw32\lib" -static-libgcc