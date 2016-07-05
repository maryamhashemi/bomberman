#ifndef BOMBERMAN_H
#define BOMBERMAN_H

#include "obstacles.h"
#include <iostream>
#include <string>
using namespace std;

class Bomberman
{
public:
    Bomberman(float X , float Y , int len , int wid);
    Bomberman();
    ~Bomberman();
    void setX(float X);
    void setY(float Y);
    void setIsExist();
    float getX();
    float getY();
    float getLength();
    float getWidth();
    bool getIsExist();
    bool collision(Wall wall);
    bool collision(Obstacles obs);
    bool collision(Bomberman *bomber);
    void move1(string data , Obstacles *obs  , Wall *wall , Bomberman *bomber );
    string move2(bool *move , Obstacles *obs  , Wall *wall , Bomberman *bomber);
    void operator = (Bomberman *bomber);

private:
        float x;
        float y;
        float length;
        float width;
        bool IsExist;
};

#endif // BOMBERMAN_H
