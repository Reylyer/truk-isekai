$CXX64COMPILERPATH = "S:\Program\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin" + ";"
$Env:Path = (Get-Item .).FullName + "\dlls;" + $Env:Path
$Env:Path = $CXX64COMPILERPATH + $Env:Path

mkdir -Force bin
mkdir -Force src
mkdir -Force obj

$files_botak = Get-ChildItem -Path .\src -Name | ForEach-Object {$_.Split(".")[0]}


# compile each cpp files
foreach ($file in $files_botak) {
    Invoke-Expression "g++ -v -Wall -c .\src\$file.cpp -I'include' -std=c++17 -o .\obj\$file.o"
}

# linkinngggg
g++ -v -Wall .\obj\*.o -o .\bin\main.exe -L'lib' -lfreeglut_static -lglu32 -lopengl32 -lwinmm -lgdi32
.\bin\main.exe 
# run

# g++ -v -Wall -c -o bin\main.exe src\*.cpp -I'include' -std=c++17 -L'lib' -lfreeglut_static -lglu32 -lopengl32 -lwinmm -lgdi32
# .\bin\main.exe

# g++ -v -Wall -c src\pohon.cpp -o obj\pohon.obj -I'include' -std=c++17
# g++ -v -Wall obj\pohon.obj -o  bin\pohon.exe -L'lib' -lfreeglut_static -lglu32 -lglew32s -lopengl32 -lwinmm -lgdi32
# .\bin\pohon.exe