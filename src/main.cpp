#include "Dog.h"
#include "Cat.h"
#include <iostream>
#include <SFML/System/Clock.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({200, 200}), "Window");

    sf::Clock clock;

    clock.start();

    clock.stop();

    Dog doggo;
    doggo.setGraphic();

    doggo.setMood(Mood::MAD);

    doggo.setGraphic();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float deltaTime = clock.restart().asSeconds(); // delta time

        doggo.setGraphic(deltaTime);

        window.clear();
        window.draw(doggo.getPetGraphic());
        window.display();
    }
}