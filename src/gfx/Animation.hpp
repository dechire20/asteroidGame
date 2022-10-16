#ifndef GFX_ANIMATION_HPP
#define GFX_ANIMATION_HPP

#include "../../lib/SFML/include/SFML/Graphics.hpp"

class Animation{
    public:
        void init(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);
        void update(int row, float deltaTime);
    
    public:
        sf::IntRect uvRect;

    private:
        sf::Vector2u imageCount;
        sf::Vector2u currentImage;
    
        float totalTime;
        float switchTime;
};
#endif