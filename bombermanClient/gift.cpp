#include "gift.h"

Gift::Gift(float X,float Y)
{
    x = X;
    y = Y;
    length = 63;
    width = 63;
    IsExist = 1;
}
Gift::~Gift()
{
}

void Gift::setX(float X)
{
        x = X;
}

void Gift::setY(float Y)
{
        y = Y;
}

void Gift::setIsExist(bool Is)
{
	IsExist = Is;
}

float Gift::getX()
{
        return x;
}

float Gift::getY()
{
        return y;
}

float Gift::getLength()
{
        return length;
}

float Gift::getWidth()
{
        return width;
}

bool Gift::getIsExist()
{
	return IsExist;
}

bool Gift::collision(Bomberman* bomber)
{
	if(y + width <= bomber->getY())
                return 0;
        if(x + length <= bomber->getX())
                return 0;
        if(y >= bomber->getY() + bomber->getWidth())
                return 0;
        if(x >= bomber->getX() + bomber->getLength())
                return 0;
        return 1; 
}

bool Gift::getGift(Bomberman *bomber )
{
	sf::Music gift;
	if (!gift.openFromFile("gift.wav")) {}
	
	if(collision(bomber) && IsExist == 1)
	{
		gift.play();
		IsExist=0;
		return 1;
	}	
	
	return 0;
}

