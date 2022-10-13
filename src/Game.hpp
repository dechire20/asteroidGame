#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "gfx/ResourceHolder.hpp"
#include <string.h>
#include <iostream>
#include "gfx/Animation.hpp"
#include "input/KeyManager.hpp"
#include "util/Math.hpp"
#include "gui/GasTank.hpp"
#include "entity/Asteroid.hpp"
#include "entity/Entity.hpp"
#include "entity/Player.hpp"
#include "Handler.hpp"
#include "gui/Statistics.hpp"
#include "gfx/Assets.hpp"

class Game{
    public:
        Game();
        void run();
        sf::Vector2f getScreenSize();
        KeyManager getKeyManager();
        GasTank getGasTank();

    private:
        void processEvents();
        void update(sf::Time elapsedTime);
        void render();
        void updateStatistics(sf::Time elapsedTime);
    
    private:
        sf::RenderWindow mWindow;
        Animation animation;
        KeyManager keyManager;
        Math math;
        GasTank gasTank;
        Asteroid asteroid;
        Player player;
        Handler handler;
        Statistics statistics;
        sf::Vector2f screenSize;
        Assets assets;

};
#endif

