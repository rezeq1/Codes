#include<iostream>
#include<time.h>
using namespace std;
class Team;
class Date {
private:
	int day, month, year;
friend class Team;
public:
	Date(); //def ctor to set the current  date
	Date(int, int, int); //ctor 
	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);
	int GetDay()const;
	int GetMonth()const;
	int GetYear()const;
	void PrintDate();
	void PrintMonthName();
	int MonthDaysNum();
	bool operator >(const Date&)const; //check if the other date is later than the date of *this
};
