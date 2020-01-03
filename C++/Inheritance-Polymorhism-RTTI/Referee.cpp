#include "Referee.h"

int Referee::GetSalary()const//get salary
{
	int a;
	a = 4500 + 30 * judged_games;
	if (wrongs > Max_wrongs)
		return a - 500;
	else
	return a;
}

void Referee::print() const //print referee information
{
	Worker::print();
	cout << "the judged wrong's games is :  " << wrongs << endl;
	if (wrongs == Max_wrongs)
		cout << "he has the maximum errors " << endl;
	cout << "her salary is : " << GetSalary() << endl;
	cout << endl;

}

void Referee::AddGames() //add her judged games number
{
	judged_games ++ ;
}

void Referee::AddWrongs(int a) //add wrongs (error)
{
	wrongs += a;
	if (wrongs > Max_wrongs)
		Max_wrongs = wrongs;
}

bool Referee::Outstanding() const// check if the referee is outstanding
{
	if (wrongs < Max_wrongs / 2)
		return true;
	return false;
}

int Referee::Max_wrongs = 0;