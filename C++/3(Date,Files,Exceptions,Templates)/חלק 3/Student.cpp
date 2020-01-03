#include "Student.h"

Student::Student(string name, string family, Date BornDate, string id, int Quantity_Marks, float average)//ctor
{
	int size = id.length();
	if (size != 9)//check if the lenght of the id is differnt than 9
		throw string("Error lenght of id is not 9");
	else
		this->id = id;

	this->name = name;

	this->family = family;

	if (BornDate.GetDay() > 31 || BornDate.GetDay() <= 0)//check if the day is illegal
		throw string("number of days is out of range");
	else {
		if (BornDate.MonthDaysNum() < BornDate.GetDay())//check if the days of the month is illegal
			throw string("number of days is not suitable to the month");
		else {
			if (BornDate.GetMonth() > 12 || BornDate.GetMonth() <= 0)//check if the month is illegal
				throw string("number of month is out of range");
			else {
				if (BornDate.GetYear() < 0)
					throw string("Error year can't be a nigative number");//check if the year is illegal
				else
					this->BornDate = BornDate;
			}
		}
	}


	if (Quantity_Marks < 0)//check if the Quantity of Marks is illigal
		throw string("error number of marks can not be negitave ");
	else {
		this->Quantity_Marks = Quantity_Marks;
		if (average < 0)//check if the average is illigal
			throw string("error average can not be negitave ");
		else {
			if (Quantity_Marks = 0 && average != 0)//check if the quantity of marks is zero so average should be zero
				throw string("error if number of marks is zero so the average shold be zero");
			else
				this->average = average;
		}
	}

}

Student::Student()//def ctor
{
	name = "Unknow";
	family = "Unknow";
	id = "000000000";
	Quantity_Marks = 0;
	average = 0;

}
bool Student::operator >(const Student & sec) const//opeartor > to check if the average of the right student is bigger than the left one
{
	if (average > sec.average)
		return true;
	return false;
}

bool Student::operator==(const Student &sec) const//to check if the two student have the same id
{
	if (sec.id == id)
		return true;
	return false;
}

ostream& operator<<(ostream& out, const Student &sec)//opeartor cout
{
	out << "the name is : " << sec.name << endl;
	out << "her family name is : " << sec.family << endl;
	out << " her born date is : ";
	sec.BornDate.PrintDate();
	out << endl;
	out << "her id is: : " << sec.id << endl;
	out << "her Quantity of Marks is :  " << sec.Quantity_Marks << endl;
	out << "her average is : " << sec.average << endl;
	return out;
}