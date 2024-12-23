#include<iostream>
#define SDL_MAIN_HANDLED
#include<SDL2/SDL.h>

#include"Game.hpp"

int main(int argc, char* argv[]){

    Game::Start();

    while(!Window::shouldClose){
        Window::PollEvents();
        Game::Update();   
        Game::RenderUpdate();
    }

    Game::Terminate();

    return 0;
}