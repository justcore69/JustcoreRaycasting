#pragma once 
#include<SDL2/SDL.h>
#include<iostream>

class Time{
public:
    static double time;
    static double deltaTime;
    static int fps;

    static void Init();
    static void Tick();

private:
    static int prevTimeTicks;
};