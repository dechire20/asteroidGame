#include "Player.hpp"
#include "../Game.hpp"
#include "../Handler.hpp"

void Player::init(Handler *handler, sf::Texture *texture){
    DEFAULT_SPEED = 400;
    currentSpeed = DEFAULT_SPEED;
    this->handler = handler;
    Entity::init(&mPlayer, texture, {handler->getGame()->getScreenSize().x / 2, handler->getGame()->getScreenSize().y / 2}, 4.f);
    mPlayer.setOrigin(sf::Vector2f(mPlayer.getTexture()->getSize().x / 4, mPlayer.getTexture()->getSize().y / 4));
    animation.init(texture, sf::Vector2u(2, 1), 0.3f);
}

void Player::move(sf::Time elapsedTime){
    mPlayer.move(mVelocity * elapsedTime.asSeconds());
}

void Player::update(sf::Time elapsedTime){
    getInput(handler->getKeyManager());
    move(elapsedTime);

    animation.update(0, elapsedTime.asSeconds());
    mPlayer.setTextureRect(animation.uvRect);
}

void Player::getInput(KeyManager mKeyManager){
    mVelocity = {0.f, 0.f};
    if (mKeyManager.left) mVelocity.x -= currentSpeed;
    if (mKeyManager.right) mVelocity.x += currentSpeed;
    if (mKeyManager.up) mVelocity.y -= currentSpeed;
    if (mKeyManager.down) mVelocity.y += currentSpeed;

    if (mKeyManager.boost && handler->getGasTank().getCurrentValue()){
        currentSpeed += 3;
    }
    else if (handler->getGasTank().getCurrentValue() <= handler->getGasTank().getMaxValue()){
        currentSpeed = DEFAULT_SPEED;
    }
}

sf::Vector2f Player::getPosition(){
    return mPlayer.getPosition();
}

float Player::getSpeed(){
    return currentSpeed;
}