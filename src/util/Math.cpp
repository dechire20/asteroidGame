#include "Math.hpp"

sf::Vector2f Math::normalize(sf::Vector2f vec){
    float magnitude = std::sqrt(vec.x * vec.x + vec.y * vec.y);
    if (magnitude != 0){
        vec.x /= magnitude;
        vec.y /= magnitude;
    }
    return vec;
}