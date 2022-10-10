#include "Asteroid.hpp"

void Asteroid::init(sf::Texture *texture){
    speed = 400.f;
    Entity::init(&asteroid, texture, {10, 10}, 5.f);
    asteroid.setOrigin(asteroid.getTexture()->getSize().x / 2, asteroid.getTexture()->getSize().y / 2);
}

void Asteroid::update(sf::Vector2f targetPosition, sf::Time elapsedTime){
    sf::Vector2f direction = (targetPosition - asteroid.getPosition());
    asteroid.move(math.normalize(direction) * speed * elapsedTime.asSeconds());
}

sf::Sprite Asteroid::getAsteroid(){
    return asteroid;
}