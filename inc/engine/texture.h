#ifndef TEXTURE
#define TEXTURE
#include<SDL.h>
#include<mytype.h>
#include<SDL_image.h>
#include<stdio.h>

class Texture
{
	public:
		Texture(i16,i16,const char*);
		~Texture();

		bool init(SDL_Renderer*);
		void render(SDL_Renderer*,i16,i16) const;
		void free();

		const char* path;
		SDL_Texture *texture;

	private:
		i16 width,height;
};

#endif
