#include <../inc/engine/log.hpp>

namespace engine
{
    Log::Log(Engine* engine)
    {
        Log::m_init = false;
        if(engine == NULL)
        {
            std::cout << "Please initialize engine.\n";
            return;
        }

        else
        {
            if(engine->m_init)
                Log::m_init = true;
            else
                std::cout << "Please initialize engine.\n";
        }
    }

    Log::~Log()
    {
        std::cout << "Log memory freed.\n";
    }

    void Log::LogInfo(const char* message)
    {
        if(Log::m_init)
        {
            SDL_Log(strcat("Info: ",message));
        }
        
        else
            std::cout << "Engine not initialized.\n";
    }

    void Log::LogWarning(const char* message)
    {
        if(Log::m_init)
        {
            SDL_Log(strcat("Warning: ",message));
        }

        else
            std::cout << "Engine not initialized.\n";
    }

    void Log::LogError(const char* message)
    {
        if(Log::m_init)
        {
            SDL_Log(strcat("Error: ",message));
        }

        else
            std::cout << "Engine not initialized.\n";
    }
}