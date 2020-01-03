#include<string>
#include"Date.h"
#include<assert.h>

class Student
{
	string name;
	string family;
	Date BornDate;
	string id;
	int Quantity_Marks;
	float average;

public:
	Student(string, string, Date, string, int, float);//ctor
	Student();//def ctor
	bool operator >(const Student&)const;//opeartor > to check if the average of the right student is bigger than the left one
	friend ostream& operator <<(ostream&, const Student &);//opeartor cout
	bool operator ==(const Student&)const;//to check if the two student have the same id

};
