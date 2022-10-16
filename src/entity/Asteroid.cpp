#include "Asteroid.hpp"
#include <iostream>

Asteroid::Asteroid():
posOutside{-11, -10, 710, 1010} // -11 and 1010 is x, -10 and 710 is y
{
    hasSpawned = true;
}

void Asteroid::init(Handler *handler, sf::Texture *texture, int *counter){
    srand(time(0));
    speed = 300;
    this->counter = counter;

    Entity::init(handler, &asteroid, texture, {100.f, 100.f}, 5.f);
    asteroid.setOrigin(asteroid.getTexture()->getSize().x / 2, asteroid.getTexture()->getSize().y / 2);
    targetPosition = sf::Vector2f(handler->getScreenSize().x / 2, handler->getScreenSize().y / 2) - asteroid.getPosition();

    boundingBox.setSize({90.f, 80.f});
    boundingBox.setOrigin({boundingBox.getSize().x / 2, boundingBox.getSize().y / 2});
}

void Asteroid::update(sf::Vector2f targetPos, sf::Time elapsedTime){
    asteroid.move(math.normalize(targetPosition) * (float)speed * elapsedTime.asSeconds());
    boundingBox.setPosition({asteroid.getPosition().x + 10, asteroid.getPosition().y - 7});

    if (hasSpawned && !outOfBounds(boundingBox.getPosition())){
        hasSpawned = false;
    }
    else if (!hasSpawned && outOfBounds(boundingBox.getPosition())){
        asteroid.setPosition(getRandomPosition());
        *counter += 1;
        targetPosition = targetPos - asteroid.getPosition();
        speed = rand() % 1000 + 200;
        hasSpawned = true;
    }

}

sf::Vector2f Asteroid::getRandomPosition(){

    randomPosition = posOutside[rand() % 4];
    randX = rand() % 1000;
    randY = rand() % 700;
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
