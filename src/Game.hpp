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

class Game{
    public:
        Game();
        void run();

    private:
        void processEvents();
        void update(sf::Time elapsedTime);
        void render();
        void updateStatistics(sf::Time elapsedTime);
    
    private:
        sf::RenderWindow mWindow;
        sf::Sprite mPlayer;
        sf::Text mStatisticsText;
        sf::Time mStatisticsUpdateTime;
        ResourceHolder<sf::Texture, Textures::ID> textures;
        ResourceHolder<sf::Font, Fonts::ID> fonts;
        Animation animation;
        KeyManager keyManager;
        Math math;
        GasTank gasTank;
        Asteroid asteroid;

        std::size_t mStatisticsNumFrames;
        float mPlayerSpeed;
        float mPlayerCurrentSpeed; 
};
#endif

