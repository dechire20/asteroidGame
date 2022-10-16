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
    boundingBox.setFillColor(sf::Color::Transparent);
    boundingBox.setOutlineColor(sf::Color::Red);
    boundingBox.setOutlineThickness(1);
}

bool Entity::outOfBounds(sf::Vector2f position){

    if (position.x >= handler->getScreenSize().x || position.x <= 0){
        return true;
    }
    else if (position.y >= handler->getScreenSize().y || position.y <= 0){
        return true;
    }
    
    return false;
}

sf::Sprite *Entity::getSprite(){
    return sprite;
}

sf::RectangleShape *Entity::getBoundingBox(){
    return &boundingBox;
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



