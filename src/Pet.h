#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

enum class Mood { HAPPY, SAD, MAD, TIRED, ILL };

enum class Activity { IDLE, EAT, PET, SLEEP, WAKE_UP, BATH };

enum class Animation { 
    HAPPY_ANIMATE, 
    SAD_ANIMATE, 
    MAD_ANIMATE, 
    TIRED_ANIMATE, 
    ILL_ANIMATE,
    EAT_ANIMATE,
    SLEEP_ANIMATE,
    WAKE_ANIMATE,
    PET_ANIMATE,
    BATH_ANIMATE
};
enum class Animal { CAT, DOG, BIRD, HAMSTER, FOX, FISH, RABBIT};

class Pet {
private:
    sf::CircleShape petGraphic; // temporary
    Animal animal;
    Mood mood;
    Activity activity;
    Animation animation;
    int level;
    int exp;
    int nextLevelExp;
    int age;
    
    int hunger;
    int energy;
    int hygiene;
    int attention;

    int moodBar;
public:
    Pet(int radius, Animal a);

    // getters
    sf::CircleShape getPetGraphic() const;
    Animal getAnimal() const;
    Mood getMood() const;
    int getLevel() const;
    int getExp() const;
    int getNextLevelExp() const;
    int getAge() const;

    int getHunger() const;
    int getEnergy() const;
    int getHygiene() const;
    int getAttention() const;

    int getMoodBar() const;

    // setters
    void setGraphicMood(sf::Color color);

    // increment stats
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
};