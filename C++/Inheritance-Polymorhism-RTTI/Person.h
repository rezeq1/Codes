#include"Date.h"
#include<string>
#include<assert.h>


class Person
{
protected: 

	string name;
	string family;
	string id;

public:
	Person(string a = "empty", string b = "empty", string c = "empty") :name(a), family(b), id(c) {}//ctor and def ctor
	
	Person(const Person&);//copy ctor
	virtual string GetId()const;//virtual function to get the id of the person

	virtual ~Person() {}//virtual dtor
	virtual void print()const;//virtual function to print the information
	virtual	bool Outstanding()const = 0;//pur virtiual function to show if person is outstandning

};
