#include<iostream>
#include<string.h>
#include "../inc/SDL2/include/SDL.h"

int main(int argc,char *argv[])
{
    std::cout << "Hello World!";
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("title",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,600,400,SDL_WINDOW_SHOWN);
    return 0;
}