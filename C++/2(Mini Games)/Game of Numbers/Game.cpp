
#include "Game.h"

int Game::Cow()const//calculate the cows
{
	int c = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((*user).GetDigit(j) == (*pc).GetDigit(i))
				c++;
		}
	}
	return c - Bull();
}
int Game::Bull()const//calculate the bulls
{
	int c = 0;
	for (int i = 0;i < 4;i++)
	{
		if ((*user).GetDigit(i) == (*pc).GetDigit(i))
			c++;
	}
	return c;
}
bool Game::CheckZero(int a)const//checking if the number have the digit 0
{
	if (a % 10 == 0 || (a / 10) % 10 == 0 || (a / 100) % 10 == 0)
		return true;
	else
		return false;
}



Game::Game()
{
	user = new Number;
	pc = new Number;
	for (int i = 0;i < 4;i++)
	{
		(*user).SetNumber(0);
		(*pc).SetNumber(0);

	}

}
Game::~Game()
{
	delete user;
	delete pc;
}

Game::Game(const Game& sec)//copy ctor
{

	user = new Number;
	pc = new Number;

	for (int i = 0;i < 4;i++)
	{
		(*user).array[i].SetValue(sec.user->GetDigit(i));
		(*pc).array[i].SetValue(sec.pc->GetDigit(i));
		
	}
}

void Game::Play()//the function to run the game
{
	(*pc).Randomaly();//give the pc a random number
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Hello,this is game 'Bulls and Cows'." << endl;
	cout << "The computer conceived 4-digits number (all digits are different,without '0')." << endl;
	cout << "Your task-guess it through numbers input." << endl;
	cout << "If the digit is identical, but it is at the other location - this is 'cow' (C)," << endl;
	cout << "if it is in the same place - would be 'bull' (B)." << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Number  B  C" << endl;
	cout << "------------" << endl;
	int numb;
	while (Bull() != 4)//checking if the user win
	{
		
			cin >> numb;
			(*user).SetNumber(numb);//insert a number from the user
			while ((*user).CheckRet(numb)==0||numb>9999||numb<999||CheckZero(numb)==1)//checking that the digits of the number is not a same without 0 
			{
				cout << "you have enter a wrong number please enter again" << endl;
				cin >> numb;
				(*user).SetNumber(numb);
			 }

		(*user).SetNumber(numb);
		cout << "        "<<Bull()<<"  "<<Cow()<<endl;

	}
	cout << "*********" << endl;
	cout << "you win!!" << endl;
	cout << "*********" << endl;

}
