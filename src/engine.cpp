#include<SDL.h>
#include<window.h>
#include<renderer.h>
#include<stdio.h>

//Screen dimension constants
#define SCREEN_WIDTH 512
#define SCREEN_HEIGHT 480

SDL_Texture *gTexture = nullptr;

void close(Window *window,Renderer *renderer)
{
	renderer->shutdown();
	window->shutdown();
	delete renderer;
	delete window;
}

int main(int argc,char *args[])
{
	Window *gWindow = new Window(SCREEN_WIDTH,SCREEN_HEIGHT,"Torch");
	Renderer *gRenderer = new Renderer();

	if(gWindow->init())	
	{
		if(gRenderer->init(gWindow->window,-1))
		{
			gTexture = gRenderer->createTexture("../img/torch.png");
		}
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
               		SDL_RenderCopy(gRenderer->renderer,gTexture,NULL,NULL);
                	SDL_RenderPresent(gRenderer->renderer);
		}

	}

	close(gWindow,gRenderer);	
	SDL_DestroyTexture(gTexture);
	return 0;

}
