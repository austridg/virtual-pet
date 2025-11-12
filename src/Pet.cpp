#include "Pet.h"

Pet::Pet()
    : level(1), mood(Mood::HAPPY), activity(Activity::IDLE) {
        lifetime.start();
    }

// getters
sf::CircleShape Pet::getPetGraphic() const { return petGraphic; }
Mood Pet::getMood() const { return mood; }
Activity Pet::getActivity() const { return activity; }

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
void Pet::setMood(Mood m) { 
    mood = m;
}

// increment stats
void Pet::feed() {
    sf::Time startTime = lifetime.getElapsedTime(); // temp variable
    
    activity = Activity::EAT;
    setGraphic();

    // increment stats
    hunger += 5;
    if(hunger > 100) { hunger = 100; }

    // do animation for 5 seconds
    while(lifetime.getElapsedTime().asSeconds() - startTime.asSeconds() < 5) {}

    // reset
    activity = Activity::IDLE;
    setGraphic();
}

void Pet::sleep() {
}

