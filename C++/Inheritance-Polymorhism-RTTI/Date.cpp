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

void Date::PrintDate() {
	cout << day << "/" << month << "/" << year << endl;
}

void Date::PrintMonthName() {
	switch (month) {
	case 1:
		cout << "January" << endl;
		break;
	case 2:
		cout << "February" << endl;
		break;
	case 3:
		cout << "March" << endl;
		break;
	case 4:
		cout << "April" << endl;
		break;
	case 5:
		cout << "May" << endl;
		break;
	case 6:
		cout << "June" << endl;
		break;
	case 7:
		cout << "July" << endl;
		break;
	case 8:
		cout << "August" << endl;
		break;
	case 9:
		cout << "September" << endl;
		break;
	case 10:
		cout << "October" << endl;
		break;
	case 11:
		cout << "November" << endl;
		break;
	case 12:
		cout << "December" << endl;
		break;
	default:
		cout << "No month in number: " << month << "." << endl;
	}
}

int Date::MonthDaysNum() {
	int num;
	enum Month {
		January = 1, February, March, April, May, June,
		July, August, September, October, November, December
	};

	if ((month == January) || (month == March) || (month == May) || (month == July) || (month == August) || (month == October) || (month == December)) {
		num = 31;
	}
	if ((month == April) || (month == June) || (month == September) || (month == November)) {
		num = 30;
	}
	if (month == February) {
		num = 28;
	}
	return num;
}

bool Date::operator >(const Date &sec)const
{
	if (year>sec.GetYear())
		return true;
	else {
		if (month > sec.GetMonth())
			return true;
		else
			if (day > sec.GetDay())
				return true;
	}
	return false;
}
