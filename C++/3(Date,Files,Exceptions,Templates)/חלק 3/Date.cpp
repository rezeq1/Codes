#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

ostream& operator<<(ostream & out, const Date & sec)//operator print
{
	return out << sec.GetDay() << "/" << sec.GetMonth() << "/" << sec.GetYear();

}
bool Date::operator>(const Date & a)
{
	if (this->GetYear() > a.GetYear())//check if the right date bigger than the left date
		return true;
	else {
		if (this->GetMonth() > a.GetMonth())
			return true;
		else {
			if (this->GetDay() > a.GetDay())
				return true;
			else
				return false;
		}
	}
}

Date::Date() { //set the current date
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	day = timeinfo->tm_mday;
	month = timeinfo->tm_mon + 1;
	year = timeinfo->tm_year + 1900;
}

Date::Date(int day, int month, int year) :day(day), month(month), year(year) {}

void Date::SetDay(int d) {
	day = d;
}

void Date::SetMonth(int m) {
	month = m;
}

void Date::SetYear(int y) {
	year = y;
}

int Date::GetDay()const { return day; }

int Date::GetMonth()const { return month; }

int Date::GetYear()const { return year; }

void Date::PrintDate()const {
	cout << day << "/" << month << "/" << year;
}





int Date::MonthDaysNum() {
	int num;
	enum Month {
		January = 1, February, March, April, May, June,
		July, August, September, October, November, December
	};

	if ((month == January) || (month == March) || (month == May) || (month == July) || (month == August) || (month == October) || (month == December)) {
		return  31;
	}
	if ((month == April) || (month == June) || (month == September) || (month == November)) {
		return  30;
	}
	if (month == February) {
		return  28;

	}
}
Date Date::operator=(const Date & sec)//operator =
{
	if (this != &sec)
	{
		day = sec.day;
		month = sec.month;
		year = sec.year;
	}
	return *this;
}


