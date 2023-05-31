#ifndef RENDERER
#define RENDERER
#include<SDL.h>
#include<stdio.h>
#include<SDL_image.h>
#include<mytype.h>

class Renderer
{
	public:
		Renderer();
		~Renderer();
		
		bool init(SDL_Window*,i8);
		void shutdown();
		
		SDL_Renderer *renderer;
};
#endif 
