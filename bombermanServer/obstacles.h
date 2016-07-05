#ifndef OBSTACLES_H
#define OBSTACLES_H
#include "wall.h"

class Obstacles : public Wall
{
public:
    Obstacles(float X,float Y );
    ~Obstacles();
    void setIsExist();
    bool getISExist();
   
private:
        bool isExist;
};

#endif // OBSTACLES_H
