#include "Stack.h"

int main() {
	Stack first, second;
	for (int i = 10;i < 15;i++) {
		first += i;
		second += i;
	}
	cout << "First Stack:" << endl << first << "Second Stack:" << endl << second;
	if (first == second)
		cout << "the stacks are equals!" << endl;
	else
		cout << "the stacks are different !" << endl;
	first -= 1;
	second -= 3;
	cout << "After deleting :" << endl << "first stack:" << endl << first << "second stack:" << endl << second;
	if (first != second)
		cout << "the stacks are different !" << endl;
	else
		cout << "the stacks are equals !" << endl;
	cout << "Reverse form of the first stack :" << endl << !first;
	cout << "delete top from first stack:" << endl << (first -= 1);
	Stack third(first);
	first = second;
	cout << endl << "After assignment :" << endl << "First Stack :" << endl << first << "Second Stack :" << endl << second << endl;
	cout << "Third stack :" << endl << third;


	system("pause");
	return 0;
}