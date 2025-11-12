#include "Cat.h"

Cat::Cat()
    : Pet() {
        petGraphic = sf::CircleShape(100.f);
    }

void Cat::setGraphic() {
    if (activity != Activity::IDLE) { animation = sf::Color::White; return; }

    switch(mood) {
        case Mood::HAPPY:
            animation = sf::Color::Yellow;
            break;
        case Mood::SAD:
            animation = sf::Color::Blue;
            break;
        case Mood::MAD:
            animation = sf::Color::Red;
            break;
        case Mood::TIRED:
            animation = sf::Color::White;
            break; 
        case Mood::ILL:
            animation = sf::Color::Green;
            break;
    }

    petGraphic.setFillColor(animation);
}