#pragma once

#include<iostream>
#include<SDL2/SDL.h>

#include"Color.hpp"
#include"Game.hpp"

#define WINDOW_W 640
#define WINDOW_H 480

class Window{
public:
    static bool shouldClose;

    static SDL_Window* window;
    static SDL_Renderer* renderer;

    static void Initialize();

    static void SetDrawColor(Color color);
    static void DrawTestRect(float x, float y, float w, float h);

    static void Clear();
    static void Present();
    static void PollEvents();
};