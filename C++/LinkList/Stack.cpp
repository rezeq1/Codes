#include "Stack.h"


Stack &Stack::operator+=(int number) //to add an integer to the stack
{
	if (top == nullptr) {	//check if the stack is empty
		top = new Node(number);
		size=1;
	}
	else {
		Node *temp = new Node(number);//help object
		temp->next = top;
		top = temp;//put the node as a head of the stack
		size++;
	}
	return *this;
}


ostream &operator<<(ostream &output, const Stack &sec) {	//operator output to print the values of the stack
	Stack::Node *temp = sec.top;
		while (temp != nullptr) {		//check if we dont arrived to the end of the stack
			output << temp->value << endl;//print the value
			temp = temp->next;//to promote the stack to the next node
		}
	return output;
}

Stack::Node::Node(const Stack::Node &sec):value(sec.value) {//copy ctor
	if (sec.next == nullptr)
		next = nullptr;
	else
		next = new Node(*(sec.next));
}

Stack &Stack::operator-=(int quantity) {	//to remove a quantity of values from the stack
	if (quantity > size) {  ////to check if the quantity of values are illegal
		cout << "you have enterd Illegal quantity" << endl;
		return *this;
	}
	Node *temp = top;
	for (int i = 0;i < quantity;i++) {
		temp = top;
		top = temp->next;//to promote the stack to the next node
		delete temp;//remove the value
	}
	return *this;
}

bool Stack::operator==(const Stack &outher) const {	//to check if two stack have the same values with the same  order
	if (this->size == outher.size)
	{
		Node *temp = top;
		Node *temp_sec = outher.top;
		while (temp != nullptr) {		//check if we dont arrived to the end of the stack
			if (temp->value != temp_sec->value)
				return false;
			temp = temp->next;//to promote the stack1 to the next node
			temp_sec = temp_sec->next;//to promote the stack2 to the next node		
		}
		return true;
	}
	else
		return false;
}

Stack::~Stack() {
	Node *temp = top;
	while (top != nullptr) {//check if we dont arrived to the end of the stack
		temp = top;
		top = temp->next;//to promote the stack to the next node
		delete temp;//release memory
	}

}

bool Stack::operator!=(const Stack &sec) const {	//check if two stacks are different
	if ((*this) == sec)
		return false;
	return true;
}

Stack &Stack::operator=(const Stack &sec) {
	if (top != sec.top) {
		top = new Node(sec.top->value);
		Node *temp = top;
		Node *temp_sec = sec.top->next;

		while (temp_sec != nullptr) {		//check if we dont arrived to the end of the stack
			temp->next = new Node(temp_sec->value);
			temp= temp->next;		//to promote the stack to the next node
			temp_sec = temp_sec->next;
		}
	}
	return *this;
}

Stack &Stack::operator!() {		//to invert the values of the stack
	Stack temp;
	Node *temp2 = top;
	while (temp2 != nullptr) {			//check if we dont arrived to the end of the stack
		temp += temp2->value;			//using operator +=
		temp2 = temp2->next;			//to promote the stack to the next node
	}
	*this = temp;
	return *this;
}

Stack::Stack(const Stack &sec) {//copy ctor
	*this = sec;
}