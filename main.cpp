#include <SFML/Graphics.hpp>

enum class Mood { HAPPY, SAD, MAD, TIRED, ILL };

class Pet {
private:
    sf::CircleShape petGraphic(float radius);
    float hunger;
    int age;
    float energy;
    float clean;

    float happiness;
public:
    Pet(float radius);

    float getHunger() const;
};

