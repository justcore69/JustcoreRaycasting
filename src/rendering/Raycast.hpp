#pragma once
#include<vector>
#include"math/Vec2.hpp"

// A data type to store a casted ray
class Raycast{
public:
    Raycast(Vec2 startPosition, float angle, std::vector<Vec2> hits);

    Vec2 startPosition;

    std::vector<Vec2> hits;
    Vec2 firstHit;

    float angle;
    Vec2 direction;
};