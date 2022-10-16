#include "Game.hpp"

sf::Vector2f const SCREENSIZE{1000, 700};

Game::Game():
mWindow(sf::VideoMode(SCREENSIZE.x, SCREENSIZE.y), "mors", sf::Style::Close),
assets(),
animation(),
keyManager(),
math(),
gasTank(),
asteroid(),
player(),
handler(this),
statistics(),
screenSize(SCREENSIZE)
{
    player.init(&handler, assets.getTextures(Textures::Spaceship), assets.getFonts(Fonts::Sansation));
    asteroid.init(&handler, assets.getTextures(Textures::Asteroid), player.getPointsCounter());
    statistics.init(&handler, assets.getFonts(Fonts::Sansation));
}

void Game::run(){
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time timePerFrame = sf::seconds(1.f / 60.f);
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;

			processEvents();
			update(timePerFrame);
		}
		render();
	}    
}

void Game::processEvents(){
    sf::Event event;

    while (mWindow.pollEvent(event)){

        switch(event.type){

            case sf::Event::KeyPressed:
                keyManager.keyInput(event.key.code, true);
                break;

            case sf::Event::KeyReleased:
                keyManager.keyInput(event.key.code, false);
                break;

            case sf::Event::Closed:
                mWindow.close();
                break;

        }
    }
}

void Game::update(sf::Time elapsedTime){

    keyManager.update();
    gasTank.update(&keyManager);
    asteroid.update(player.getBoundingBox()->getPosition(), elapsedTime);
    player.update(elapsedTime);
    statistics.update(elapsedTime);
}

void Game::render(){
    mWindow.clear();
    mWindow.draw(*player.getSprite());
    mWindow.draw(*asteroid.getSprite());

    // gui
    mWindow.draw(gasTank.getGasTank());
    mWindow.draw(statistics.getStatistics());
    mWindow.draw(*player.getTextCounter());
    mWindow.display();
}

sf::Vector2f Game::getScreenSize(){
    return screenSize;
}

KeyManager Game::getKeyManager(){
    return keyManager;
}

GasTank Game::getGasTank(){
    return gasTank;
}

sf::RectangleShape *Game::getAsteroidBoundingBox(){
    return asteroid.getBoundingBox();
}