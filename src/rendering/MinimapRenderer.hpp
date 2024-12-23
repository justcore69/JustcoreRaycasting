#pragma once

#include<vector>
#include<cmath>
#include<limits>
#include<functional>

#include"Color.hpp"
#include"Game.hpp"
#include"math/Vec2.hpp"

#include"Raycast.hpp"

#include"entities/Player.hpp"

class MinimapRenderer{
public:
    static Vec2 mapPosition;
    static const int gridSize;
    static const int playerSize;

    static void Initialize();
    static void RenderMinimap();

    static void DrawBlock(int x, int y, Color color);
    static void DrawCircle(float x, float y, float r, Color color);
    static void DrawPlayer(float x, float y, float a, Color color);
    static void DrawRay(Raycast ray, Color color);
    static void DrawFunctionDelayed(std::function<void()> function);

private:
    static SDL_Window* _window;
    static SDL_Renderer* _renderer;
    static std::vector<std::function<void()>> _drawBuffer;
};