#include"Vec2.hpp"

Vec2::Vec2(){
    x = 0;
    y = 0;
}

Vec2::Vec2(float x, float y){
    this->x = x;
    this->y = y;
}

// TODO: define arithmetic operators

float Vec2::dot(Vec2 a, Vec2 b){
    return a.x * b.x + a.y * b.y;
}

float Vec2::dist(Vec2 a, Vec2 b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}