#include "SFML/Graphics.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>

const int Window_size_x = 450;
const int Window_size_y = 800;

int firstNumber[8] = {-2,-2,-2,-2,-2,-2,-2,-2}; // -1 is decimal, -2 is blank
unsigned int firstNumberDigitIndex = 0;
bool firstNumDecFlag = false;

double outputNumber = 0.0;

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

void print_array() {

    std::cout << ""
        << "{" << firstNumber[0] << "," << firstNumber[1] << "," << firstNumber[2] << ","
        << firstNumber[3] << "," << firstNumber[4] << "," << firstNumber[5] << ","
        << firstNumber[6] << "," << firstNumber[7] << "}\n";
    return;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({ Window_size_x, Window_size_y}), "Basic C++ Calculator");
	sf::RectangleShape background({Window_size_x, Window_size_y});
    sf::RectangleShape output_background({ Window_size_x, Window_size_y - (Window_size_y - 00) });
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
    Button button_clear(num_button_offset * 4 + button_width * 3, Window_size_y - 220, button_width, button_height, "CLEAR", 50);

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

            static bool mouseStatusLastFrame = false;
            bool mouseStatusCurFrame = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);

            if (event->is<sf::Event::Closed>())
                window.close();
            
            if (!mouseStatusLastFrame && mouseStatusCurFrame)
            {
                sf::Vector2i position = sf::Mouse::getPosition(window);
                sf::Mouse::setPosition(sf::Vector2i(position.x, position.y), window);

                if (button_one.isButtonClicked(position)) {
                    firstNumber[firstNumberDigitIndex] = 1;
                    if (firstNumberDigitIndex <= 7) {
                        firstNumberDigitIndex++;
                    }
                    print_array();
                    
                }
                else if (button_two.isButtonClicked(position)) {
                    firstNumber[firstNumberDigitIndex] = 2;
                    if (firstNumberDigitIndex <= 7) {
                        firstNumberDigitIndex++;
                    }
                    print_array();
                    
                }
                else if (button_three.isButtonClicked(position)) {
                    firstNumber[firstNumberDigitIndex] = 3;
                    if (firstNumberDigitIndex <= 7) {
                        firstNumberDigitIndex++;
                    }
                    print_array();
                    
                }
                else if (button_four.isButtonClicked(position)) {
                    firstNumber[firstNumberDigitIndex] = 4;
                    if (firstNumberDigitIndex <= 7) {
                        firstNumberDigitIndex++;
                    }
                    print_array();
                    
                }
                else if (button_five.isButtonClicked(position)) {
                    firstNumber[firstNumberDigitIndex] = 5;
                    if (firstNumberDigitIndex <= 7) {
                        firstNumberDigitIndex++;
                    }
                    print_array();
                    
                }
                else if (button_six.isButtonClicked(position)) {
                    firstNumber[firstNumberDigitIndex] = 6;
                    if (firstNumberDigitIndex <= 7) {
                        firstNumberDigitIndex++;
                    }
                    print_array();
                    
                }
                else if (button_seven.isButtonClicked(position)) {
                    firstNumber[firstNumberDigitIndex] = 7;
                    if (firstNumberDigitIndex <= 7) {
                        firstNumberDigitIndex++;
                    }
                    print_array();
                    
                }
                else if (button_eight.isButtonClicked(position)) {
                    firstNumber[firstNumberDigitIndex] = 8;
                    if (firstNumberDigitIndex <= 7) {
                        firstNumberDigitIndex++;
                    }
                    print_array();
                    
                }
                else if (button_nine.isButtonClicked(position)) {
                    firstNumber[firstNumberDigitIndex] = 9;
                    if (firstNumberDigitIndex <= 7) {
                        firstNumberDigitIndex++;
                    }
                    print_array();
                    
                }
                else if (button_decimal.isButtonClicked(position)) {
                    if (firstNumDecFlag == false) {
                        firstNumber[firstNumberDigitIndex] = -1;
                        if (firstNumberDigitIndex <= 7) {
                            firstNumberDigitIndex++;
                        }
                    }
                    firstNumDecFlag = true;
                    print_array();
                    
                }
                else if (button_equal.isButtonClicked(position)) {

                    if      ((firstNumber[7] == -2) && (firstNumber[6] == -2) && (firstNumber[5] == -2) && (firstNumber[4] == -2) && (firstNumber[3] == -2) && (firstNumber[2] == -2) && (firstNumber[1] == -2) && (firstNumber[0] != -2)) {
                        // 1
                        outputNumber = (firstNumber[0] * 1);
                    }
                    else if ((firstNumber[7] == -2) && (firstNumber[6] == -2) && (firstNumber[5] == -2) && (firstNumber[4] == -2) && (firstNumber[3] == -2) && (firstNumber[2] == -2) && (firstNumber[1] != -2) && (firstNumber[0] != -2)) {
                        // 1 + 10
                        outputNumber =  (firstNumber[1] * 1) + (firstNumber[0] * 10);
                    }
                    else if ((firstNumber[7] == -2) && (firstNumber[6] == -2) && (firstNumber[5] == -2) && (firstNumber[4] == -2) && (firstNumber[3] == -2) && (firstNumber[2] != -2) && (firstNumber[1] != -2) && (firstNumber[0] != -2)) {
                        // 1 + 10 + 100
                        outputNumber = (firstNumber[2] * 1) + (firstNumber[1] * 10) + (firstNumber[0] * 100);
                    }
                    else if ((firstNumber[7] == -2) && (firstNumber[6] == -2) && (firstNumber[5] == -2) && (firstNumber[4] == -2) && (firstNumber[3] != -2) && (firstNumber[2] != -2) && (firstNumber[1] != -2) && (firstNumber[0] != -2)) {
                        // 1 + 10 + 100 + 1000
                        outputNumber = (firstNumber[3] * 1) + (firstNumber[2] * 10) + (firstNumber[1] * 100) + (firstNumber[0] * 1000);
                    }
                    else if ((firstNumber[7] == -2) && (firstNumber[6] == -2) && (firstNumber[5] == -2) && (firstNumber[4] != -2) && (firstNumber[3] != -2) && (firstNumber[2] != -2) && (firstNumber[1] != -2) && (firstNumber[0] != -2)) {
                        // 1 + 10 + 100 + 1,000 + 10,000
                        outputNumber = (firstNumber[4] * 1) + (firstNumber[3] * 10) + (firstNumber[2] * 100) + (firstNumber[1] * 1000) + (firstNumber[0] * 10000);
                    }
                    else if ((firstNumber[7] == -2) && (firstNumber[6] == -2) && (firstNumber[5] != -2) && (firstNumber[4] != -2) && (firstNumber[3] != -2) && (firstNumber[2] != -2) && (firstNumber[1] != -2) && (firstNumber[0] != -2)) {
                        // 1 + 10 + 100 + 1,000 + 10,000 + 100,000
                        outputNumber = (firstNumber[5] * 1) + (firstNumber[4] * 10) + (firstNumber[3] * 100) + (firstNumber[2] * 1000) + (firstNumber[1] * 10000) + (firstNumber[0] * 100000);
                    }
                    else if ((firstNumber[7] == -2) && (firstNumber[6] != -2) && (firstNumber[5] != -2) && (firstNumber[4] != -2) && (firstNumber[3] != -2) && (firstNumber[2] != -2) && (firstNumber[1] != -2) && (firstNumber[0] != -2)) {
                        // 1 + 10 + 100 + 1,000 + 10,000 + 100,000 + 1,000,000
                        outputNumber = (firstNumber[6] * 1) + (firstNumber[5] * 10) + (firstNumber[4] * 100) + (firstNumber[3] * 1000) + (firstNumber[2] * 10000) + (firstNumber[1] * 100000) + (firstNumber[0] * 1000000);
                    }
                    else if ((firstNumber[7] != -2) && (firstNumber[6] != -2) && (firstNumber[5] != -2) && (firstNumber[4] != -2) && (firstNumber[3] != -2) && (firstNumber[2] != -2) && (firstNumber[1] != -2) && (firstNumber[0] != -2)) {
                        // 1 + 10 + 100 + 1,000 + 10,000 + 100,000 + 1,000,000 + 10,000,000
                        outputNumber = (firstNumber[7] * 1) + (firstNumber[6] * 10) + (firstNumber[5] * 100) + (firstNumber[4] * 1000) + (firstNumber[3] * 10000) + (firstNumber[2] * 100000) + (firstNumber[1] * 1000000) + (firstNumber[0] * 10000000);
                    }


                    std::cout << outputNumber << "\n";
                }
                else if (button_clear.isButtonClicked(position)) {
                    for (size_t i = 0; i < 8; i++)
                    {
                        firstNumber[i] = -2;
                    }
                    firstNumberDigitIndex = 0;
                    outputNumber = 0.0;
                    print_array();
                }
               
            }


            mouseStatusLastFrame = mouseStatusCurFrame;
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
        button_clear.drawButton(window);
        window.draw(output_background);

        window.display();
    }

    
}

double calculate() {


    return outputNumber;
}



