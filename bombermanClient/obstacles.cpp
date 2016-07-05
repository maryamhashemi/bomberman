#include "obstacles.h"

Obstacles::Obstacles(float X,float Y ):Wall(X , Y )
{
    isExist = 1 ;
}

Obstacles::~Obstacles()
{

}

void Obstacles::setIsExist()
{
	isExist=0;
}

bool Obstacles::getISExist()
{
	return isExist;
}
