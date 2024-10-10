#include<iostream>
#define SDL_MAIN_HANDLED
#include<SDL2/SDL.h>

#define WINDOW_W 640
#define WINDOW_H 480

int main(int argc, char* argv[]){
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1) std::cerr << "SDL2 didn't initialize\n";
    std::cout << "Hello, sdl22" << '\n';

    SDL_Window* window = SDL_CreateWindow("Justcore Raycasting", 100, 100, WINDOW_W, WINDOW_H, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, 0);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    float time = 0;
    float deltaTime = 0;
    float prevTimeTicks = 0;

    bool shouldCLose = false;

    while(!shouldCLose){

        SDL_Event e;
        while (SDL_PollEvent(&e)){
            switch (e.type){
                case SDL_QUIT: shouldCLose = true; break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_Rect r;
        r.x = WINDOW_W / 2 - 16 + cosf(time) * 128;
        r.y = WINDOW_H / 2 - 16 + sinf(time) * 128;
        r.w = 32;
        r.h = 32;

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderDrawRect(renderer, &r);

        SDL_RenderPresent(renderer);

        deltaTime = (SDL_GetTicks() - prevTimeTicks) / 1000;
        prevTimeTicks = SDL_GetTicks();
        time += deltaTime;
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    
    return 0;
}