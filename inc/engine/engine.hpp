#ifndef ENGINE_H
#define ENGINE_H

#include<renderer.hpp>
#include<config.hpp>
#include<../sdl/sdl.h>

namespace engine
{
    class Engine
    {
        public:

            Engine(Config &config);
            ~Engine();
            void init();

            SDL_Window* window() const;
            //-

        private:
            //-
    };
}

#endif