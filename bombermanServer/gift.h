#ifndef GIFT_H
#define GIFT_H

#include "bomberman.h"
#include "timer.h"
#include "SFML/Audio.hpp"

class Gift
{
public:
    Gift(float X,float Y);
    ~Gift();
    void setX(float X);
    void setY(float Y);
    void setIsExist(bool Is);
    float getX();
    float getY();
    float getLength();
    float getWidth();
    bool getIsExist();
    bool collision(Bomberman* bomber);
    bool getGift(Bomberman *bomber);
    
private:
    float x;
    float y;
    float length;
    float width;
    bool IsExist;

};

#endif // GIFT_H
