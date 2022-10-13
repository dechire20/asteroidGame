#include "Statistics.hpp"
#include "../Handler.hpp"
#include "../Game.hpp"
#include <iostream>

Statistics::Statistics(){
    statisticsNumFrames = 0;
}

void Statistics::init(Handler *handler, sf::Font *font){
    text.setFont(*font);
    text.setPosition(handler->getScreenSize().x - 230.f, 10.f);
    text.setCharacterSize(20);
}

void Statistics::update(sf::Time elapsedTime){
    statisticsUpdateTime += elapsedTime;
    statisticsNumFrames += 1;

    if (statisticsUpdateTime >= sf::seconds(1.0f)){
        text.setString(
        "Frames / Second: " + std::to_string(statisticsNumFrames) + "\n" +
        "Time / Update: " + std::to_string(statisticsUpdateTime.asMicroseconds() / statisticsNumFrames) + " us");

        statisticsUpdateTime -= sf::seconds(1.0f);
        statisticsNumFrames = 0;
    }
}

sf::Text Statistics::getStatistics(){
    return text;

}