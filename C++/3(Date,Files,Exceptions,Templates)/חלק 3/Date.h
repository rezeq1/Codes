#include<iostream>
#include<time.h>
using namespace std;


class Date {

	int day, month, year;
	
public:
	Date(); 
	Date(int, int, int);  
	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);
	int GetDay()const;
	int GetMonth()const;
	int GetYear()const;
	void PrintDate()const;
	int MonthDaysNum();
	Date operator =(const Date&);//opeartor =
	bool operator>(const Date&);//check if the right date bigger than the left date
	friend ostream& operator<<(ostream& out, const Date &sec);//print  a date
	
};
