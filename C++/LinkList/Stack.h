#include <iostream>
using namespace std;

class Stack {
	class Node {
		int value;
		Node *next;
	public:
		friend class Stack;
		Node(int num) :value(num), next(nullptr) {};//ctor
		Node(const Node&);//copy ctor
		friend ostream&operator<<(ostream&, const Stack&);//operator output of stack

	};
	Node *top;
	int size;
public:
	Stack() :top(nullptr), size(0) {};//def ctor
	Stack(const Stack&);//copy ctor
	~Stack();//dtor
	Stack& operator=(const Stack&);//operator =
	Stack& operator+=(int);//to add an integer to the stack
	Stack& operator-=(int);//to remove a quantity of values from the stack
	Stack& operator!();//to invert the values of the stack
	bool operator==(const Stack&)const;//to check if two stack have the same values with the same  order
	bool operator!=(const Stack&)const;//check if two stacks are different

	friend ostream&operator<<(ostream&, const Stack&);//operator output to print the values of the stack


};