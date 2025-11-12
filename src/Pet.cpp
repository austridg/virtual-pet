#include "Pet.h"

Pet::Pet()
    : level(1), mood(Mood::HAPPY), activity(Activity::IDLE) {
        lifetime.start();

        debugFont.loadFromFile("assets/fonts/arial.ttf");

        debugText.setFont(debugFont);
        debugText.setCharacterSize(12);
        debugText.setFillColor(sf::Color::White);
        debugText.setPosition(10.f, 10.f);
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

void Pet::handleActivity(float dt) {

    // check and incremenet activity time, if reaches limit, reset to IDLE activity
    // requires 2 new varaibles for Pet (activityTime,activityDuration)

}

void Pet::handleMood(float dt) {

    // check for mood changes every 1 second (or something)
    
    // update mood accoridingly based on current stats

}

void Pet::update(float dt) {

    // track idle time

    // decay stats over time

    // handle activity and handle mood

    // set graphic

    // update debug text

}

void Pet::draw(sf::RenderWindow &window) {
    window.draw(petGraphic);
    window.draw(debugText);
}

// DEBUG TEXT UPDATE
void Pet::updateDebugText() {
    debugText.setString(
        "Level: " + std::to_string(level) + "\n" +
        "Exp: " + std::to_string(exp) + "/" + std::to_string(nextLevelExp) + "\n" +
        "Age: " + std::to_string(age) + "\n" +
        "Hunger: " + std::to_string(hunger) + "\n" +
        "Energy: " + std::to_string(energy) + "\n" +
        "Hygiene: " + std::to_string(hygiene) + "\n" +
        "Attention: " + std::to_string(attention) + "\n" +
    );
}