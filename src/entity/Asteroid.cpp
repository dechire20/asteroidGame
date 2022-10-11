#include "Asteroid.hpp"

Asteroid::Asteroid(){

}

void Asteroid::init(sf::Texture *texture){

    srand(time(0));
    speed = rand() % 800 + 200;
    Entity::init(&asteroid, texture, {10, 10}, 5.f);
    asteroid.setOrigin(asteroid.getTexture()->getSize().x / 2, asteroid.getTexture()->getSize().y / 2);
}

void Asteroid::update(sf::Vector2f targetPosition, sf::Time elapsedTime){
    sf::Vector2f direction = (targetPosition - asteroid.getPosition());
    asteroid.move(math.normalize(direction) * (float)speed * elapsedTime.asSeconds());
}

float Asteroid::getSpeed(){
    return speed;
}