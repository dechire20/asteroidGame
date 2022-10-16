#include "Player.hpp"
#include "../Game.hpp"
#include "../Handler.hpp"


void Player::init(Handler *handler, sf::Texture *texture, sf::Font *font){

    DEFAULT_SPEED = 400;
    dashLenght = 13000.f;
    currentSpeed = DEFAULT_SPEED;
    this->handler = handler;

    Entity::init(handler, &mPlayer, texture, {handler->getGame()->getScreenSize().x / 2, handler->getGame()->getScreenSize().y / 2}, 4.f);
    mPlayer.setOrigin(sf::Vector2f(mPlayer.getTexture()->getSize().x / 4, mPlayer.getTexture()->getSize().y / 4));
    animation.init(texture, sf::Vector2u(2, 1), 0.3f);

    boundingBox.setSize({90.f, 50.f});
    boundingBox.setOrigin({boundingBox.getSize().x / 2, boundingBox.getSize().y / 2});
    
    counter.setPosition(handler->getScreenSize().x / 2, 10);
    counter.setFont(*font);
    counter.setCharacterSize(40);
}

void Player::move(sf::Time elapsedTime){
    minX = boundingBox.getPosition().x - (boundingBox.getSize().x / 2) + (mVelocity * elapsedTime.asSeconds()).x;
    minY = boundingBox.getPosition().y - (boundingBox.getSize().y / 2) + (mVelocity * elapsedTime.asSeconds()).y;
    maxX = boundingBox.getPosition().x + (boundingBox.getSize().x / 2) + (mVelocity * elapsedTime.asSeconds()).x;
    maxY = boundingBox.getPosition().y + (boundingBox.getSize().y / 2) + (mVelocity * elapsedTime.asSeconds()).y; 
    position.x = 0;
    position.y = 0;

    xMove(elapsedTime);
    yMove(elapsedTime);

    mPlayer.move(position);
}

void Player::update(sf::Time elapsedTime){
    getInput(handler->getKeyManager());
    move(elapsedTime);
    deathState();
    boundingBox.setPosition({mPlayer.getPosition().x - 1, mPlayer.getPosition().y + 30});
    aabb.update(boundingBox);

    counter.setString(std::to_string(pointsCounter));
    animation.update(0, elapsedTime.asSeconds());
    mPlayer.setTextureRect(animation.uvRect);

}

void Player::getInput(KeyManager mKeyManager){
    mVelocity = {0.f, 0.f};
    if (mKeyManager.left) mVelocity.x -= currentSpeed;
    if (mKeyManager.right) mVelocity.x += currentSpeed;
    if (mKeyManager.up) mVelocity.y -= currentSpeed;
    if (mKeyManager.down) mVelocity.y += currentSpeed;

    if (mKeyManager.boost && !isDashing && handler->getGasTank().getCurrentValue() == 0){
        mVelocity = math.normalize(mVelocity) * dashLenght;
        isDashing = true;
    }
    else if (isDashing && !mKeyManager.boost){
        isDashing = false;
    }

}

void Player::xMove(sf::Time elapsedTime){
    xMoveValue = mVelocity.x * elapsedTime.asSeconds();

    if (xMoveValue > 0){
        if (!outOfBounds({maxX, minY}) && !outOfBounds({maxX, maxY})){
            position.x += xMoveValue;
        }
    }
    else if (xMoveValue < 0){
        if (!outOfBounds({minX, minY}) && !outOfBounds({minX, maxY})){
            position.x += xMoveValue;
        }
    }
}

void Player::yMove(sf::Time elapsedTime){
    yMoveValue = mVelocity.y * elapsedTime.asSeconds();

    if (yMoveValue > 0){
        if (!outOfBounds({minX, maxY}) && !outOfBounds({maxX, maxY})){
            position.y += yMoveValue;
        }
    }
    else if (yMoveValue < 0){
        if (!outOfBounds({minX, minY}) && !outOfBounds({maxX, minY})){
            position.y += yMoveValue;
        }
    }
}

void Player::deathState(){
    if (aabb.collides(*handler->getAsteroidBoundingBox())){
        pointsCounter = 0;
    }
}

int *Player::getPointsCounter(){
    return &pointsCounter;
}

sf::Text *Player::getTextCounter(){
    return &counter;
}

sf::Vector2f Player::getPosition(){
    return mPlayer.getPosition();
}

float Player::getSpeed(){
    return currentSpeed;
}
