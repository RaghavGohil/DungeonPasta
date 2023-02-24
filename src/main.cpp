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

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
    
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hpInstance, LPSTR nCmdLine, int iCmdShow)
{   

    if(!init())
    {

        std::cout << "Failed to initialize!" << std::endl;

    }

    else
    {

        if(!loadMedia())
        {

            std::cout << "Unable to load media!" << std::endl;

        }

        else
        {

            SDL_BlitSurface(gHelloWorld,NULL,gScreenSurface,NULL);
            SDL_UpdateWindowSurface( gWindow );
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; }} //our hack
        }

    }

    close();

    return 0;

}

bool init()
{
   
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not be initialized. " << SDL_GetError() << std::endl;
        success = false;
    }

    else
    {
        //Create window
        gWindow = SDL_CreateWindow( TITLE , SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            std::cout << "Window could not be initialized. " << SDL_GetError() << std::endl;
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;

}

bool loadMedia()
{

    bool success = true;

    //Load splash image
    gHelloWorld = SDL_LoadBMP( "C://Users/Mira.H.Gohil/Desktop/monke.bmp" );
    if( gHelloWorld == NULL )
    {
        std::cout << "Couldn't load media. " << SDL_GetError() << std::endl;
        success = false;
    }

    return success;

}

void close()
{

    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    SDL_Quit();

}