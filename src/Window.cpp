#include"Window.hpp"

bool Window::shouldClose = false;

SDL_Window* Window::window = nullptr;
SDL_Renderer* Window::renderer = nullptr;

void Window::Initialize(){
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1) std::cerr << "SDL2 didn't initialize\n";
    std::cout << "Hello, sdl2" << '\n';

    window = SDL_CreateWindow("Justcore Raycating", 100, 100, WINDOW_W, WINDOW_H, 0);
    renderer = SDL_CreateRenderer(window, 0, 0);

    SetDrawColor(Color::black);
    Clear();
}

void Window::SetDrawColor(Color color){
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void Window::DrawTestRect(float x, float y, float w, float h){
    SDL_Rect r;
    r.x = WINDOW_W / 2.f - 16.f + cosf(Time::time) * 128;
    r.y = WINDOW_H / 2.f - 16.f + sinf(Time::time) * 128;
    r.w = w;
    r.h = h;

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawRect(renderer, &r);
}

void Window::Clear(){
    SDL_RenderClear(renderer);
}

void Window::Present(){
    SDL_RenderPresent(renderer);
}

void Window::PollEvents(){
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        switch (e.type)
        {
            case SDL_QUIT: Game::Terminate(); break;
            case SDL_KEYDOWN:
                if(e.key.keysym.sym == SDLK_w){
                    Game::player->keyPressedW = true;
                }
                if(e.key.keysym.sym == SDLK_a){
                    Game::player->keyPressedA = true;
                }
                if(e.key.keysym.sym == SDLK_s){
                    Game::player->keyPressedS = true;
                }
                if(e.key.keysym.sym == SDLK_d){
                    Game::player->keyPressedD = true;
                }
            break;
            case SDL_KEYUP:
                if(e.key.keysym.sym == SDLK_w){
                    Game::player->keyPressedW = false;
                }
                if(e.key.keysym.sym == SDLK_a){
                    Game::player->keyPressedA = false;
                }
                if(e.key.keysym.sym == SDLK_s){
                    Game::player->keyPressedS = false;
                }
                if(e.key.keysym.sym == SDLK_d){
                    Game::player->keyPressedD = false;
                }
            break;
        }
    }
}