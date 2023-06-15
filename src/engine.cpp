#include<SDL.h>
#include<window.h>
#include<renderer.h>
#include<texture.h>
#include<entity.h>
#include<stdio.h>

//Screen dimension constants
#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 480

SDL_Texture *gTexture = nullptr;

int main(int argc,char *args[])
{
	Window *gWindow = new Window(SCREEN_WIDTH,SCREEN_HEIGHT,"RoboLove");
	Renderer *gRenderer = new Renderer();

	if(!gWindow->init()){ return -1; }
	if(!gRenderer->init(gWindow->window,-1)) { return -1; }
	
	Entity *et = new Entity(gRenderer->renderer,"../img/player/player_front.png");

	SDL_Event e;
	bool quit = false;

	while(!quit)
	{
		while(SDL_PollEvent(&e))
		{
			SDL_RenderClear(gRenderer->renderer);
			et->texture->render(gRenderer->renderer,0,0,0,0,5*5,10*5);
			SDL_RenderPresent(gRenderer->renderer);
			
			switch(e.type)
			{
				case SDL_QUIT:
					quit = true;
					gWindow->free();	
			}	
		}
	}

	et->free();
	gRenderer->free();
	gWindow->free();
	delete et;
	delete gRenderer;
	delete gWindow;
	return 0;

}
