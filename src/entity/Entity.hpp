#ifndef ENTITY_ENTITY_HPP
#define ENTITY_ENTITY_HPP

#include "SFML/Graphics.hpp"
#include "../gfx/Animation.hpp"

class Entity{
    public:
        void init(sf::Sprite *sprite, sf::Texture *texture, sf::Vector2f position, float scaleValue);
        sf::Vector2f getPosition();
        float getWidth();
        float getHeight();
        sf::Sprite *getSprite();

    protected:
        sf::Vector2f position;
        sf::Sprite *sprite;
        Animation animation;
        float scale;
};

#endif