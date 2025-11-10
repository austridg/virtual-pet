#include "Pet.h"

Pet::Pet(int radius, Animal a)
    : petGraphic(radius), animal(a), level(1), animation(Animation::HAPPY_ANIMATE), activity(Activity::IDLE) {}

// getters
sf::CircleShape Pet::getPetGraphic() const { return petGraphic; }
Animal Pet::getAnimal() const { return animal; }
Mood Pet::getMood() const { return mood; }
int Pet::getLevel() const { return level; }
int Pet::getExp() const { return exp; }
int Pet::getNextLevelExp() const { return nextLevelExp; }
int Pet::getAge() const { return age; }

int Pet::getHunger() const { return hunger; }
int Pet::getEnergy() const { return energy; }
int Pet::getHygiene() const { return hygiene; }
int Pet::getAttention() const { return attention; }

int Pet::getMoodBar() const { return moodBar; }

// setters
void Pet::setGraphicMood(sf::Color color) {
    petGraphic.setFillColor(color);
}

// increment stats
void Pet::feed() {
    animation = Animation::EAT_ANIMATE;

    hunger += 5;
    if(hunger > 100) { hunger = 100; }
}

void Pet::sleep() {
    animation = Animation::SLEEP_ANIMATE;
}

