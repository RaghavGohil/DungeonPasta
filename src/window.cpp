#include<window.h>

Window::Window(u16 width,u16 height,const char *title)
{
	Window::width = width;
	Window::height = height;
	Window::title = title;
}

Window::~Window()
{
	Window::shutdown();	
}

bool Window::init()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Failed to initialize SDL.");
		return false;
	}
	else
	{
		Window::window = SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,Window::width,Window::height,SDL_WINDOW_SHOWN);
		if(window==nullptr)
		{
			printf("Failed to create window.");
			return false;
		}
	}
	return true;	
}

void Window::shutdown()
{
	Window::title = nullptr;
	SDL_DestroyWindow(Window::window);
	SDL_Quit();	
}
