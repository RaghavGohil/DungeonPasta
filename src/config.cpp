#include<../inc/engine/config.hpp>

namespace engine
{
    Config::Config(uint32_t screen_width, uint32_t screen_height, std::string title)
    {
        Config::m_screen_width = screen_width;
        Config::m_screen_height = screen_height;
        Config::m_title = title;
    }

    uint32_t Config::getScreenWidth() const
    {
        return m_screen_width;
    }

    uint32_t Config::getScreenHeight() const
    {
        return m_screen_height;
    }

    std::string Config::getTitle() const
    {
        return m_title;
    } 
}