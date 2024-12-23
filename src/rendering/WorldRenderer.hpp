#pragma once

#include"Game.hpp"
#include"Raycast.hpp"

class WorldRenderer{
public:
    static void Initialize();
    static void DrawVerticalLine(int x, float h, Color c);
    static Raycast CastRay(float startX, float startY, float angle, Color color);
    static void DrawWallsGreedy();
private:
    static SDL_Renderer* _renderer;
};