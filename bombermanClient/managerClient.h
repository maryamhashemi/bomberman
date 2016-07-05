#ifndef MANAGERCLIENT_H
#define MANAGERCLIENT_H
#include "gui.h"
#include "Client.h"
#include "SocketException.h"
#include <iostream>
#include <string>

class ManagerClient
{
public:
    ManagerClient();
    ~ManagerClient();
    int getWorldWidth();
    Menu *getMenu();
    Wall *getWall();
    Obstacles *getObs();
    Gift *getGift();
    Bomberman *getBomber1();
    Bomberman *getBomber2();
    Bomb *getBomb();
    void run();


private:
   GUI *gui ;
   Menu *menu ;
   Wall *wall ;
   Obstacles *obs ;
   Bomberman *bomber1 ;
   Bomberman *bomber2 ;
   Bomb *bomb1 ;
   Bomb *bomb2 ; 
   Timer *timer;
   Timer *bomb1timer;
   Timer *bomb2timer;
   Gift *gift;
   
   float WorldLength;
   float WorldWidth;
};

#endif // MANAGERCLIENT_H
