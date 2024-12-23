#include"Color.hpp"

Color::Color(int r, int g, int b, int a){
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

Color::Color(int r, int g, int b){
    this->r = r;
    this->g = g;
    this->b = b;
}

Color Color::white = Color(255, 255, 255);
Color Color::black = Color(0, 0, 0);
Color Color::grey = Color(64, 64, 64);
Color Color::darkGray = Color(16, 16, 16);
Color Color::red = Color(255, 0, 0);
Color Color::green = Color(0, 255, 0);
Color Color::blue = Color(0, 0, 255);