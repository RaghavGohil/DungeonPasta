#pragma once
#include<SDL.h>
#include<stdio.h>
#include<SDL_image.h>
#include<mytypes.h>

class Renderer
{
	public:
		Renderer(void);
		~Renderer(void);
		
		bool init(SDL_Window* fwindow,const i8 fdriver);

		//getters:
		SDL_Renderer* getRenderer(void);
			
		void free(void);
	private:
		SDL_Renderer *renderer;
};
