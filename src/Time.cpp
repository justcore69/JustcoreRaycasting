#include"Time.hpp"

double Time::time = 0;
double Time::deltaTime = 0;
int Time::prevTimeTicks = 0;
int Time::fps = 0;

void Time::Init(){
    prevTimeTicks = SDL_GetTicks();
}

void Time::Tick() {
    int currentTicks = SDL_GetTicks();
    deltaTime = (currentTicks - prevTimeTicks) / 1000.0;
    prevTimeTicks = currentTicks;
    time += deltaTime;
    fps = (int)(1 / deltaTime);

    if((int)(time * 1000) % 1000 == 0) std::cout << time << " " << fps << '\n';
}