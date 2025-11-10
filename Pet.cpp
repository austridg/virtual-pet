#include "Pet.h"

Pet::Pet(float radius, Animal a)
    : petGraphic(radius), animal(a), level(1) {}

Animal Pet::getAnimal() const { return animal; }
Mood Pet::getMood() const { return mood; }
int Pet::getLevel() const { return level; }
int Pet::getExp() const { return exp; }
int Pet::getNextLevelExp() const { return nextLevelExp; }
int Pet::getAge() const { return age; }

float Pet::getHunger() const { return hunger; }
float Pet::getEnergy() const { return energy; }
float Pet::getCleanliness() const { return cleanliness; }
float Pet::getAttention() const { return attention; }

float Pet::getMoodBar() const { return moodBar; }