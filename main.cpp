#include "Pet.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({200, 200}), "Window");
    Pet pet(100,Animal::CAT);
    pet.setGraphicMood(sf::Color::Blue);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(pet.getPetGraphic());
        window.display();
    }
}