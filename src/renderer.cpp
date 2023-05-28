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
	Renderer::renderer = SDL_CreateRenderer(window,driver,SDL_RENDERER_ACCELERATED);
	if(renderer == nullptr)
	{
		SDL_Log("Failed to initialize renderer");
		return false;
	}
	else
	{
		// set the renderer color so that we know that the renderer is set up
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 			
	}
	return true;
}

void Renderer::shutdown()
{
	SDL_DestroyRenderer(Renderer::renderer);
	renderer = nullptr;
}
