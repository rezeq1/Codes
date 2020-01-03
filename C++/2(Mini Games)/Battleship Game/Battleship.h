#ifndef _BATTLESHIP_H
#define _BATTLESHIP_H

#include<iostream>
#include<ctime>
using namespace std;

class Game;
class Battleship 
{
	int long1;
	static int c;//number of the ships that have puted
	friend class Game;

public:
	Battleship();
	void setlong1(int);
	int getlong1()const;
	static int getcount()
	{
		return c;
	}
};

#endif