#include "Game.hpp"

const sf::Vector2f screenSize {1000, 700};

Game::Game():
mWindow(sf::VideoMode(screenSize.x, screenSize.y), "Deliver the package", sf::Style::Close),
mPlayer(),
mStatisticsText(),
mStatisticsNumFrames(0),
mStatisticsUpdateTime(),
mPlayerSpeed(300.f),
mPlayerCurrentSpeed(mPlayerSpeed),
textures(),
fonts(),
animation(),
keyManager(),
math(),
gasTank(),
asteroid()
{

    // Load resources
    textures.load(Textures::Spaceship, "res/entity/player/Spaceship1.png");
    textures.load(Textures::Asteroid, "res/entity/objects/asteroid.png");
    textures.load(Textures::SmallStar, "res/background/smallStar.png");
    textures.load(Textures::MedStar, "res/background/medStar.png");
    fonts.load(Fonts::Sansation, "res/fonts/Sansation.ttf");

    // Setup player
    mPlayer.setTexture(textures.get(Textures::Spaceship));
    animation.init(&textures.get(Textures::Spaceship), sf::Vector2u(2, 1), 0.2f); 
    mPlayer.setScale(4.f, 4.f);
    mPlayer.setPosition(screenSize.x / 2, screenSize.y / 2);
    // change 4 to (arraySize * 2)
    mPlayer.setOrigin(sf::Vector2f(mPlayer.getTexture()->getSize().x / 4, mPlayer.getTexture()->getSize().y / 4));

    asteroid.init(&textures.get(Textures::Asteroid));


    // Setup statistics text 
    mStatisticsText.setFont(fonts.get(Fonts::Sansation));
    mStatisticsText.setPosition(screenSize.x - 230, 10.f);
    mStatisticsText.setCharacterSize(20);

    // TODO: Setup stars
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



    sf::Vector2f movement(0.f, 0.f);

    // Player movement
    if (keyManager.up){
        movement.y -= mPlayerCurrentSpeed;
    }
    if (keyManager.down){
        movement.y += mPlayerCurrentSpeed;
    }
    if (keyManager.left){
        movement.x -= mPlayerCurrentSpeed;
    }
    if (keyManager.right){
        movement.x += mPlayerCurrentSpeed;
    }

    

    // Gauge functionality
    if (keyManager.boost && gasTank.getCurrentValue() >= 0) mPlayerCurrentSpeed += 3;
    else if (gasTank.getCurrentValue() <= gasTank.getMaxValue()) mPlayerCurrentSpeed = mPlayerSpeed;

    // Movement
    mPlayer.move(movement * elapsedTime.asSeconds());

    // Updates the animation
    animation.update(0, elapsedTime.asSeconds());
    mPlayer.setTextureRect(animation.uvRect);
}

void Game::render(){
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.draw(gasTank.getGasTank());
    mWindow.draw(*asteroid.getSprite());
    mWindow.draw(mStatisticsText);
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