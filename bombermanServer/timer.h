#ifndef TIMER_H
#define TIMER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <sstream>
//#include <windows.h>
#include <unistd.h>


using namespace std;

class Timer
{
public:
    Timer(int milliseconds , int seconds  , int minute);
    ~Timer();
    void handletime();
    string Tostring(int integer);
    void setMilliseconds(int m);
    void setSeconds(int s);
    void setMinute(int m);
    int getMilliseconds();
    int getSeconds();
    int getMinute();
    sf::Text getSecondsText();
    sf::Text getMinuteText();
    sf::Text getCharchter();
    
private:
	int milliseconds;
    int seconds;
    int minute;
    string Sseconds;
    string Sminute; 
    sf::Text Tseconds;
	sf::Text Tminute;
	sf::Text charachter;
	sf::Font font;
	
};

#endif // TIMER_H
