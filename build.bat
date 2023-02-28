@echo off
echo compiling using g++ because cl sucks.
@REM note: sdl2.dll is added to the path env so please add it manually.
@REM if build is not made create build dir
mkdir build
pushd build
@REM vcvars32.bat // use this once..
@REM cl /Fea.exe ../sandbox.cpp ../src/engine.cpp ../src/log.cpp /Wall /EHsc /I ../inc/sdl  /I ../inc/engine /link ../lib/SDL2main.lib ../lib/SDL2.lib
g++ -c ../src/engine.cpp -I ../inc/engine
g++ -c ../src/log.cpp -I ../inc/engine
g++ -c ../sandbox.cpp -I ../inc/engine
g++ engine.o log.o sandbox.o -Wall -o a.exe
popd