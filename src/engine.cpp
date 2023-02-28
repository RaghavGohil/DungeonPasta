#include<engine.h>
#include<iostream>

namespace engine
{

    bool Engine::m_init = false;

    Engine::Engine()
    {
        Engine::m_init = true;
    }
    
    Engine::~Engine()
    {
        //-
    }

    // void Engine::initializeSDL()
    // {
    //     if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    //     {
    //         std::cout << "SDL could not be initialized." << std::endl;
    //         return;
    //     }

    //     // At last we know that the engine is initialized.
    //     Engine::m_init = true;
    // }

    // SDL_Window* Engine::createWindow(Config* config)
    // {
    //     //Create window
    //     window = SDL_CreateWindow(config->m_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,config->m_screen_width,config->m_screen_height, SDL_WINDOW_SHOWN );
    //     if(window == NULL)
    //     {
    //         Engine::log.LogError("Window couldn't be created.");
    //     }
    //     // If window is null, it returns null else it returns the window.
    //     return window;
    // }
}