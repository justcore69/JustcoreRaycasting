#include"AssetLoader.hpp"

std::vector<std::vector<int>> AssetLoader::LoadMap(std::string path){
    std::ifstream file("assets/TestMap.txt");
    std::vector<std::vector<int>> map = {};
    std::string line;

    if(file.is_open()){
        while(std::getline(file, line)){
            map.push_back({});

            for(int i = 0; i < line.size(); i++){
                map[map.size()-1].push_back(line[i]);
            }
        }

        std::cout << "AsstLoader::LoadMap - Map Loaded from " << path << " succesfully" << '\n';
        
        file.close();
        return map;
    }

    std::cout << "AsstLoader::LoadMap - Failed to open " << path << '\n';
    return {};
}