#include <SFML/Graphics.hpp>

enum class Mood { HAPPY, SAD, MAD, TIRED, ILL };
enum class Animal { CAT, DOG, BIRD, HAMSTER, FOX, FISH, RABBIT};

class Pet {
private:
    sf::CircleShape petGraphic;
    Animal animal;
    Mood mood;
    int level;
    int exp;
    int nextLevelExp;
    int age;
    
    float hunger;
    float energy;
    float cleanliness;
    float attention;

    float moodBar;
public:
    Pet(float radius, Animal a);

    Animal getAnimal() const;
    Mood getMood() const;
    int getAge() const;
    float getHunger() const;
    float getEnergy() const;
    float getCleanliness() const;
    float getAttention() const;
    float getMoodBar() const;
};

