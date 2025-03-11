#include "SFML/Graphics.hpp"
#include <iostream>

const int Window_size_x = 500;
const int Window_size_y = 800;

int main()
{
    sf::RenderWindow window(sf::VideoMode({ Window_size_x, Window_size_y}), "Basic C++ Calculator");
	sf::RectangleShape background({Window_size_x, Window_size_y});
	background.setFillColor(sf::Color(0x80, 0x80, 0x80));
    

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
		window.draw(background);
        window.display();
    }
}

