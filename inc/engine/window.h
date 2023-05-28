#ifndef WINDOW
#define WINDOW
#include<mytype.h>
class Window
{
	public:
		Window(u16,u16,const char*);
		~Window();
		SDL_Window *window;
		bool init();
		void shutdown();
		void checkEvent(SDL_Event*);
	private:
		u16 width,height;
		const char *title;
};

#endif
