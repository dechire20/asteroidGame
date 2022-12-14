#include "KeyManager.hpp"

KeyManager::KeyManager(){
    for (int i = 0; i < 1000; i++){
        keys[i] = false;
    }
}

void KeyManager::update(){
    left = keys[sf::Keyboard::A];
    right = keys[sf::Keyboard::D];
    up = keys[sf::Keyboard::W];
    down = keys[sf::Keyboard::S];
    boost = keys[sf::Keyboard::Space];
}

void KeyManager::keyInput(sf::Keyboard::Key key, bool isPressed){
    keys[key] = isPressed;
}