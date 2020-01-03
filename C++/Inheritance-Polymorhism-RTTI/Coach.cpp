#include "Coach.h"

Coach::Coach(string f, bool x, int e, int d, string a, string b, string c):Worker(d,b,c,a)//def ctor and ctor
{
	group_name = f;
	IsPlayer = x;
	Championships = e;
}

int Coach::GetSalary() const //get salary
{
	int  basis = 4500, x = seniority;
	return basis + 200 * x + 500 * Championships;

}

bool Coach::Outstanding() const //check if the coach is Outstanding
{
	if (Championships >= 2)
		return true;
	return false;
}

void Coach::print() const // print coach information
{
	Worker::print();
	cout << "the name of the group that he trains  is:  " << group_name << endl;
	cout << "her salary is : " << GetSalary() << endl;
	if (IsPlayer == true)
		cout << "he was footballer in the past" << endl;
	else
		cout << "he was not footballer" << endl;
	cout << "The number of the championships is " << Championships << endl;
}

Coach & Coach::operator=(const Coach &sec) //operator =
{
	if (&sec != this) //check if *this different from sec
	{
		group_name = sec.group_name;
		IsPlayer = sec.IsPlayer;
		Championships = sec.Championships;
		seniority = sec.seniority;
		name = sec.name;
		family = sec.family;
		id = sec.id;
	}
	return *this;
}
