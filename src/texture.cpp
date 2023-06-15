#include<texture.h>

Texture::Texture(const char* fpath):path(fpath)
{
	//
}

Texture::~Texture(void)
{
	free();
}

bool Texture::init(SDL_Renderer *frenderer)
{
	SDL_Surface *surface = IMG_Load(this->path); 
	if(surface == nullptr)
	{
		printf("Failed to load specified image at %s.",this->path); // todo: SDL_Log 
		return false;
	}
	else
	{
		this->texture = SDL_CreateTextureFromSurface(frenderer,surface);
		if(texture == nullptr)
		{
			printf("Failed to load texture from surface from path %s.",this->path); // todo: SDL_Log 
			return false;
		}
		SDL_FreeSurface(surface);
		return true;
	}	
}

void Texture::render(SDL_Renderer *frenderer,i16 fsrc_x,i16 fsrc_y,i16 fdest_x,i16 fdest_y,u16 fw,u16 fh)
{
	SDL_Rect src_rect = {fsrc_x,fsrc_y,fw,fh};
	SDL_Rect dest_rect = {fdest_x,fdest_y,fw,fh};
	SDL_RenderCopy(frenderer,this->texture,&src_rect,&dest_rect);
}

void Texture::free(void)
{
	SDL_DestroyTexture(this->texture);
	this->path = nullptr;
	this->texture = nullptr;
}
