#include "Pet.h"

Pet::Pet(float radius, Animal a)
    : petGraphic(radius), animal(a) {}

Animal Pet::getAnimal() const { return animal; }
Mood Pet::getMood() const { return mood; }
int Pet::getAge() const { return age; }
float Pet::getHunger() const { return hunger; }
float Pet::getEnergy() const { return energy; }
float Pet::getCleanliness() const { return cleanliness; }
float Pet::getAttention() const { return attention; }
float Pet::getMoodBar() const { return moodBar; }