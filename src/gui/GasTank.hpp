#ifndef GUI_GASTANK_HPP
#define GUI_GASTANK_HPP

#include "SFML/Graphics.hpp"
#include "../util/KeyManager.hpp"

class GasTank{
    public:
        GasTank();
        void update(KeyManager *mKeyManager);
        float getMaxValue();
        float getCurrentValue();
        sf::RectangleShape getGasTank();

    private:
        sf::RectangleShape mGasTank;
        float maxValue;
        float currentValue;
        float fuelCost;
        float refuelValue;
};


#endif