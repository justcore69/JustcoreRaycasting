#include"Game.hpp"

std::vector<std::vector<int>> Game::map = {};
Player* Game::player = nullptr;

void Game::Start(){
    Window::Initialize();

    map = AssetLoader::LoadMap("assets/TestMap.txt");

    Vec2 playerMapPosition = GetMapPosition('P');
    player = new Player(Vec2(playerMapPosition.x + 0.5, playerMapPosition.y + 0.5), 90);

    MinimapRenderer::Initialize();
    WorldRenderer::Initialize();
    Time::Init();
}

void Game::Update(){
    Time::Tick();

    player->Update();
}

void Game::RenderUpdate(){
    Window::SetDrawColor(Color::black);
    Window::Clear();

    WorldRenderer::DrawWallsGreedy();
    MinimapRenderer::RenderMinimap();
    //Window::DrawTestRect(0, 0, 32, 32);

    Window::Present();
}

void Game::Terminate(){
    Window::shouldClose = true;
    SDL_DestroyWindow(Window::window);
    SDL_DestroyRenderer(Window::renderer);
}

// TODO: Create a map class and place there the methods below

Vec2 Game::GetMapPosition(char c){
    for(int y = 0; y < map.size(); y++){
        for(int x = 0; x < map[y].size(); x++){
            if(map[y][x] == c) return Vec2(x, y);
        }
    }
    return Vec2(0, 0);
}

bool Game::HasCharacterOn(Vec2 pos, char c){
    if(pos.y >= map.size() || pos.x >= map[0].size() || pos.x < 0 || pos.y < 0) return false;
    return map[pos.y][pos.x] == c;
}