#include <SFML/Graphics.hpp>
#include <iostream>

const int Window_size_x = 500;
const int Window_size_y = 800;

class Button {
private:
    sf::RectangleShape button;
    sf::Text text_input;
    sf::Font font_type;

public:
    Button(float x_chord, float y_chord, float button_width, float button_height, const std::string& button_text)
    {

        if (!font_type.openFromFile("SAOFont-Regular_v1.ttf"))
            std::cerr << "Font not found.\n";

        button.setPosition(sf::Vector2f(x_chord, y_chord));
        button.setSize(sf::Vector2f(button_width, button_height));
        button.setFillColor(sf::Color(0xA0, 0xA0, 0xA0));

        text_input.setFont(font_type);
        text_input.setString(button_text);
        text_input.setCharacterSize(20);
        text_input.setFillColor(sf::Color::Black);

        text_input.setPosition(sf::Vector2f(x_chord + (button_width/2), y_chord + (button_height / 2) ) ); // set text location to center of button.
    }

    void drawButton(sf::RenderWindow& window) {
        window.draw(button);
        window.draw(text_input);
    }

    bool isButtonClicked(sf::Vector2i cursorChords) {
        return button.getGlobalBounds().contains(static_cast<sf::Vector2f>(cursorChords)); // return true if cursor is within the bounds of the button.
    }

};

int main()
{
    sf::RenderWindow window(sf::VideoMode({ Window_size_x, Window_size_y}), "Basic C++ Calculator");
	sf::RectangleShape background({Window_size_x, Window_size_y});
	background.setFillColor(sf::Color(0x80, 0x80, 0x80));
    
    Button button(100, 100, 100, 100, "CHEESE");

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

