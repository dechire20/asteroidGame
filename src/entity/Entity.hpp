#ifndef ENTITY_ENTITY_HPP
#define ENTITY_ENTITY_HPP

#include "../gfx/Animation.hpp"
#include "../Handler.hpp"
#include "../util/AABB.hpp"

class Entity{
    public:
        void init(Handler *handler, sf::Sprite *sprite, sf::Texture *texture, sf::Vector2f position, float scaleValue);
        sf::Vector2f getPosition();
        float getWidth();
        float getHeight();
        sf::Sprite *getSprite();
        bool outOfBounds(sf::Vector2f position);
        sf::RectangleShape *getBoundingBox();

    protected:
        sf::Vector2f position;
        sf::Sprite *sprite;
        Animation animation;
        float scale;
        sf::RectangleShape boundingBox;
        Handler *handler;
        AABB aabb;
};

#endif