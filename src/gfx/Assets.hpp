/*#ifndef GFX_ASSETS_HPP
#define GFX_ASSETS_HPP

#include "ResourceHolder.hpp"
#include "SFML/Graphics.hpp"

class Assets{
    public:
        Assets();
        ResourceHolder<sf::Texture, Textures::ID> *getTextures();
        ResourceHolder<sf::Font, Fonts::ID> *getFonts();

    private:
        ResourceHolder<sf::Texture, Textures::ID> textures;
        ResourceHolder<sf::Font, Fonts::ID> fonts;
};


#endif*/