#include<iostream>
#include <SDL.h>
#include <string.h>
#include <windows.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define TITLE "game"

bool init();
bool loadMedia();
void close();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hpInstance, LPSTR nCmdLine, int iCmdShow)
{   

    //Create window and surface
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;

    //Init sdl(without initializing you cannot call the sdl functions)
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
    
        std::cout << "SDL could not be initialized. " << SDL_GetError() << std::endl;
    
    }

    else
    {
    
        //Create window
        window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        
        if( window == NULL )
        {
    
            std::cout << "Window could not be created. " << SDL_GetError() << std::endl;
    
        }

        else
        {
    
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            //Fill the surface white
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
            
            //Update the surface
            SDL_UpdateWindowSurface( window );

            //SDL_Delay(ms); can be used to create a delay of ms.

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
    
        }

        //Destroy window and free from the memory.
        SDL_DestroyWindow( window );

        //Quit SDL subsystems
        SDL_Quit();
    
    }

    return 0;

}

