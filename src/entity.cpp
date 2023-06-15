#include<entity.h>

Entity::Entity(SDL_Renderer *frenderer ,const char* fpath):path(fpath)
{
    this->dest_x = 0;
    this->dest_y = 0;
    this->src_x = 0;
    this->src_y = 0;

    this->texture = new Texture(fpath);

    assert(this->texture->init(frenderer));

}

Entity::~Entity()
{
    free();
}

i16 Entity::getSrcX() const {return this->src_x;}
i16 Entity::getSrcY() const {return this->src_y;}
i16 Entity::getDestX() const {return this->dest_x;}
i16 Entity::getDestY() const {return this->dest_y;}
i16 Entity::getW() const {return this->w;}
i16 Entity::getH() const {return this->h;}

void Entity::setSrcX(i16 fsrc_x){this->src_x = fsrc_x;}
void Entity::setSrcY(i16 fsrc_y){this->src_y = fsrc_y;}
void Entity::setDestX(i16 fdest_x){this->dest_x = fdest_x;}
void Entity::setDestY(i16 fdest_y){this->dest_y = fdest_y;}
void Entity::setW(i16 fw){this->dest_y = w;}
void Entity::setH(i16 fh){this->dest_y = h;}

void Entity::free()
{
    delete this->texture;
    this->texture = nullptr;
}