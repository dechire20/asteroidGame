#include "AABB.hpp"

void AABB::update(sf::RectangleShape bounds){
    this->x = bounds.getPosition().x;
    this->y = bounds.getPosition().y;
    this->width = bounds.getSize().x;
    this->height = bounds.getSize().y;
}

bool AABB::collides(sf::RectangleShape otherBounds){
    return 
        this->x < otherBounds.getPosition().x + otherBounds.getSize().x &&
        this->x + this->width > otherBounds.getPosition().x &&
        this->y < otherBounds.getPosition().y + otherBounds.getSize().y &&
        this->height + this->y > otherBounds.getPosition().y;
}