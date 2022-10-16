#ifndef UTIL_KEYMANAGER_HPP
#define UTIL_KEYMANAGER_HPP

#include "../../lib/sfml/Graphics.hpp"

class KeyManager{
    public:
        KeyManager();
        void keyInput(sf::Keyboard::Key key, bool isPressed);
        void update();

    private:
        bool keys[5000]{false};
    public:
        bool left, right, up, down, boost;

};

#endif