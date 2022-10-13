#include "Assets.hpp"

Assets::Assets(){
    textures.load(Textures::Spaceship, "res/entity/player/Spaceship1.png");
    textures.load(Textures::Asteroid, "res/entity/objects/asteroid.png");
    textures.load(Textures::SmallStar, "res/background/smallStar.png");
    textures.load(Textures::MedStar, "res/background/medStar.png");
    fonts.load(Fonts::Sansation, "res/fonts/Sansation.ttf");
}

sf::Texture *Assets::getTextures(Textures::ID texture){
    return &textures.get(texture);
}

sf::Font *Assets::getFonts(Fonts::ID font){
    return &fonts.get(font);
}