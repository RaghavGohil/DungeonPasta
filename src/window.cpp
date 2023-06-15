#include<window.h>

Window::Window(const u16 fwidth,const u16 fheight,const char *ftitle)
{
	this->width = fwidth;
	this->height = fheight;
	this->title = ftitle;
}

Window::~Window(void)
{
	Window::free();	
}

bool Window::init(void)
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

void Window::free(void)
{
	Window::title = nullptr;
	SDL_DestroyWindow(Window::window);
	SDL_Quit();	
}
