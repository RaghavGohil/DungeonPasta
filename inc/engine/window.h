#ifndef WINDOW
#define WINDOW
#include<mytype.h>
#include<SDL.h>
#include<stdio.h>

class Window
{
	public:
		Window(u16,u16,const char*);
		~Window();

		bool init();
		void shutdown();
		SDL_Window *window;

	private:
		u16 width,height;
		const char *title;
};

#endif
