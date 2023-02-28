#ifndef LOG_H
#define LOG_H

#include<engine.h>
#include <iostream>
#include <string>
#include <fstream>

namespace engine
{   
    // The log class is a simple implementation which enables the user to log info, error and warnings to the console. 
    class Log
    {
        public:
            static void Init();
            //There are 3 modes. 0: Info, 1: Warning , 2: Error. 
            // This function will log into ../logs/logs.txt. For more, see definition.
            static void LogFile(const char*, uint32_t mode);
            // This functions logs directly to the console (in a window application, this is rendered useless).
            static void LogConsole(const char*, uint32_t mode);
        private:
            // This class will create no instances.
            Log();
            // Initialize log.
            static bool m_Init;
    };
}

#endif