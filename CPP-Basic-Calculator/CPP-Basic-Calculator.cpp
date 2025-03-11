#include "SFML/Graphics.hpp"
#include <SFML/Graphics/Text.hpp>
#include <iostream>

const int Window_size_x = 450;
const int Window_size_y = 800;

class Button {
private:
    sf::RectangleShape button;
    sf::Text text_input;
    sf::Font font_type;

public:
    Button(float x_chord, float y_chord, float button_width, float button_height, const std::string& button_text, const int font_size)

        : text_input(font_type, "", 20)
    {
        
        if (!font_type.openFromFile("Fonts/SAOUI-Regular.otf"))
            std::cerr << "Font not found.\n";
    
        button.setPosition(sf::Vector2f(x_chord, y_chord));
        button.setSize(sf::Vector2f(button_width, button_height));
        button.setFillColor(sf::Color(0xA0, 0xA0, 0xA0));

        text_input.setFont(font_type);
        text_input.setString(button_text);
        text_input.setCharacterSize(font_size);
        text_input.setFillColor(sf::Color::Black);

        text_input.setPosition(sf::Vector2f(x_chord, y_chord)); // set text location to center of button.
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
    sf::RectangleShape output_background({ Window_size_x, Window_size_y - (Window_size_y - 200) });
	background.setFillColor(sf::Color(0x80, 0x80, 0x80));
    output_background.setFillColor(sf::Color(0xA0, 0xA0, 0xA0));
    
    const int num_button_offset = 10;
    const float button_width = 100.0;
    const float button_height = 100.0;

    Button button_sign(num_button_offset, Window_size_y - 110, button_width, button_height, "+/-", 50);
    Button button_zero(num_button_offset * 2 + button_width, Window_size_y - 110, button_width, button_height, "0", 50);
    Button button_decimal(num_button_offset * 3 + button_width * 2, Window_size_y - 110, button_width, button_height, ".", 50);
    Button button_equal(num_button_offset * 4 + button_width * 3, (Window_size_y - 110), button_width, button_height, "=", 50);

    Button button_one(num_button_offset, Window_size_y - 220, button_width, button_height, "1", 50);
    Button button_two(num_button_offset * 2 + button_width, Window_size_y - 220, button_width, button_height, "2", 50);
    Button button_three(num_button_offset * 3 + button_width * 2, Window_size_y - 220, button_width, button_height, "3", 50);

    Button button_four(num_button_offset, (Window_size_y - 320) - num_button_offset, button_width, button_height, "4", 50);
    Button button_five(num_button_offset * 2 + button_width, (Window_size_y - 320) - num_button_offset, button_width, button_height, "5", 50);
    Button button_six(num_button_offset * 3 + button_width * 2, (Window_size_y - 320) - num_button_offset, button_width, button_height, "6", 50);

    Button button_seven(num_button_offset, (Window_size_y - 420) - num_button_offset * 2, button_width, button_height, "7", 50);
    Button button_eight(num_button_offset * 2 + button_width, (Window_size_y - 420) - num_button_offset * 2, button_width, button_height, "8", 50);
    Button button_nine(num_button_offset * 3 + button_width * 2, (Window_size_y - 420) - num_button_offset * 2, button_width, button_height, "9", 50);

    Button button_multi(num_button_offset, (Window_size_y - 530) - num_button_offset * 2, button_width, button_height, "X", 50);
    Button button_divide(num_button_offset * 2 + button_width, (Window_size_y - 530) - num_button_offset * 2, button_width, button_height, "/", 50);
    Button button_add(num_button_offset * 3 + button_width * 2, (Window_size_y - 530) - num_button_offset * 2, button_width, button_height, "+", 50);
    Button button_subtract(num_button_offset * 4 + button_width * 3, (Window_size_y - 530) - num_button_offset * 2, button_width, button_height, "-", 50);




    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

		window.draw(background);
        button_sign.drawButton(window);
        button_zero.drawButton(window);
        button_decimal.drawButton(window);
		button_one.drawButton(window);
        button_two.drawButton(window);
        button_three.drawButton(window);
        button_four.drawButton(window);
        button_five.drawButton(window);
        button_six.drawButton(window);
        button_seven.drawButton(window);
        button_eight.drawButton(window);
        button_nine.drawButton(window);
        button_multi.drawButton(window);
        button_divide.drawButton(window);
        button_add.drawButton(window);
        button_subtract.drawButton(window);
        button_equal.drawButton(window);
        window.draw(output_background);






        window.display();
    }
}

