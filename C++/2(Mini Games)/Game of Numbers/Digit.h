#ifndef _DIGIT_H
#define _DIGIT_H




#include<iostream>
#include<ctime>
using namespace std;


class Digit {
	int value;

public:
	
Digit():value(0){}
bool Equal(const Digit &num)
{
	return num.value == value;
}

int GetValue()const//get the value
{
	return value;
}
void SetValue(int a)
{
	value = a;
}





};


#endif