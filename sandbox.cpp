#include <iostream>
#include <string.h>
#include <windows.h>
#include <engine.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define TITLE "game"

// //entry point.
// int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hpInstance, LPSTR nCmdLine, int iCmdShow)
// {
//     engine::Engine e;
//     return 0;
// }

//entry point.
int main(int argc , char **argv)
{
    engine::Engine e;
    engine::Log::LogConsole("Hello world",1);
    return 0;
}