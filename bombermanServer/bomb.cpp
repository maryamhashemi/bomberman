#include "bomb.h"
#include <string>
using namespace std;

Bomb::Bomb(float X , float Y)
{
    x  = X;
    y  = Y;
}

Bomb::Bomb()
{
}

Bomb::~Bomb()
{
}

void Bomb::setX(float X)
{
        x = X;
}

void Bomb::setY(float Y)
{
        y = Y;
}

float Bomb::getX()
{
        return x;
}

float Bomb::getY()
{
        return y;
}

void Bomb::shoot1(string data , Bomberman *bomber , Timer *bombtimer)
{
	if(data == "Shoot")
	{
		setX(bomber->getX());
		setY(bomber->getY());	
		bombtimer->setSeconds(0);	
	}						
}

string Bomb::shoot2(Bomberman *bomber , Timer *bombtimer)
{
	string data = "Shoot";
	setX(bomber->getX());
	setY(bomber->getY());	
	bombtimer->setSeconds(0);	
	return data;						
}

void Bomb::explode(Obstacles* obs , Bomberman *bomber1 , Bomberman *bomber2)
{
	/*sf::Music b;
	if (!b.openFromFile("bomb.wav")) {}
	
	b.play();*/
	
	int i=0;
	int j=0;
	int ii[3];
	int jj[3];
	
	while(i!=1320)
	{
		if(x+22.5 >=i && x+22.5 <i+63)
		{
			ii[0]=i-66;
			ii[1]=i+66;
			ii[2]=i;
			
			break;
		}	
		i+=66;
	}	
		
	while(j!=792)
	{	
		if(y+22.5>=j && y+22.5<j+63)
		{
			jj[0]=j-66;
			jj[1]=j+66;
		    jj[2]=j;

			break;
		}	
		j+=66;
	}
	
	for(int k=0 ; k<56 ; k++)
	{
		for(int m=0 ; m<2 ;m++)
		{
			if(obs[k].getX()==ii[m] && obs[k].getY()==jj[2])
				obs[k].setIsExist();
			if(obs[k].getX()==ii[2] && obs[k].getY()==jj[m])
				obs[k].setIsExist();
		}	
	}	
	
	
	Bomberman *bomber = new Bomberman[2]();
	bomber[0] = bomber1;
	bomber[1] = bomber2;
	
	
	for( int k=0 ; k<2 ; k++)
	{
			for(int m=0 ; m<2 ; m++)
			{
					if(bomber[k].getY() + bomber[k].getWidth() <= jj[2])
							break;
					if(bomber[k].getX() + bomber[k].getLength() <= ii[m])
							break;
					if(bomber[k].getY() >= jj[2] + 66)
							break;
					if(bomber[k].getX() >= ii[m] + 66)
							break;
					if(k==0)
							bomber1->setIsExist();
					if(k==1)
							bomber2->setIsExist();
			}
     }  
         
    for( int k=0 ; k<2 ; k++)
	{
			for(int m=0 ; m<2 ; m++)
			{
					if(bomber[k].getY() + bomber[k].getWidth() <= jj[m])
							break;
					if(bomber[k].getX() + bomber[k].getLength() <= ii[2])
							break;
					if(bomber[k].getY() >= jj[m] + 66)
							break;
					if(bomber[k].getX() >= ii[2] + 66)
							break;
					if(k==0)
							bomber1->setIsExist();
					if(k==1)
							bomber2->setIsExist();
			}
     }
     
     
    for( int k=0 ; k<2 ; k++)
	{
			
		if(bomber[k].getY() + bomber[k].getWidth() <= jj[2])
				break;
		if(bomber[k].getX() + bomber[k].getLength() <= ii[2])
				break;
		if(bomber[k].getY() >= jj[2] + 66)
				break;
		if(bomber[k].getX() >= ii[2] + 66)
				break;
		if(k==0)
			bomber1->setIsExist();
		if(k==1)
			bomber2->setIsExist();	
     }
     
}


void Bomb::explodeGift(Obstacles* obs , Bomberman *bomber1 , Bomberman *bomber2)
{
	
	/*sf::Music b;
	if (!b.openFromFile("bomb.wav")) {}
	
	b.play();*/
	
	int i=0;
	int j=0;
	int ii[3];
	int jj[3];
	
	
	
	while(i!=1320)
	{
		if(x+22.5 >=i && x+22.5 <i+63)
		{
			ii[0]=i-66;
			ii[1]=i;
			ii[2]=i+66;
			break;
		}	
		i+=66;
	}	
		
	while(j!=792)
	{	
		if(y+22.5>=j && y+22.5<j+63)
		{
			jj[0]=j-66;
		    jj[1]=j;
			jj[2]=j+66;

			break;
		}	
		j+=66;
	}
	
	for(int k=0 ; k<56 ; k++)
	{
		for(int m=0 ; m<3 ; m++)
		{
			for(int n=0 ; n<3 ; n++)
			{
				if(obs[k].getX()==ii[m] && obs[k].getY()==jj[n])
					obs[k].setIsExist();
			}
		}	
	}
	
	Bomberman *bomber = new Bomberman[2]();
	bomber[0] = bomber1;
	bomber[1] = bomber2;
	
		
	for( int k=0 ; k<2 ; k++)
	{
		for(int m=0 ; m<3 ; m++)
		{
			for(int n=0 ; n<3 ; n++)
			{
					if(bomber[k].getY() + bomber[k].getWidth() <= jj[n])
							break;
					if(bomber[k].getX() + bomber[k].getLength() <= ii[m])
							break;
					if(bomber[k].getY() >= jj[n] + 66)
							break;
					if(bomber[k].getX() >= ii[m] + 66)
							break;
					if(k==0)
							bomber1->setIsExist();
					if(k==1)
							bomber2->setIsExist();
			}
		}			
     }  	

}
