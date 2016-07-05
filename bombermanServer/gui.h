#ifndef GUI_H
#define GUI_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "bomb.h"
#include "bomberman.h"
#include "obstacles.h"
#include "wall.h"
#include "menu.h"
#include "timer.h"
#include "gift.h"

class GUI
{
public:
    GUI();
    ~GUI();
    void drawBack();
    bool drawMenu(Menu *menu);
    sf::RenderWindow* getWindow();
    void drawWall(Wall *wall);
    void drawObs(Obstacles *obs);
    void drawBomber(Bomberman *bomber , bool isLeft);
    void drawBomb(Bomb *bomb);
    void drawTimer(Timer *timer);
    void drawGift(Gift *gift);
    void drawLoading();
    void drawGameover();
    void drawWin();

private:
  int monitorLength;
  int monitorWidth;

  float kLength;
  float kWidth;

  sf::RenderWindow* window;
  sf::Event event;
};

#endif // GUI_H
