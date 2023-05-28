#ifndef RENDERER
#define RENDERER
#include<mytype.h>
#include<SDL.h>
class Renderer
{
	public:
		Renderer();
		~Renderer();
		bool init(SDL_Window*,i8);
		void shutdown();
		
		SDL_Renderer *renderer;

		void renderTexture();
};

#endif 
