#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "input/KeyManager.hpp"
#include "gui/GasTank.hpp"
#include "memory"

class Game;

class Handler{
    public:
        Handler(Game *game);
        KeyManager getKeyManager();
        Game *getGame();
        GasTank getGasTank();
        sf::Vector2f getScreenSize();

    private:
        Game *game;
};

#endif