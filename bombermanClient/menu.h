#ifndef MENU_H
#define MENU_H
#define MAX_NUMBER_OF_ITEMS 3
#include "bomb.h"

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"

class Menu
{
	
public:
	Menu(float width , float height);
    ~Menu();
    void draw(sf::RenderWindow *window);
    void drawInstruct(sf::RenderWindow *window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex;}
   
private:
    int selectedItemIndex;
    sf::Font font;
    sf::Font font1;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Text instruction[16];

};

#endif // MENU_H
