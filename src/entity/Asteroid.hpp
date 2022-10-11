#ifndef ENTITY_ASTEROID_HPP
#define ENTITY_ASTEROID_HPP

#include "SFML/Graphics.hpp"
#include "../util/Math.hpp"
#include "../gfx/ResourceHolder.hpp"
#include "Entity.hpp"
#include "random"
#include "functional"

class Asteroid : public Entity{
    public:
        void init(sf::Texture *textures);
        void update(sf::Vector2f targetPosition, sf::Time elapsedTime);
        float getSpeed();
        Asteroid();

    private:
        sf::Sprite asteroid;
        Math math;
        int speed;
};

#endif