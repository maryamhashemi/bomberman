#ifndef WALL_H
#define WALL_H

class Wall
{
public:
    Wall(float X,float Y);
    ~Wall();
    void setX(float X);
    void setY(float Y);
    float getX();
    float getY();
    float getLength();
    float getWidth();

private:
        float x;
        float y;
        float length;
        float width;
};

#endif // WALL_H
