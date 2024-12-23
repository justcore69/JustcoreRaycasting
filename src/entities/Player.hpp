#pragma once

#include<iostream>
#include"Game.hpp"
#include"../math/Vec2.hpp"

class Game;

class Player{
public:
    Vec2 position = Vec2(0, 0);

    float rotation = 0;
    float fov = 90;

    Vec2 direction = Vec2(0, 0);

    float movementSpeed = 4;
    float rotationSpeed = 10;

    bool keyPressedW = false, keyPressedA = false, keyPressedS = false, keyPressedD = false;

    Player(Vec2 position, float rotation);

    void Move(float angle);
    void Rotate(float angle);
    void Update();
};