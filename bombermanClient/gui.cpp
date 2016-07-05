#include "gui.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "bomb.h"
#include "bomberman.h"
#include "obstacles.h"
#include "wall.h"
#include "menu.h"


GUI:: GUI()
{
    monitorLength = 1383;
    monitorWidth = 855;

    window = new sf::RenderWindow(sf::VideoMode(monitorLength, monitorWidth), "Bomberman");
    
}

GUI::~GUI()
{

}

 sf::RenderWindow* GUI::getWindow()
 {
     return window ;
 }

 bool GUI::drawMenu(Menu *menu)
 {
	  sf::Music Menu;
	  sf::Music click;
	  sf::Music HowTo;
	  
	  if (!Menu.openFromFile("menu.wav")) {}
	  if (!click.openFromFile("click.WAV")) {}
	  if (!HowTo.openFromFile("howto.wav")) {}
	  
	  bool back=1;
	  Menu.play();
	  
             while (window->isOpen())
             {
                     sf::Event event;
                     

                     while (window->pollEvent(event))
                     {
                             switch (event.type)
                             {
                             case sf::Event::KeyReleased:
                                     switch (event.key.code)
                                     {
                                     case sf::Keyboard::Up:
                                             menu->MoveUp();
                                             break;

                                     case sf::Keyboard::Down:
                                             menu->MoveDown();
                                             break;
                                             
                                           

                                     case sf::Keyboard::Return:
											
											 Menu.stop();
											 

                                             switch (menu->GetPressedItem())
                                             {
                                             case 0:
                                             {
												    HowTo.play();
													back=0;
													while(!back)
													{
														window->clear();
														menu->drawInstruct(window);
														window->display();
														sf::Event event1;
														while (window->pollEvent(event1))
														{
															if(event1.type == sf::Event::KeyPressed) 
															{
																if(event1.key.code==sf::Keyboard::Escape)
																{
																	HowTo.stop();
																	Menu.play();
																	back=1;
																	
																}	
															}
														}
													}
													 
                                                     
                                                     break;
											  }
                                             case 1:  
                                                   return 1;

                                             case 2:
                                                     window->close();
                                                     return 0;
                                                     break;
                                             }

                                             break;
                                     }

                                     break;
                             case sf::Event::Closed:
                                     window->close();
									 return 0;
                                     break;

                             }
                     }
					if(back)
					{
						 window->clear();
						 menu->draw(window);
						 window->display();
					}
             }
 }
 
 void GUI::drawBack()
  {
	  sf::Texture texture1;
      if (!texture1.loadFromFile("back.png")){}
      sf::Sprite sprite1(texture1);
      window->draw(sprite1);
  }

 void GUI::drawWall(Wall *wall)
 {
    for(int i=0 ; i < 110 ; i++)
    {
        sf::Texture texture2;
        if (!texture2.loadFromFile("wall.png")){}
        sf::Sprite sprite2(texture2);
        sprite2.setPosition(sf::Vector2f(wall[i].getX(), wall[i].getY()));
        window->draw(sprite2);
    }
  }
  
  void GUI::drawObs(Obstacles *obs)
  {
	    for(int i=0 ; i<56 ; i++)
	    {
			if(obs[i].getISExist()==1)
			{
				sf::Texture texture3;
				if (!texture3.loadFromFile("obs.png")){}
				sf::Sprite sprite3(texture3);
				sprite3.setPosition(sf::Vector2f(obs[i].getX(), obs[i].getY()));
				window->draw(sprite3);
			}
	    }
  }

  void GUI::drawBomber(Bomberman *bomber , bool isLeft)
  {
    if(isLeft)
    {	if(bomber->getIsExist()==1)
		{
			sf::Texture texture4;
			if (!texture4.loadFromFile("bomber1.png")){}
			sf::Sprite sprite4(texture4);
			sprite4.setPosition(sf::Vector2f(bomber->getX(), bomber->getY()));
			window->draw(sprite4);
		}	
    }
    else
    {
		if(bomber->getIsExist()==1)
		{
			sf::Texture texture5;
			if (!texture5.loadFromFile("bomber2.png")){}
			sf::Sprite sprite5(texture5);
			sprite5.setPosition(sf::Vector2f( bomber->getX() , bomber->getY()));
			window->draw(sprite5);
		}
    }
    
  }

  void GUI::drawBomb(Bomb *bomb)
  {
        sf::Texture texture6;
        if (!texture6.loadFromFile("bomb.png")){}
        sf::Sprite sprite6(texture6);
        sprite6.setPosition(sf::Vector2f(bomb->getX(), bomb->getY()));
        window->draw(sprite6);
       
  }
  
  void GUI::drawTimer(Timer *timer)
  {
		timer->handletime();
		window->draw(timer->getSecondsText());
		window->draw(timer->getCharchter());
		window->draw(timer->getMinuteText());	
  }
  
 void GUI::drawGift(Gift *gift)
 {  
	 for(int i = 0 ; i<6 ; i++)
	 {
		 if(gift[i].getIsExist()==1)
		 {
			sf::Texture texture7;
			if (!texture7.loadFromFile("giftp.png")){}
			sf::Sprite sprite7(texture7);
			sprite7.setPosition(sf::Vector2f(gift[i].getX(), gift[i].getY()));
			window->draw(sprite7);
		}
	}	
 }
 
  void GUI::drawLoading()
  {
	  sf::Texture texture8;
      if (!texture8.loadFromFile("loading.png")){}
      sf::Sprite sprite8(texture8);
      window->draw(sprite8);
  }
  
   void GUI::drawGameover()
  {
	  sf::Texture texture9;
      if (!texture9.loadFromFile("gameover.png")){}
      sf::Sprite sprite9(texture9);
      window->draw(sprite9);
  }
   void GUI::drawWin()
  {
	  sf::Texture texture12;
      if (!texture12.loadFromFile("winner.png")){}
      sf::Sprite sprite12(texture12);
      window->draw(sprite12);
  }	 
