#include "Player.hpp"

Player::Player(){
    DEFAULT_SPEED = 400;
    currentSpeed = DEFAULT_SPEED;
}

void Player::move(sf::Time elapsedTime){
    position += mVelocity * elapsedTime.asSeconds();
}

void Player::update(){

}

void Player::getInput(KeyManager mKeyManager){
    if (mKeyManager.left) mVelocity.x -= currentSpeed;
    if (mKeyManager.right) mVelocity.x += currentSpeed;
    if (mKeyManager.up) mVelocity.y -= currentSpeed;
    if (mKeyManager.down) mVelocity.y += currentSpeed;

    if (mKeyManager.boost){
        
    }
}