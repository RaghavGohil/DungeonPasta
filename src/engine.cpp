#include<iostream>
#include <SDL.h>
#include <string.h>
#include <windows.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define TITLE "game"

//functions:
bool init();//initializes sdl and creates a window for us.
bool loadMedia();//creates a surface and loads an image on the surface.
SDL_Surface* loadImgSurface( std::string path );//creates a sdl surface and return a pointer to it.
void close();//closes the application after freeing the data.

//initialization:
//The window we'll be rendering to
SDL_Window* gWindow = NULL;
    
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

//Current displayed image
SDL_Surface* gCurrentSurface = NULL;

//entry point.
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hpInstance, LPSTR nCmdLine, int iCmdShow)
{   
    if(!init())
    {
        std::cout << "Failed to initialize!\n";
    }

    else
    {
        if(!loadMedia())
        {
            std::cout << "Unable to load media!\n";
        }

        else
        {

            //Apply the image stretched
			SDL_Rect stretch_rect;
			stretch_rect.x = 0;
			stretch_rect.y = 0;
			stretch_rect.w = SCREEN_WIDTH;
			stretch_rect.h = SCREEN_HEIGHT;
            //sourcerect
            // SDL_Rect src_rect;
            // src_rect.x = 0;
			// src_rect.y = 0;
			// src_rect.w = 500;
			// src_rect.h = 300;
			// SDL_BlitScaled( gHelloWorld,&src_rect, gScreenSurface, &stretch_rect );
            // SDL_BlitSurface(gHelloWorld,NULL,gScreenSurface,NULL);
            SDL_UpdateWindowSurface( gWindow );
            
            SDL_Event e; 
            bool quit = false;
            
            while( quit == false )
            {
                while( SDL_PollEvent( &e ) )
                { 
                    if( e.type == SDL_QUIT )
                        quit = true;
                    if( e.type == SDL_KEYDOWN )
                        SDL_Log("User pressed a key.\n");//use the log function as by default in a window application it doesn't print out to the console. 
                }
            }
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
    gHelloWorld = loadImgSurface("C://Users/Mira.H.Gohil/Desktop/monke.bmp");
    if( gHelloWorld == NULL )
    {
        std::cout << "Couldn't load media. " << SDL_GetError() << std::endl;
        success = false;
    }

    return success;
}

SDL_Surface* loadImgSurface(std::string path)
{
    //load the surface at path.
    SDL_Surface* surface = SDL_LoadBMP(path.c_str());

    if(surface == NULL)
    {
        std::cout<<"Unable to load surface at: "<<path.c_str()<<std::endl;
        return surface;// return null if surface is null.
    }

    else
    {
        SDL_Surface* optimized_surface = SDL_ConvertSurface(surface,gScreenSurface->format,0);
        if(optimized_surface == NULL)
        {
            std::cout<<"Unable to load optimized surface at: "<<path.c_str()<<std::endl;
            return surface;//return the unoptimized surface.
        }
        else
        {
            SDL_FreeSurface(surface);
            return optimized_surface;
        }
    }

}

void close()
{
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    SDL_Quit();
}