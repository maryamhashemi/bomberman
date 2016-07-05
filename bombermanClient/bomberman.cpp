#include "bomberman.h"



Bomberman::Bomberman(float X , float Y , int len , int wid){
    x = X;
    y = Y;
    length = len;
    width = wid;
    IsExist = 1;
}

Bomberman::Bomberman()
{
}

Bomberman::~Bomberman()
{
}

void Bomberman::setX(float X)
{
        x = X;
}

void Bomberman::setY(float Y)
{
        y = Y;
}

void Bomberman::setIsExist()
{
        IsExist = 0;
}

float Bomberman::getX()
{
        return x;
}

float Bomberman::getY()
{
        return y;
}
float Bomberman::getLength()
{
        return length;
}

float Bomberman::getWidth()
{
        return width;
}

bool Bomberman::getIsExist()
{
	return IsExist;
}

bool Bomberman::collision(Wall wall)
{
        if(y + width <= wall.getY())
                return 0;
        if(x + length <= wall.getX())
                return 0;
        if(y >= wall.getY() + wall.getWidth())
                return 0;
        if(x >= wall.getX() + wall.getLength())
                return 0;
        return 1;   
}

bool Bomberman::collision(Obstacles obs)
{
	
		if(obs.getISExist()==0)
				return 0;
        if(y + width <= obs.getY())
                return 0;
        if(x + length <= obs.getX())
                return 0;
        if(y >= obs.getY() + obs.getWidth())
                return 0;
        if(x >= obs.getX() + obs.getLength())
                return 0;
        return 1;
      
}

bool Bomberman::collision(Bomberman *bomber)
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

void Bomberman::move1(string data  , Obstacles *obs  , Wall *wall  , Bomberman *bomber)
{
	
		if( data  == "Right" )
		{
			setX(getX()+7);
			for(int i=0 ; i<56 ; i++)
			{
				if(collision(wall[i]) || collision(obs[i]) || collision(bomber) || getX()<=63 || getX()>=1263 || getY()<=63 || getY()>=735 )
						setX(getX()-7);  
			}
			
		}
		
		if( data  == "Up" )
		{
			 setY(getY()-7);
             for(int i=0 ; i<56 ; i++)
			 {
					if(collision(wall[i]) || collision(obs[i]) || collision(bomber) || getX()<=63 || getX()>=1263 || getY()<=63 || getY()>=735) 
						setY(getY()+7);
             }  
              
		}
		
		if( data  == "Left" )
		{
			setX(getX()-7);
            for(int i=0 ; i<56 ; i++)
			{
					if(collision(wall[i]) || collision(obs[i]) || collision(bomber) || getX()<=63 || getX()>=1263 || getY()<=63 || getY()>=735)
							setX(getX()+7);
            }
            
		}
		
		if( data  == "Down" )
		{
			setY(getY()+7);
            for(int i=0 ; i<56 ; i++)
			{
					if(collision(wall[i]) || collision(obs[i]) || collision(bomber) || getX()<=63 || getX()>=1263 || getY()<=63 || getY()>=735) 
								setY(getY()-7);
            }  
             
		}
}


string Bomberman::move2(bool *move , Obstacles *obs  , Wall *wall  , Bomberman *bomber)
{
	string data  = " " ;
	
		if(move[0])
		{
			setX(getX()+7);
			for(int i=0 ; i<56 ; i++)
			{
				if(collision(wall[i]) || collision(obs[i]) || collision(bomber) || getX()<=63 || getX()>=1263 || getY()<=63 || getY()>=735)
						setX(getX()-7);  
			}
			
			data = "Right";
		}		
			
		
		if(move[1])
		{
			 setY(getY()-7);
             for(int i=0 ; i<56 ; i++)
			 {
					if(collision(wall[i]) || collision(obs[i]) || collision(bomber) || getX()<=63 || getX()>=1263 || getY()<=63 || getY()>=735) 
						setY(getY()+7);
             }  
              
			data = "Up";
		}
		
		if(move[2])
		{
			setX(getX()-7);
            for(int i=0 ; i<56 ; i++)
			{
					if(collision(wall[i]) || collision(obs[i]) || collision(bomber) || getX()<=63 || getX()>=1263 || getY()<=63 || getY()>=735)
							setX(getX()+7);
            }
            
			data = "Left";
		}
		
		if(move[3])
		{
			setY(getY()+7);
            for(int i=0 ; i<56 ; i++)
			{
					if(collision(wall[i]) || collision(obs[i]) || collision(bomber) || getX()<=63 || getX()>=1263 || getY()<=63 || getY()>=735) 
								setY(getY()-7);
            }    
            
			data = "Down";
		}
		
		return data;
}

void Bomberman::operator = (Bomberman *bomber)
{
	x = bomber->getX();
	y = bomber->getY();
	length = bomber->getLength();
	width = bomber->getWidth();
	IsExist = bomber->getIsExist();
}
