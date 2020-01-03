#include"Person.h"

Person::Person(const Person &sec)//copy ctor
{
	name = sec.name;
	id = sec.id;
	family = sec.family;
}

string Person::GetId() const
{
	return id;
}

void Person::print() const
{
	cout << "the name is :  " << name << endl << "the family is:  " << family << endl << "her id is:  " << id << endl;
}


