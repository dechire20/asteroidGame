#include "Handler.hpp"
#include "Game.hpp"

Handler::Handler(Game *game){
    this->game = game;
}

KeyManager Handler::getKeyManager(){
    return game->getKeyManager();
}

Game *Handler::getGame(){
    return game;
}

GasTank Handler::getGasTank(){
    return game->getGasTank();
}

sf::Vector2f Handler::getScreenSize(){
    return game->getScreenSize();
}