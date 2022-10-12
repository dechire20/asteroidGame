#include "Game.hpp"

sf::Vector2f const screenSize{1000, 700};

Game::Game():
mWindow(sf::VideoMode(screenSize.x, screenSize.y), "Deliver the package", sf::Style::Close),
mStatisticsText(),
mStatisticsNumFrames(0),
mStatisticsUpdateTime(),
animation(),
keyManager(),
math(),
gasTank(),
asteroid(),
mPlayer(),
textures(),
fonts(),
handler(this)
{
    textures.load(Textures::Spaceship, "res/entity/player/Spaceship1.png");
    textures.load(Textures::Asteroid, "res/entity/objects/asteroid.png");
    textures.load(Textures::SmallStar, "res/background/smallStar.png");
    textures.load(Textures::MedStar, "res/background/medStar.png");
    fonts.load(Fonts::Sansation, "res/fonts/Sansation.ttf");


    mPlayer.init(&handler, &textures.get(Textures::Spaceship));
    asteroid.init(&textures.get(Textures::Asteroid));


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

		updateStatistics(elapsedTime);
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
    asteroid.update(mPlayer.getPosition(), elapsedTime);
    mPlayer.update(elapsedTime);


}

void Game::render(){
    mWindow.clear();
    mWindow.draw(*mPlayer.getSprite());
    mWindow.draw(*asteroid.getSprite());
    mWindow.draw(gasTank.getGasTank());
    mWindow.display();
}

void Game::updateStatistics(sf::Time elapsedTime){
    mStatisticsUpdateTime += elapsedTime;
    mStatisticsNumFrames += 1;

    if (mStatisticsUpdateTime >= sf::seconds(1.0f)){
        mStatisticsText.setString(
        "Frames / Second: " + std::to_string(mStatisticsNumFrames) + "\n" +
        "Time / Update: " + std::to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + " us\n" +
        "Asteroid Speed: " + std::to_string((int)asteroid.getSpeed()));

        mStatisticsUpdateTime -= sf::seconds(1.0f);
        mStatisticsNumFrames = 0;
    }
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