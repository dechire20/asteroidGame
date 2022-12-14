#ifndef UTIL_AABB_HPP
#define UTIL_AABB_HPP

#include "../../lib/SFML/include/SFML/Graphics.hpp"

class AABB{
    public:
        void update(sf::RectangleShape bounds);
        bool collides(sf::RectangleShape otherBounds);
    
    private:
        float x;
        float y;
        int width;
        int height;
};



#endif