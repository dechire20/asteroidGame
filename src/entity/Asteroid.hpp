#ifndef ENTITY_ASTEROID_HPP
#define ENTITY_ASTEROID_HPP

#include "../util/Math.hpp"
#include "../Handler.hpp"
#include "Entity.hpp"
#include "random"
#include "functional"

class Asteroid : public Entity{
    public:
        Asteroid();
        void init(Handler *handler, sf::Texture *texture);
        void update(sf::Vector2f targetPosition, sf::Time elapsedTime);
        sf::Vector2f getRandomPosition();
        float getSpeed();

    private:
        sf::Sprite asteroid;
        sf::Vector2f targetPosition;
        Math math;
        int speed;
        int posOutside[4];
        int randomPosition;
        float randX;
        float randY;
        bool hasSpawned;
};

#endif