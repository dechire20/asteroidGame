#ifndef ENTITY_PLAYER_HPP
#define ENTITY_PLAYER_HPP

#include "Entity.hpp"
#include "../util/KeyManager.hpp"
#include "../util/Math.hpp"

class Game;
class Handler;

class Player : public Entity{
    public:
        void init(Handler *handler, sf::Texture *texture);
        void move(sf::Time elapsedTime);
        void update(sf::Time elapsedTime);
        sf::Vector2f getPosition();
        float getSpeed();
        void xMove(sf::Time elapsedTime);
        void yMove(sf::Time elapsedTime);
    
    private:
        void getInput(KeyManager mKeyManager);
    
    private:
        sf::Vector2f mVelocity;
        sf::Sprite mPlayer;
        Handler *handler;
        Math math;

        float DEFAULT_SPEED;
        float currentSpeed;
        float dashLenght;
        bool isDashing{false};
        float minX;
        float minY;
        float maxX;
        float maxY;
        float xMoveValue{0};
        float yMoveValue{0};
};

#endif