#pragma once

#include<vector>
#include<cmath>
#include<algorithm>

#include"Window.hpp"
#include"rendering/MinimapRenderer.hpp"
#include"rendering/WorldRenderer.hpp"
#include"Color.hpp"
#include"Time.hpp"
#include"AssetLoader.hpp"
#include"entities/Player.hpp"

#define PI 3.1415926535f
#define Deg2Rad PI / 180
#define Rad2Deg 180 / PI

class Player;

class Game{
public:
    static std::vector<std::vector<int>> map;
    static Player* player;

    static void Start();
    static void Update();
    static void RenderUpdate();
    static void Terminate();

    static Vec2 GetMapPosition(char c);
    static bool HasCharacterOn(Vec2 pos, char c);
};