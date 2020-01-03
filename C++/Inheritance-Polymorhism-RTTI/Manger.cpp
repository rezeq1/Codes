#include "Manger.h"

bool Manger::Outstanding() const //check if the manger is Outstanding
{
	if (seniority > 4)
		return true;
	return false;
}

int Manger::GetSalary() const //get salary
{

	return 4500*3+ seniority*5;
}

Manger & Manger::operator=(const Manger &sec)//operator =
{

		seniority = sec.seniority;
		name = sec.name;
		family = sec.family;
		id = sec.id;
	
	return *this;

}

void Manger::print() const
{
	cout << "the information of the manger is " << endl;
	Worker::print();
}
