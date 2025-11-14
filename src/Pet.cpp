#include "Pet.h"
#include <iostream>

Pet::Pet()
    : level(1), exp(0), age(0), hunger(100.f), energy(100.f), hygiene(100.f), attention(100.f), mood(Mood::HAPPY), activity(Activity::IDLE), activityDuration(5.f) {}

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

// setters
void Pet::setMood(Mood m) { 
    mood = m;
}

// increment stats
void Pet::feed() {
    // // sf::Time startTime = lifetime.getElapsedTime(); // temp variable
    
    // activity = Activity::EAT;
    // setGraphic();

    // // increment stats
    // hunger += 5;
    // if(hunger > 100) { hunger = 100; }

    // // do animation for 5 seconds
    // while(lifetime.getElapsedTime().asSeconds() - startTime.asSeconds() < 5) {}

    // // reset
    // activity = Activity::IDLE;
    // setGraphic();
}

void Pet::handleActivity(float dt) {
    if (activity != Activity::IDLE) {
        if (activityTime >= activityDuration) {
            activity = Activity::IDLE;
            activityTime = 0.f;
        } else {
            activityTime += dt;
        }
    }
}

void Pet::handleMood(float dt) {

    // OMG - REFACTOR THIS IS SO BAD
    if (moodUpdate >= 1.f) {
        int happy{};
        int sad{};
        int mad{};
        int tired{};
        int ill{};

        if (attention >= 10.f && attention < 20.f) { sad += 2; mad += 1; }
        else if (attention < 10.f) { sad += 3; mad += 2; }
        else { happy += 1; }

        if (hunger >= 15.f && hunger < 20.f) { mad += 2; ill += 1; }
        else if (hunger < 15.f) { mad += 1; ill += 3; }
        else { happy += 1; }

        if (energy >= 10.f && energy < 20.f) { tired += 5; }
        else if (energy < 10.f) { tired += 10; }
        else { happy += 1; }

        if (hygiene >= 15.f && hygiene < 20.f) { ill += 2; }
        else if (hygiene < 15.f) { ill += 4; }
        else { happy += 1; }

        if (happy > sad + mad + tired + ill) { mood = Mood::HAPPY; }
        else if (sad > happy + tired + ill + mad) { mood = Mood::SAD; }
        else if (mad > happy + sad + tired + ill) { mood = Mood::MAD; }
        else if (tired > happy + sad + mad + ill) { mood = Mood::TIRED; }
        else { mood = Mood::ILL; }
    }

    moodUpdate += dt;

}

void Pet::update(float dt) {

    if (activity == Activity::IDLE) { idleTime += dt; }

    hunger -= 0.4 * dt;
    if (hunger < 0) { hunger = 0; }

    attention -= 0.5 * dt;
    if (attention < 0) { attention = 0; }

    hygiene -= 0.2 * dt;
    if (hygiene < 0) { hygiene = 0; }

    energy -= 0.3 * dt;
    if (energy < 0) {energy = 0; }

    age += 0.1 * dt;

    // TODO - Leveling Function

    handleActivity(dt);
    handleMood(dt);

    setGraphic();

}

void Pet::draw(sf::RenderWindow &window) {
    window.draw(petGraphic);
}

// DEBUG TEXT UPDATE (LEVEL, EXP, AGE, HUNGER, ENERGY, HYGIENE, ATTENTION)
void Pet::debugText() {
    std::cout << "================================\n";
    std::cout << "LEVEL: " << level << std::endl;
    std::cout << "EXP: " << exp << std::endl;
    std::cout << "AGE: " << age << std::endl;
    std::cout << "HUNGER: " << hunger << std::endl;
    std::cout << "ENERGY: " << energy << std::endl;
    std::cout << "HYGIENE: " << hygiene << std::endl;
    std::cout << "ATTENTION: " << attention << std::endl;
    std::cout << "================================\n";
}