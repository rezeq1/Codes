#include<iostream>
#include<time.h>
using namespace std;


class Date {

	int day, month, year;

public:
	Date();//def ctor
	Date(int, int, int);//ctor
	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);
	int GetDay()const;
	int GetMonth()const;
	int GetYear()const;
	Date operator =(const Date&);//operator =
	bool operator>(const Date&);//check if the right date bigger than the left date
	friend ostream& operator<<(ostream& out, const Date &sec);//print  a date
};