#include "timer.h"


Timer::Timer(int milliseconds , int seconds  , int minute )
{
	this->milliseconds = milliseconds;
    this->seconds = seconds;
    this->minute = minute;
    
    if (!font.loadFromFile("timerfont.ttf"))
	{
		// handle error
	}
		
    Tseconds.setFont(font);
	Tseconds.setCharacterSize(40);
	Tseconds.setColor(sf::Color::White);
	Tseconds.setPosition(645,10);
	
	Tminute.setFont(font);
	Tminute.setCharacterSize(40);
	Tminute.setColor(sf::Color::White);
	Tminute.setPosition(600,10);
	
	charachter.setFont(font);
	charachter.setCharacterSize(40);
	charachter.setColor(sf::Color::White);
	charachter.setString(":");
	charachter.setPosition(630,10);
	
}

Timer::~Timer()
{

}

void Timer::handletime()
{
	
	if(milliseconds == 10)
	{
		seconds++;
		milliseconds = 0;
	}
    if(seconds == 60)
    {
        minute++;
        seconds = 0;
    }
    
    Sseconds = Tostring(seconds);
    Sminute =  Tostring(minute);
    
	Tseconds.setString(Sseconds);
	Tminute.setString(Sminute);
	
    milliseconds ++;
    usleep(1000);
}

string Timer::Tostring(int integer)
{
	stringstream ss;
	ss << integer;
	string str = ss.str();
	return str;
}	

void Timer::setMilliseconds(int m)
{
	milliseconds = m;
}

void Timer::setSeconds(int s)
{
    seconds = s;
}

void Timer::setMinute(int m)
{
    minute = m;
}

int Timer::getMilliseconds()
{
	return milliseconds;
}

int Timer::getSeconds()
{
    return seconds;
}

int Timer::getMinute()
{
    return minute;
}

sf::Text Timer::getSecondsText()
{
	return Tseconds;
}

sf::Text Timer::getMinuteText()
{
	return Tminute;
}

sf::Text Timer::getCharchter()
{
	return charachter;
}



