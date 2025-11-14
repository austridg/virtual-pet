#include "Dog.h"
#include "Cat.h"
#include <iostream>
#include <SFML/System/Clock.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({200, 200}), "Window");

    sf::Clock clock;

    float showDebug;

    clock.start();

    Dog doggo;
    doggo.setGraphic();
    doggo.debugText();

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        float deltaTime = clock.restart().asSeconds(); // delta time

        doggo.update(deltaTime);
        if(showDebug >= 5.f) { doggo.debugText(); showDebug = 0.f; }
        showDebug += deltaTime;

        window.clear();
        doggo.draw(window);
        window.display();
    }
}