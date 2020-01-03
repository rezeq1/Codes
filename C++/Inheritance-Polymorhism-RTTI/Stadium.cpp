#include "Stadium.h"

void Stadium::print() const
{
	cout << "the name of the Stadium is :  " << name_stadium << endl;
	cout << "the name of the town's Stadium is :  " << town << endl;
	cout << "the number of the Stadium's seats is :  " << seats << endl;
}

Stadium & Stadium::operator=(const Stadium &sec)
{
	if (&sec != this)// check if this deffernt from sec address
	{
		
		seats = sec.seats;
		name_stadium = sec.name_stadium;
		town = sec.town;
	}
	return *this;
}
