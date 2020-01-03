#include "Worker.h"

void Worker::print() const
{
	Person::print();//print the name and id and her family name
	cout << "the seniority years is :  " << seniority << endl;
}

int Worker::GetSalary() const
{
	return 4500;
}

