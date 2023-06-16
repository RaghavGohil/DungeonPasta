#include<entity.h>

Entity::Entity(SDL_Renderer *frenderer ,const char* fpath):path(fpath)
{
    this->src_vec = {0,0};
    this->dest_vec = {0,0};
    this->dim_vec = {0,0};

    this->texture = new Texture(fpath);

    assert(this->texture->init(frenderer));

}

Entity::~Entity()
{
    free();
}

Vec2 Entity::getSrcVec() const {return this->src_vec;}
Vec2 Entity::getDestVec() const {return this->dest_vec;}
Vec2 Entity::getDimVec() const {return this->dim_vec;}

void Entity::setSrcVec(Vec2 fsrc_vec){this->src_vec = fsrc_vec;}
void Entity::setDestVec(Vec2 fdest_vec){this->dest_vec = fdest_vec;}
void Entity::setDimVec(Vec2 fdim_vec){this->dim_vec = fdim_vec;}

void Entity::free()
{
    delete this->texture;
    this->texture = nullptr;
}
