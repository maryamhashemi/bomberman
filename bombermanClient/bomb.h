#ifndef BOMB_H
#define BOMB_H
#include "bomberman.h"
#include "timer.h"
#include "SFML/Audio.hpp"

class Bomb
{
public:
    Bomb(float X ,float Y);
    Bomb();
    ~Bomb();
    void setX(float X);
    void setY(float Y);
    float getX();
    float getY();
    void shoot1(string data , Bomberman *bomber , Timer *bombtimer);
    string shoot2(Bomberman *bomber , Timer *bombtimer);
	void  explode(Obstacles* obs , Bomberman *bomber1 , Bomberman *bomber2);
	void  explodeGift(Obstacles* obs , Bomberman *bomber1 , Bomberman *bomber2);


private:
     float x;
     float y;
};

#endif // BOMB_H
