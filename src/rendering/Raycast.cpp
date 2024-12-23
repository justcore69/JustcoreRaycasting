#include"Raycast.hpp"

Raycast::Raycast(Vec2 startPosition, float angle, std::vector<Vec2> hits){
    this->startPosition = startPosition;
    this->angle = angle;
    this->direction = Vec2(cosf(angle * Deg2Rad), sinf(angle * Deg2Rad));
    this->hits = hits;

    float closestHitDistance = 1000;

    for(const auto& hit : hits){
        float dist = Vec2::dist(startPosition, hit);
        if(dist < closestHitDistance){
            closestHitDistance = dist;
            firstHit = hit;
        }
    }
}