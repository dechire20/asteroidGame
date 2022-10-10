#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"
#include "../input/KeyManager.hpp"
#include "SFML/Graphics.hpp"

class Player : public Entity{
    public:
        Player();
        void move(sf::Time elapsedTIme);
        void update();
    
    private:
        void getInput(KeyManager mKeyManager);
    
    private:
        sf::Vector2f mVelocity;
        sf::Sprite mPlayer;

        float DEFAULT_SPEED;
        float currentSpeed;
};

#endif