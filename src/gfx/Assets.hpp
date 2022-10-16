#ifndef GFX_ASSETS_HPP
#define GFX_ASSETS_HPP

#include "ResourceHolder.hpp"
#include "../../lib/SFML/include/SFML/Graphics.hpp"

class Assets{
    public:
        Assets();
        sf::Texture *getTextures(Textures::ID texture);
        sf::Font *getFonts(Fonts::ID texture);

    private:
        ResourceHolder<sf::Texture, Textures::ID> textures;
        ResourceHolder<sf::Font, Fonts::ID> fonts;
};


#endif