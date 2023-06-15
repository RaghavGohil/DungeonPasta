#pragma once
#include<SDL.h>
#include<mytypes.h>
#include<stdio.h>
#include<texture.h>
#include<assert.h>

class Entity
{

    public:
        Entity(SDL_Renderer *frenderer ,const char* fpath);
        ~Entity();

        //getters
        i16 getSrcX()  const;
        i16 getSrcY()  const;
        i16 getDestX() const;
        i16 getDestY() const;
        i16 getW() const;
        i16 getH() const;
        //setters
        void setSrcX(i16 fsrc_x);
        void setSrcY(i16 fsrc_y);
        void setDestX(i16 fdest_x);
        void setDestY(i16 fdest_y);
        void setW(i16 fw);
        void setH(i16 fh);

        Texture *texture;

        void free();
    
    private:
        i16 src_x,src_y,dest_x,dest_y,w,h;
        const char *path;
};