#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>

namespace engine
{
    class Log
    {
        public:
            Log();
            ~Log();
            void LogInfo(std::string);
            void LogError(std::string);
            void LogWarning(std::string);
        private:
            // For checking if the engine is initialized.
            bool m_init;
    };
}

#endif