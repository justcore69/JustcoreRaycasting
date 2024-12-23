#include"Player.hpp"

Player::Player(Vec2 position, float rotation){
    this->position = position;
    this->rotation = rotation;
}

void Player::Move(float angle){
    position.x += cosf(angle * Deg2Rad) * movementSpeed * Time::deltaTime;
    position.y += sinf(angle * Deg2Rad) * movementSpeed * Time::deltaTime;
}

void Player::Rotate(float angle){
    rotation += angle * rotationSpeed * Time::deltaTime;
}

void Player::Update(){

    direction = Vec2(cosf(rotation * Deg2Rad), sinf(rotation * Deg2Rad));
    //std::cout << "dir: (" << direction.x << ", " << direction.y << ");" << '\n';

    if(keyPressedW){
        Move(rotation);
    }
    if(keyPressedA){
        //Move(rotation + PI/2);
        Rotate(-rotationSpeed);
    }
    if(keyPressedS){
        Move(rotation + 180);
    }
    if(keyPressedD){
        //Move(rotation - PI/2);
        Rotate(rotationSpeed);
    }
}