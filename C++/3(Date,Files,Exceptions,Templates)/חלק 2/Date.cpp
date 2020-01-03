#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

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

ostream& operator<<(ostream & out,const Date & sec)//operator print
{
	return out << sec.GetDay() << "/" << sec.GetMonth() << "/" << sec.GetYear();

}
