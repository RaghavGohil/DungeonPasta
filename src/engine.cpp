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
	
	Entity *entity = new Entity(gRenderer->getRenderer(),"../img/player/player_front.png");

	SDL_Event e;
	bool quit = false;

	while(!quit)
	{
		while(SDL_PollEvent(&e))
		{
			SDL_RenderClear(gRenderer->getRenderer());
			entity->texture->render(gRenderer->getRenderer(),0,0,0,0,5*5,10*5);
			SDL_RenderPresent(gRenderer->getRenderer());
			
			switch(e.type)
			{
				case SDL_QUIT:
					quit = true;
					gWindow->free();	
			}	
		}
	}

	entity->free();
	gRenderer->free();
	gWindow->free();
	delete entity;
	delete gRenderer;
	delete gWindow;
	return 0;

}
