#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<fstream>

class AssetLoader{
public:
    static std::vector<std::vector<int>> LoadMap(std::string path);
};