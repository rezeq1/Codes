
#include"Digit.h"
class Game;

class Number
{
	Digit array[4];
	bool CheckRet(int);//checkin if the number have a same digits
	int power(int)const;//to calcualte the number with power 10

	friend class Game;


public:
	Number();
void SetNumber(int);
void Randomaly();//get a random number 
void Print()const;
int GetDigit(int)const;//return the digit of the requested index



};
