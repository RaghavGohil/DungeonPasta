#include<renderer.h>

Renderer::Renderer()
{
	//
}
Renderer::~Renderer()
{
	Renderer::shutdown();	
}

bool Renderer::init(SDL_Window *window,i8 driver)
{
	//Always on accelerated boiss
	this->renderer = SDL_CreateRenderer(window,driver,SDL_RENDERER_ACCELERATED);
	if(renderer == nullptr)
	{
		printf("Failed to initialize renderer. ");
		return false;
	}
	else
	{
		// set the renderer color so that we know that the renderer is set up
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 			

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


void Renderer::shutdown()
{
	SDL_DestroyRenderer(this->renderer);
	renderer = nullptr;
	IMG_Quit();
}
