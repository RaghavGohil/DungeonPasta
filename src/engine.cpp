#include<SDL.h>
#include<window.h>
#include<renderer.h>
#include<texture.h>
#include<stdio.h>

//Screen dimension constants
#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 480

SDL_Texture *gTexture = nullptr;

int main(int argc,char *args[])
{
	Window *gWindow = new Window(SCREEN_WIDTH,SCREEN_HEIGHT,"Game");
	Renderer *gRenderer = new Renderer();
	Texture *gTexture = new Texture(100,100,"../img/monke.png");
	if(!gWindow->init()){ return -1; }
	if(!gRenderer->init(gWindow->window,-1)) { return -1; }
	if(!gTexture->init(gRenderer->renderer)) { return -1; }
	SDL_Event e;
	bool quit = false;
	while(!quit)
	{
		while(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
			{
				quit = true;
				gWindow->shutdown();	
			}	
			
		}
		SDL_RenderClear(gRenderer->renderer);
		gTexture->render(gRenderer->renderer,100,100);
		SDL_RenderPresent(gRenderer->renderer);
	}
	gTexture->free();
	gRenderer->shutdown();
	gWindow->shutdown();
	delete gTexture;
	delete gRenderer;
	delete gWindow;
	return 0;

}
