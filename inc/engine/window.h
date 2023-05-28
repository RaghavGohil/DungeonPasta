#ifndef WINDOW
#define WINDOW
#include<mytype.h>
class Window
{
	public:
		Window(u16,u16,const char*);
		~Window();
		bool init();
		void shutdown();
		void checkEvent(SDL_Event*);
		SDL_Window *window;
	private:
		u16 width,height;
		const char *title;
};

#endif
