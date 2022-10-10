#include "Entity.hpp"

void Entity::init(sf::Sprite *sprite, sf::Texture *texture, sf::Vector2f position, float scaleValue){
    sprite->setTexture(*texture);
    sprite->setScale(scale, scale);
    sprite->setPosition(position);

    this->position = position;
    this->sprite = sprite;
    this->scale = scaleValue;
}

sf::Sprite *Entity::getSprite(){
    return sprite;
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



