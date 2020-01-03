#include<iostream>
#include"tree.h"
using namespace std;


//---------------------------MAIN--------------------------------------------------
int main() {
	tnode<int> *n1 = new tnode<int>(3);
	tnode<int> *n2 = new tnode<int>(-1);
	tnode<int> *n3 = new tnode<int>(8, n2, n1);
	tnode<int> *n4 = new tnode<int>(4);
	tnode<int> *n5 = new tnode<int>(6, n3, n4);


	cout << "\npreorder: ";
	n5->preorder();
	cout << "\ninorder: ";
	n5->inorder();
	cout << "\npostorder: ";
	n5->postorder();

	cout << "height = " << n5->depth() << endl;
	cout << "is Perfect ? " << n5->isPerfect() << endl;
	cout << "is Complete ? " << n5->isComplete();
	getchar();

	return 0;
} //main



