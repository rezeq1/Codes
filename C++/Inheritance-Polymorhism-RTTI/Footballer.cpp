#include "Footballer.h"

Footballer::Footballer(string g ,string e, int f, int d, string a, string b, string c):Worker(d,a,b,c)//ctor and def ctor
{
	name_group = e;
	Gools = f;
	role = g;
}

Footballer::Footballer(const Footballer &sec)//copy ctor
{
	name_group = sec.name_group;
	Gools = sec.Gools;
	role = sec.role;
	name = sec.name;
	family = sec.family;
	id = sec.id;
	seniority = sec.seniority;



}

float Footballer::Percent_Success()const//get the Percent of Success
{
	float a;
	a = (float)Gools / num_games;
	a *= 100;
	return a;
}

bool Footballer::Outstanding() const//check if the footballer is Outstanding
{
	float x = Percent_Success();
	if (x > 75)
		return true;
	return false;
}

void Footballer::Scoring(int a) //to add the number of the footballer gools
{
	Gools += a;
}

int Footballer::GetSalary() const//to get the player salary
{
	float salary = 6500,flag;
	float x = Percent_Success();
	flag = (float)x / 100;
	salary += flag* 2000;

	return salary;
}

void Footballer::print() const//to print the footballer information
{
	Worker::print();
	cout << " the scoring gools of the player is " << Gools << endl;
	cout << " her Percent of Success is: " << Percent_Success() << endl;
	cout << " her salary is : " << GetSalary() << endl;
	cout << "her role is : " << role << endl;
}

Footballer & Footballer::operator=(const Footballer &sec)//operator =
{
	if (&sec != this)//check if is sec is not *this
	{
		name_group = sec.name_group;
		Gools = sec.Gools;
		role = sec.role;
		name = sec.name;
		family = sec.family;
		id = sec.id;
		seniority = sec.seniority;
	}


	return *this;
}
