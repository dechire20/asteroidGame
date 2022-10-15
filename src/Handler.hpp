#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "util/KeyManager.hpp"
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
        sf::RectangleShape *getAsteroidBoundingBox();

    private:
        Game *game;
};

#endif