#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

enum class Mood { HAPPY, SAD, MAD, TIRED, ILL };

enum class Activity { IDLE, EAT, PET, SLEEP, WAKE_UP, BATH };

class Pet {
protected:
    sf::CircleShape petGraphic; // temporary
    Mood mood;
    Activity activity;
    sf::Color animation; // temporary type, same logic
    int level;
    int exp;
    int nextLevelExp;
    int age;
    
    int hunger;
    int energy;
    int hygiene;
    int attention;

    float activityTime;
    float activityDuration;
    float idleTime;
    float moodUpdate;
public:
    Pet();
    virtual ~Pet() = default;

    // getters
    sf::CircleShape getPetGraphic() const;
    Mood getMood() const;
    Activity getActivity() const;
    int getLevel() const;
    int getExp() const;
    int getNextLevelExp() const;
    int getAge() const;

    int getHunger() const;
    int getEnergy() const;
    int getHygiene() const;
    int getAttention() const;

    // setters
    virtual void setGraphic() = 0;
    void setMood(Mood m);

    // activity functions
    void feed();
    void sleep();
    void wake();
    void pet();
    void bath();

    // decay stats
    void decayHunger();
    void decayEnergy();
    void decayHygiene();
    void decayAttention();

    // TODO - animation functions

    void handleActivity(float dt);
    void handleMood(float dt);
    void update(float dt);
    void draw(sf::RenderWindow &window);

    // DEBUG TEXT UPDATE
    void debugText();

};