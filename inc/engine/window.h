#pragma once
#include<mytypes.h>
#include<SDL.h>
#include<stdio.h>

class Window
{
	public:
		Window(const u16 fwidth,const u16 fheight,const char* ftitle);
		~Window(void);

		bool init(void);
		void free(void);
		SDL_Window *window;

	private:
		u16 width,height;
		const char *title;
};
