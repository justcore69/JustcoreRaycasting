#include"MinimapRenderer.hpp"

Vec2 MinimapRenderer::mapPosition = Vec2(0, 0);

const int MinimapRenderer::gridSize = 16;
const int MinimapRenderer::playerSize = 3/4 * MinimapRenderer::gridSize;;

SDL_Window* MinimapRenderer::_window = nullptr;
SDL_Renderer* MinimapRenderer::_renderer = nullptr;

std::vector<std::function<void()>> MinimapRenderer::_drawBuffer = {};

void MinimapRenderer::Initialize(){
    _window = Window::window;
    _renderer = Window::renderer;

    //mapInfo = AssetLoader::LoadMap("assets/TestMap.txt");
}

void MinimapRenderer::RenderMinimap(){
    auto map = Game::map;

    SDL_Rect r = SDL_Rect();
    r.x = 0;
    r.y = 0;
    r.w = Game::map[0].size() * gridSize;
    r.h = Game::map.size() * gridSize;

    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderFillRect(_renderer, &r);

    // Draw blocks

    for(int y = 0; y < map.size(); y++){
        for(int x = 0; x < map[y].size(); x++){
            switch (map[y][x])
            {
                case '#': DrawBlock(x * gridSize, y * gridSize, Color::green); break;
                case '.': DrawBlock(x * gridSize, y * gridSize, Color::darkGray); break;
                case 'P': DrawBlock(x * gridSize, y * gridSize, Color::darkGray); break;
            }
        }
    }

    // Draw entities

    DrawPlayer(Game::player->position.x, Game::player->position.y, Game::player->rotation, Color::green);

    // Draw delayed draw functions

    for(const auto& drawCall : _drawBuffer){
        drawCall();
    }
    _drawBuffer.clear();
}

void MinimapRenderer::DrawBlock(int x, int y, Color color){
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = gridSize;
    r.h = gridSize;

    SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawRect(_renderer, &r);
}

void MinimapRenderer::DrawCircle(float x, float y, float r, Color color){
    float step = PI*2 / 100;

    for(float i = 0; i < PI*2; i+=step){
        SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawLineF(_renderer,
        gridSize * (x + cosf(i) * r),
        gridSize * (y + sinf(i) * r),
        gridSize * (x + cosf(i+step) * r),
        gridSize * (y + sinf(i+step) * r));
    }
}

void MinimapRenderer::DrawPlayer(float x, float y, float a, Color color){
    float r = 0.25;

    DrawCircle(x, y, r, color);

    SDL_RenderDrawLineF(_renderer, 
    x * gridSize, 
    y * gridSize, 
    (x + cosf(a * Deg2Rad) * r) * gridSize, 
    (y + sinf(a * Deg2Rad) * r) * gridSize);

    SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 255);

    SDL_RenderDrawLineF(_renderer, 
    x * gridSize, 
    y * gridSize, 
    x * gridSize + (Game::player->direction.x) * gridSize, 
    y * gridSize + (Game::player->direction.y) * gridSize);
}

void MinimapRenderer::DrawRay(Raycast ray, Color color){
    SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
    float d = Vec2::dist(ray.startPosition, ray.firstHit);
    SDL_RenderDrawLine(_renderer, 
    ray.startPosition.x * gridSize, 
    ray.startPosition.y * gridSize, 
    (ray.startPosition.x + cosf(ray.angle * Deg2Rad) * d) * gridSize, 
    (ray.startPosition.y + sinf(ray.angle * Deg2Rad) * d) * gridSize);

    DrawCircle(ray.firstHit.x, ray.firstHit.y, 0.02f, Color::red);
}

void MinimapRenderer::DrawFunctionDelayed(std::function<void()> function){
    _drawBuffer.push_back(function);
}