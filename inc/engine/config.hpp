#ifndef CONFIG_H
#define CONFIG_H

namespace engine
{
    class CConfig
    {
        public:
            
            CConfig();
            ~CConfig();
            
            uint32_t m_fnuget_screen_width();
            uint32_t m_fnuget_screen_height();

        private:
            uint32_t uscreen_width;
            uint32_t uscreen_height;
    };
}

#endif