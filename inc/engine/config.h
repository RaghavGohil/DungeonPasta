#ifndef CONFIG_H
#define CONFIG_H

#include <string>

namespace engine
{
    class Config
    {
        public:
            Config(uint32_t, uint32_t, std::string);

            // These functions will return the screen width and the screen height. They are const as they will not modify the private variables.
            uint32_t getScreenWidth() const;
            uint32_t getScreenHeight() const;
            std::string getTitle() const;
        private:
            uint32_t m_screen_width;
            uint32_t m_screen_height;
            std::string title;
    };
}

#endif