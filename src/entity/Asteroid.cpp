#include "Asteroid.hpp"
#include <iostream>

Asteroid::Asteroid():
posOutside{-11, -10, 710, 1010} // -11 and 1010 is x, -10 and 710 is y
{
    hasSpawned = true;
}

void Asteroid::init(Handler *handler, sf::Texture *texture){
    srand(time(0));
    speed = 300;
    Entity::init(handler, &asteroid, texture, getRandomPosition(), 5.f);
    asteroid.setOrigin(asteroid.getTexture()->getSize().x / 2, asteroid.getTexture()->getSize().y / 2);
    targetPosition = sf::Vector2f(handler->getScreenSize().x / 2, handler->getScreenSize().y / 2) - asteroid.getPosition();

    boundingBox.setSize({60.f, 60.f});
    boundingBox.setOrigin({boundingBox.getSize().x / 2, boundingBox.getSize().y / 2});
}

void Asteroid::update(sf::Vector2f targetPos, sf::Time elapsedTime){
    asteroid.move(math.normalize(this->targetPosition) * (float)speed * elapsedTime.asSeconds());
    boundingBox.setPosition(asteroid.getPosition());

    if (hasSpawned && !outOfBounds()){
        hasSpawned = false;
    }
    else if (!hasSpawned && outOfBounds()){
        asteroid.setPosition(getRandomPosition());
        this->targetPosition = targetPos - asteroid.getPosition();
        speed = rand() % 2000 + 800;
        hasSpawned = true;
    }

}

sf::Vector2f Asteroid::getRandomPosition(){

    randomPosition = posOutside[rand() % 4];
    randX = rand() % 1000;
    randY = rand() % 700;
    //speed = rand() % 5000 + 1000;
    switch (randomPosition)
    {
    case -11:
        return {(float)randomPosition, randY};
        break;

    case 1010:    
        return {(float)randomPosition, randY};
        break;
    
    case -10:
        return {randX, (float)randomPosition};
        break;
    
    case 710:
        return {randX, (float)randomPosition};
        break;

    default:
        break;
    }

    return {500, 500};
}

float Asteroid::getSpeed(){
    return speed;
}