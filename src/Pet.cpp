#include "Pet.h"
#include <iostream>
#include <map>

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

    if (moodUpdate < 1.f) {
        moodUpdate += dt;
        return;
    }

    moodUpdate = 0;

    // map of moods
    std::map <Mood, int> score {
        {Mood::HAPPY,0},
        {Mood::MAD,0},
        {Mood::SAD,0},
        {Mood::TIRED,0},
        {Mood::ILL,0}
    };

    // attention
    if (attention >= 20.f) { score[Mood::HAPPY] += 1; }
    else if (attention >= 10.f) { score[Mood::SAD] += 2; score[Mood::MAD] += 1; }
    else { score[Mood::SAD] += 3; score[Mood::MAD] += 2; }

    // hunger
    if (hunger >= 20.f) { score[Mood::HAPPY] += 1; }
    else if (hunger >= 15.f) { score[Mood::MAD] += 2; score[Mood::ILL] += 1; }
    else { score[Mood::MAD] += 1; score[Mood::ILL] += 3; }

    // energy
    if (energy >= 20.f) { score[Mood::HAPPY] += 1; }
    else if (energy >= 10.f) { score[Mood::TIRED] += 5; }
    else { score[Mood::TIRED] += 10; }

    // hygiene
    if (hygiene >= 20.f) { score[Mood::HAPPY] += 1; }
    else if (hygiene >= 15.f) { score[Mood::ILL] += 2; }
    else { score[Mood::ILL] += 4; }

    Mood chosenMood = Mood::HAPPY;
    int bestScore = -1;

    // find mood with highest score
    for (auto& x : score) {
        if(x.second > bestScore) {
            bestScore = x.second;
            chosenMood = x.first;
        }
    }

    mood = chosenMood;

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