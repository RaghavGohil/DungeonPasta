@echo off
echo -lstdc++ options links the standard libraries.
echo -L stands for library search path.
pushd build
gcc ../src/main.cpp -lstdc++ -L ../inc/SDL2/lib/x86/SDL2.lib ../inc/SDL2/lib/x86/SDL2main.lib
popd