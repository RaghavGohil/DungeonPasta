#pragma once
#include<SDL.h>
#include<mytypes.h>
#include<stdio.h>
#include<texture.h>
#include<assert.h>
#include<mymath.h>

class Entity
{

    public:
        Entity(SDL_Renderer *frenderer ,const char* fpath);
        ~Entity();

        //getters
        Vec2 getSrcVec()  const;
        Vec2 getDestVec() const;
        Vec2 getDimVec() const;
	
        //setters
        void setSrcVec(Vec2 fsrc_vec);
        void setDestVec(Vec2 fdest_vec);
        void setDimVec(Vec2 fdim_vec);

        Texture *texture;
        void free();
    
    private:
	Vec2 src_vec,dest_vec,dim_vec;//dim vec contains the width and the height
        const char *path;
};
