#ifndef INPUT_KEYMANAGER_HPP
#define INPUT_KEYMANAGER_HPP

#include "SFML/Graphics.hpp"

class KeyManager{
    public:
        KeyManager();
        void keyInput(sf::Keyboard::Key key, bool isPressed);
        void update();

    private:
        bool keys[1000]{false};
    public:
        bool left, right, up, down, boost;

};

#endif