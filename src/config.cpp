#include<../inc/engine/config.hpp>

namespace engine
{
    Config::Config(uint32_t scr_width, uint32_t scr_height, std::string title)
    {
        Config::screen_width = scr_width;
        Config::screen_height = scr_height;
        Config::title = title;
    }
}