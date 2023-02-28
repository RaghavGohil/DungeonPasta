#include <log.h>
#define LOGFILE "../logs/logs.txt"

namespace engine
{

    bool Log::m_Init = Engine::m_init;

    // Check if engine is initialized. If yes, it will try to initialize log.
    Log::Log()
    {
        Log::m_Init = Engine::m_init;
    }

    void Log::LogFile(const char* message, uint32_t mode)
    {
        std::fstream fs;
        fs.open(LOGFILE,std::ios::out);

        if (!fs) 
        {
		    Log::LogConsole("Can't create or open log file.",2);
	    }
	    else 
        {
		    //Write to the file.
            switch(mode)
            {
                case 0:
                    fs << "INFO: " << message << "\n";break;
                case 1:
                    fs << "WARNING: " << message << "\n";break;
                case 2:
                    fs << "ERROR: " << message << "\n";break;
            }
		    fs.close(); 
	    }
    }


    void Log::LogConsole(const char* message, uint32_t mode)
    {
        if(Log::m_Init)
        {
            switch(mode)
            {
                case 0:
                    std::cout << "INFO: " << message << std::endl;break;
                case 1:
                    std::cout << "WARNING: " << message << std::endl;break;
                case 2:
                    std::cout << "ERROR: " << message << std::endl;break;
            }
        }
        
        else
            std::cout << "Engine not initialized.\n";
    }
}