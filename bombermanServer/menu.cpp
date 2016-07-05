#include "menu.h"
#include <iostream>

Menu::Menu(float width , float height)
{
    if (!font.loadFromFile("kitten.swash-monoline.ttf"))
    {
         // handle error
    }
   if (!font1.loadFromFile("2.ttf"))
    {
         // handle error
    }
   
    menu[0].setFont(font);
    menu[0].setCharacterSize(40);
    menu[0].setColor(sf::Color::Black);
    menu[0].setString("How to Play");
    menu[0].setPosition(sf::Vector2f((width / 2)-110, (height /3)-35));

    menu[1].setFont(font);
    menu[1].setCharacterSize(40);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Play");
    menu[1].setPosition(sf::Vector2f((width / 2)-50, (height /2)+10));

    menu[2].setFont(font);
    menu[2].setCharacterSize(40);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f((width / 2)-40, (height/2)+210));

   for(int i = 0; i<10; i++)
    {
       instruction[i].setFont(font1);
       instruction[i].setCharacterSize(30);
       instruction[i].setColor(sf::Color::White);
       instruction[i].setPosition(sf::Vector2f((width / 3)-340 , height /3+(30*i)-100));
    }
      for(int i = 10; i<16; i++)
    {
       instruction[i].setFont(font1);
       instruction[i].setCharacterSize(30);
       instruction[i].setColor(sf::Color::Red);
       instruction[i].setPosition(sf::Vector2f((width / 3)-340 , height /3+(30*i)-100));
    }
    instruction[0].setString("HOW TO PLAY THIS GAME Bomberman s goal is to reach the surface of the earth.");
    instruction[1].setString("However, his initial point of departure is deep in the bowel in the earth,so"); 
    instruction[2].setString("Bomberman must search for exitways and make his way upwards.");
    instruction[3].setString("BOMBS- In the earliest stage of the game, only one bomb can be set at a time");
    instruction[4].setString("and it has very weak firepower.");
    instruction[5].setString("BRICK- These dissolve when hit by the flames of exploding bombs.");
    instruction[6].setString("Hidden within the bricks are exitways and power-up panels,");
    instruction[7].setString("so it is wise to bomb out as many bricks as possible.");
    instruction[8].setString("CONCRETE- Concrete walls arenot damaged by bomb fires,");
    instruction[9].setString("so Bomberman can take shelter from exploding bombs.");
    instruction[10].setString("CONTROL FUNCTIONS:");
    instruction[11].setString("UP - Moves Bomberman up");
    instruction[12].setString("RIGHT - Moves Bomberman right");
    instruction[13].setString("LEFT - Moves Bomberman left");
    instruction[14].setString("DOWN - Moves Bomberman down");
    instruction[15].setString("SPACE- Lays down a bomb");
    
    selectedItemIndex=0;

}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow *window)
{
	sf::Texture texture11;
    if(!texture11.loadFromFile("menu.png")){}
    sf::Sprite sprite11(texture11);
    window->draw(sprite11);
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
            window->draw(menu[i]);
    }
}

void Menu::drawInstruct(sf::RenderWindow *window)
{ 
	sf::Texture texture22;
    if(!texture22.loadFromFile("how.png")){}
    sf::Sprite sprite22(texture22);
    window->draw(sprite22);
	for(int i = 0 ; i<16 ; i++)
	{
		window->draw(instruction[i]);
    } 
  
}

void Menu::MoveUp()
{
        if (selectedItemIndex - 1 >= 0)
        {
                menu[selectedItemIndex].setColor(sf::Color::White);
                selectedItemIndex--;
                menu[selectedItemIndex].setColor(sf::Color::Black);
        }
}

void Menu::MoveDown()
{
        if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
        {
                menu[selectedItemIndex].setColor(sf::Color::White);
                selectedItemIndex++;
                menu[selectedItemIndex].setColor(sf::Color::Black);
        }
}

