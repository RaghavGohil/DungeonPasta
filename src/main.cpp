#include<iostream>
#include <SDL.h>
#include <string.h>
#include <windows.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define TITLE "game"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hpInstance, LPSTR nCmdLine, int iCmdShow)
{   

    //create window and surface.
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;

    //init sdl(without initializing you cannot call the sdl functions).
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL could not be initialized. " ;//<< SDL_GetError() << std::endl;
    }

    else
    {
        //Create window
        window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        
        if( window == NULL )
        {
            std::cout << "Window could not be created. " << SDL_GetError() << std::endl;
        }
    }

    return 0;
}