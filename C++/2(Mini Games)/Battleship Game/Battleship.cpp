#include "Battleship.h"

int Battleship::c = 0;

Battleship::Battleship()
{
	c++;
	switch (c)//the long of the ships by the question
	{
	case 1:
		long1 = 5;
		break;
	case 2:
		long1 = 4;
		break;
	case 3:
		long1 = 3;
		break;
	case 4:
		long1 = 2;
		break;
	case 5:
		long1 = 3;
		break;
	}
	
}

void Battleship::setlong1(int long_)
{
	long1 = long_;
}

int Battleship::getlong1()const
{
	return long1;
}
