@echo off
echo compiling using g++ because cl sucks.
@REM note: sdl2.dll is added to the path env so please add it manually.
@REM if build is not made create build dir
mkdir build
pushd build
@REM vcvars32.bat // use this once..
@REM cl /Fea.exe ../sandbox.cpp ../src/engine.cpp ../src/log.cpp /Wall /EHsc /I ../inc/sdl  /I ../inc/engine /link ../lib/SDL2main.lib ../lib/SDL2.lib
echo compiling and linking files
g++ -c ../src/engine.cpp ../src/window.cpp -I ../inc/engine -I ../inc/SDL
echo creating binary
@REM note: sdl works file with the -l in -lSDL2main and the sdl2 one... include -lib in -lSDL2main which makes it -libSDL2main.
g++ ../build/engine.o ../build/window.o -o a.exe -L ../lib -lmingw32 -lSDL2main -lSDL2
popd
