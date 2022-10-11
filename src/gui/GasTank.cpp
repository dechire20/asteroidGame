#include "GasTank.hpp"
#include "iostream"

GasTank::GasTank(){
    maxValue = 200.f;
    currentValue = maxValue;
    fuelCost = 1;
    refuelValue = 0.1;

    mGasTank.setFillColor(sf::Color(0, 152, 219, 255));
    mGasTank.setSize({20.f, maxValue});
    mGasTank.rotate(180);
    mGasTank.setPosition(30.f, 210.f);
}

void GasTank::update(KeyManager *mKeyManager){
    if (mKeyManager->boost && currentValue >= 0){
        currentValue -= fuelCost;
    }
    else if (currentValue <= maxValue){
        currentValue += 0.5;
    }

    mGasTank.setSize({20.f, currentValue / maxValue * maxValue});
}

float GasTank::getCurrentValue(){
    return currentValue;
}

float GasTank::getMaxValue(){
    return maxValue;
}

sf::RectangleShape GasTank::getGasTank(){
    return mGasTank;
}