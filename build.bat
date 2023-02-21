@echo off
echo compiling using cl.exe -- msvc 
@REM echo -lstdc++ options links the standard libraries.
@REM echo -L stands for library search path.
@REM echo -I searches and includes all the header files.
@REM echo -Wall gives all the warnings.
@REM g++ ../src/main.cpp -lstdc++ -Wall -lSDL2main -lSDL2 -I ../inc/SDL
pushd build
@REM vcvars32.bat // use this once..
cl /Fea.exe ../src/main.cpp /Wall /EHsc /I "../inc/SDL" /link ../lib/SDL2main.lib ../lib/SDL2.lib
popd