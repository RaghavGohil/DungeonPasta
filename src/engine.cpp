#include<SDL.h>
#include<iostream>
#include<windows.h>

//Screen dimension constants
static const int SCREEN_WIDTH = 640;
static const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;



bool init()
{
	bool success = false;
	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		std::cout << SDL_GetError();
		return success;
	}	
	else
	{
		gWindow = SDL_CreateWindow("Solus",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
		if(gWindow==NULL)
		{
			std::cout << SDL_GetError();
			return success;
		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return true;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load splash image
    gHelloWorld = SDL_LoadBMP( "../img/engine/logo.bmp" );
    if( gHelloWorld == NULL )
    {
	    std::cout << "Unable to load image" << std::endl;
        success = false;
    }

    return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{

	if(!init())
	{
		std::cout << "Failed to create window!!!";
	}
	else
	{
		if(!loadMedia())
		{
			std::cout << "Failed to load media!!!";
		}
		else
		{
			SDL_BlitSurface(gHelloWorld,NULL,gScreenSurface,NULL);
			SDL_UpdateWindowSurface(gWindow);
			SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
		}
	}
		
	close();
	return 0;
}
