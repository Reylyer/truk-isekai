file = mainglfw
ext = cpp

# change this to your path
CXX64COMPILERPATH = S:\Program\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin



CXX64FLAGS = -lfreeglut_static -lglu32 -lopengl32 -lwinmm -lgdi32

# 
create_dir:
	@if not exist bin mkdir bin
	@if not exist obj mkdir obj



all: compile_all compile_main link
	$(CXX64COMPILERPATH)\g++.exe -c src\main.cpp -o obj\main.obj -I'include' -std=c++17
	$(CXX64COMPILERPATH)\g++.exe -v -Wall obj\main.obj -o  bin\main.exe -L'lib' $(CXX64FLAGS)
	.\bin\main.exe

