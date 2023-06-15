#pragma once
#include<SDL.h>
#include<mytypes.h>
#include<SDL_image.h>
#include<stdio.h>

class Texture
{
	public:
		Texture(const char* fpath);
		~Texture(void);

		bool init(SDL_Renderer* frenderer);
		void render(SDL_Renderer* frenderer,i16 fsrc_x,i16 fsrc_y,i16 fdest_x,i16 fdest_y,u16 fw,u16 fh);
		void free(void);
		const char *path;
		SDL_Texture *texture;
};
