#ifndef ENGINE_H
#define ENGINE_H

#include<renderer.hpp>
#include<config.hpp>
#include<log.hpp>

#include<iostream.h>
#include<../sdl/sdl.h>

namespace engine
{
    class Engine
    {
        public:

            Engine(Config &config);
            ~Engine();

            void initializeSDL() const;
            SDL_Window* createWindow() const;
        private:
            // Is the engine initialized?
            bool m_init;
    };
}

#endif