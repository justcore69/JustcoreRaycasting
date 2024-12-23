#include"WorldRenderer.hpp"

SDL_Renderer* WorldRenderer::_renderer = nullptr;

void WorldRenderer::Initialize(){
    _renderer = Window::renderer;
}

void WorldRenderer::DrawVerticalLine(int x, float h, Color c){
    SDL_SetRenderDrawColor(_renderer, c.r, c.g, c.b, c.a);
    SDL_RenderDrawLine(_renderer, x, WINDOW_H / 2 + h * WINDOW_H / 2, x, WINDOW_H / 2 - h * WINDOW_H / 2);
}

Raycast WorldRenderer::CastRay(float startX, float startY, float angle, Color color){
    float r = 360.0f;
    float m = (modf(angle, &r) == 90) ? std::numeric_limits<float>::max() : tanf(angle * Deg2Rad);

    Vec2 dir = Vec2(cosf(angle * Deg2Rad), sinf(angle * Deg2Rad));

    float localX = startX - static_cast<int>(startX);
    float localY = startY - static_cast<int>(startY);

    int mapX = static_cast<int>(startX);
    int mapY = static_cast<int>(startY);

    std::vector<Vec2> intersections;
    std::vector<Vec2> hits;

    // TODO: Look for shortcuts in the ray collision algorithm. It's fast enough, but might be even faster

    for(int i = 0; i <= 10; i++){ // Vertical
        float d = dir.x >= 0 ? (1 - localX) : localX; 
        float x = startX + (d + i) * (dir.x >= 0 ? 1 : -1);
        float y = startY + m * (d + i) * (dir.x >= 0 ? 1 : -1);

        intersections.push_back(Vec2(x, y));

        if(Game::HasCharacterOn(Vec2((int)x + (dir.x >= 0 ? 0 : -1), (int)y), '#')){
            // Hit
            hits.push_back(Vec2(x, y));
        }
    }

    for(int i = 0; i <= 10; i++){ // Horizontal
        float d = dir.y >= 0 ? (1 - localY) : localY; 
        float x = startX + 1.0f / m * (d + i) * (dir.y >= 0 ? 1 : -1);
        float y = startY + (d + i) * (dir.y >= 0 ? 1 : -1);

        intersections.push_back(Vec2(x, y));

        if(Game::HasCharacterOn(Vec2((int)x, (int)y + (dir.y >= 0 ? 0 : -1)), '#')){
            // Hit
            hits.push_back(Vec2(x, y));
        }
    }

    return Raycast(Vec2(startX, startY), angle, hits);
}

void WorldRenderer::DrawWallsGreedy(){

    // Is called greedy because it casts a ray for every vertical line on the screen

    // TODO: implement DrawWalls (not greedy) that will cast rays for every wall corner instead of every vertical line
    // It will significantly enhance perfomance, leaving us space for the CPU texturing!

    int c = 32;

    for(int i = 0; i < c; i++){
        float s = Game::player->fov / c;
        Raycast ray = CastRay(Game::player->position.x, Game::player->position.y, Game::player->rotation + s * i - Game::player->fov / 2, Color::white);
        MinimapRenderer::DrawFunctionDelayed(std::bind(MinimapRenderer::DrawRay, ray, Color::white));
        float d = std::max(Vec2::dist(ray.startPosition, ray.firstHit), 1.0f);
        if(d > 0){
            DrawVerticalLine(WINDOW_W / c * i, 1 / d, Color(255 / d, 255 / d, 255 / d, 255));
        }
        else{
            DrawVerticalLine(WINDOW_W / c * i, 1, Color(255, 255, 255, 255));
        }
    }
}