#include"Game.h"


int main()
{
	int number;
	cout << "How many ships do you want to put??" << endl;
	cin >> number;
	Game a(number);
	a.play();




	system("pause");

	return 0;
}