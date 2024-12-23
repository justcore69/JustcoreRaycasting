#pragma once

class Color{
public:
    int r, g, b, a;

    static Color white;
    static Color black;
    static Color grey;
    static Color darkGray;
    static Color red;
    static Color green;
    static Color blue;

    Color(int r, int g, int b, int a);
    Color(int r, int g, int b);
};