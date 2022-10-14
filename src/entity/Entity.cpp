#include "Entity.hpp"
#include <iostream>

void Entity::init(Handler *handler, sf::Sprite *sprite, sf::Texture *texture, sf::Vector2f position, float scaleValue){
    // Initialize values
    this->position = position;
    this->sprite = sprite;
    this->scale = scaleValue;
    this->handler = handler;
    
    // Load sprite
    sprite->setTexture(*texture);
    sprite->setScale(scaleValue, scaleValue);
    sprite->setPosition(position);

    // Bounding box
    boundingBox.setPosition(position); // default
    boundingBox.setSize({20.f, 20.f}); // default
    boundingBox.setOrigin(boundingBox.getSize().x / 2, boundingBox.getSize().y / 2);
    boundingBox.setFillColor(sf::Color::Red);
}

bool Entity::outOfBounds(){

    if (boundingBox.getPosition().x >= handler->getScreenSize().x || boundingBox.getPosition().x <= 0){
        return true;
    }
    else if (boundingBox.getPosition().y >= handler->getScreenSize().y || boundingBox.getPosition().y <= 0){
        return true;
    }
    
    return false;
}

sf::Sprite *Entity::getSprite(){
    return sprite;
}

sf::RectangleShape Entity::getBoundingBox(){
    return boundingBox;
}

sf::Vector2f Entity::getPosition(){
    return position;
}

float Entity::getWidth(){
    return sprite->getTexture()->getSize().x * scale;
}

float Entity::getHeight(){
    return sprite->getTexture()->getSize().y * scale;
}



