#include<SDL.h>
#include<stdio.h>
#include<windows.h>
#include<window.h>

//Screen dimension constants
#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 480

bool loadMedia();

SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load splash image
    gHelloWorld = SDL_LoadBMP( "../img/engine/logo.bmp" );
    if( gHelloWorld == NULL )
    {
	    printf("Unable to load the image.");
        success = false;
    }

    return success;
}

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{

	Window *gWindow = new Window(SCREEN_WIDTH,SCREEN_HEIGHT,"Torch");
	if(gWindow->init())	
	{
		if(!loadMedia())
		{
			printf("Unable to load media.");
		}
		else
		{
			SDL_BlitSurface(gHelloWorld,NULL,gScreenSurface,NULL);
			SDL_UpdateWindowSurface(gWindow->window);
			SDL_Event e;
			gWindow->checkEvent(&e);
		}
	}

	delete gWindow;	
	//Deallocate surface
    	SDL_FreeSurface( gHelloWorld );
    	gHelloWorld = NULL;
	return 0;

}
