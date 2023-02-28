#ifndef ENGINE_H
#define ENGINE_H

#include<log.h>

namespace engine
{
    class Engine
    {
        public:

            Engine();
            ~Engine();

            // Initialize engine.
            static bool m_init;
    };
}

#endif