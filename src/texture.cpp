#include<texture.h>

Texture::Texture(i16 width,i16 height,const char* path)
{
	this->width = width;
	this->height = height;
	this->path = path;
}

Texture::~Texture()
{
	free();
}

bool Texture::init(SDL_Renderer *renderer)
{
	SDL_Surface *surface = IMG_Load(this->path); 
	if(surface == nullptr)
	{
		printf("Failed to load specified image at %s.",this->path); // todo: SDL_Log 
		return false;
	}
	else
	{
		this->texture = SDL_CreateTextureFromSurface(renderer,surface);
		if(texture == nullptr)
		{
			printf("Failed to load texture from surface from path %s.",this->path); // todo: SDL_Log 
			return false;
		}
		SDL_FreeSurface(surface);
		return true;
	}	
}

void Texture::render(SDL_Renderer *renderer,i16 x,i16 y) const
{
	SDL_Rect rect = {x,y,this->width,this->height};
	SDL_RenderCopy(renderer,this->texture,nullptr,&rect); //{} is struct SDL_rect
}

void Texture::free()
{
	SDL_DestroyTexture(this->texture);
	this->path = nullptr;
	this->texture = nullptr;
}
