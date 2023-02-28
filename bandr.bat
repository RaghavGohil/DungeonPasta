build.bat
pushd build
cl /Fea.exe ../test.cpp /Wall /EHsc /I ../inc/sdl /link ../lib/SDL2main.lib ../lib/SDL2.lib
a.exe
popd