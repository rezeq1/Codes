
#include "Number.h"

bool Number::CheckRet(int num)//checkin if the number have a same digits
{
	int count = 0, a, b, c, d;
	a = num % 10;
	b = (num / 10) % 10;
	c = (num / 100) % 10;
	d = num / 1000;
	int ar[] = { a,b,c,d };


	for (int i = 0;i < 3;i++)
		for (int j = i+1;j < 4;j++)
			if (ar[i] == ar[j])
				count++;

	if (count>0)
		return false;
	else
		return true;
}

int Number::power(int a)const//to calcualte the number with power 10
{
	int c = 1;
	for (int i = 0;i < a;i++)
		c *= 10;
	return c;
}




Number::Number()
{
	for (int i = 0; i < 4; i++)
		array[i].SetValue(0);
}

void Number::SetNumber(int a)
{
	for (int i = 0; i < 4; i++)
	{
			array[i].SetValue(a % 10);
		a /= 10;
	}
}

void Number::Randomaly()//get a random number
{
	int c, number = 0;
	srand(time(NULL));
	do {
		number=0;
		for (int i = 0; i < 4; i++)
		{
			c = rand() % 9 + 1;
			number += (c * 1000) / power(i);
			array[3 - i].SetValue(c);
		}
		
	} while (CheckRet(number)!=1);
	{

	}
	
}

int Number::GetDigit(int a)const//return the digit of the requested index
{
	if (a >= 0 && a <= 3)
		return array[a].GetValue();

		return -1;
}

void Number::Print()const//print the number
{
	for(int i=3;i>=0;i--)
		cout<<array[i].GetValue();
	cout << endl;
}

