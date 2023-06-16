#include<renderer.h>

Renderer::Renderer(void)
{
	//
}
Renderer::~Renderer(void)
{
	Renderer::free();	
}

bool Renderer::init(SDL_Window *fwindow,const i8 fdriver)
{
	//Always on accelerated boiss
	this->renderer = SDL_CreateRenderer(fwindow,fdriver,SDL_RENDERER_ACCELERATED);
	if(renderer == nullptr)
	{
		printf("Failed to initialize renderer. ");
		return false;
	}
	else
	{
		// set the renderer color so that we know that the renderer is set up
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 			

		// initialize the image loader

		i8 imgFlags = IMG_INIT_PNG; // for sprite rendering it's efficient to use png
		
		if(!(IMG_Init(imgFlags)&imgFlags)) // img init is a nasty function
		{
			// so if we fail to load		
			printf("Failed to initialize image library.");
			renderer = nullptr; // no use of the renderer
			return false;
		}
	}
	return true;
}

SDL_Renderer* Renderer::getRenderer(void)
{
	return this->renderer;
}

void Renderer::free(void)
{
	SDL_DestroyRenderer(this->renderer);
	renderer = nullptr;
	IMG_Quit();
}
