#include "wall.h"

Wall::Wall(float X,float Y)
{
        x = X;
        y = Y;
        length = 63;
        width = 63;
}

Wall::~Wall()
{

}

void Wall::setX(float X)
{
        x = X;
}

void Wall::setY(float Y)
{
        y = Y;
}

float Wall::getX()
{
        return x;
}

float Wall::getY()
{
        return y;
}

float Wall::getLength()
{
        return length;
}

float Wall::getWidth()
{
        return width;
}
