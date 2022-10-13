#ifndef GUI_STATISTICS_HPP
#define GUI_STATISTICS_HPP

#include "SFML/Graphics.hpp"

class Handler;
class Game;

class Statistics{
    public:
        Statistics();
        void init(Handler *handler, sf::Font *font);
        void update(sf::Time elapsedTime);
        sf::Text getStatistics();
        
    private:
        sf::Text text;
        sf::Time statisticsUpdateTime;
        std::size_t statisticsNumFrames;
};


#endif