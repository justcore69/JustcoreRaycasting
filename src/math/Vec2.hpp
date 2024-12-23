#pragma once
#include<cmath>

#define PI 3.1415926535f
#define Deg2Rad PI / 180
#define Rad2Deg 180 / PI

class Vec2{
public:
    float x, y;
    Vec2();
    Vec2(float x, float y);

    static float dot(Vec2 a, Vec2 b);
    static float dist(Vec2 a, Vec2 b);
};