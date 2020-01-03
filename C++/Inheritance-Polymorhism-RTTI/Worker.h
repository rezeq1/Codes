#include"Person.h"
class Ligat_HaAl;
class Worker:public Person
{
protected:
	int seniority;

	friend class Ligat_HaAl;
public:
	Worker(int d = 0, string a = "empty", string b = "empty", string c = "empty") :Person(a, b, c), seniority(d) {}//ctor and def ctor
	virtual ~Worker(){}//dtor
	void print()const;//virtual function to print
	virtual int  GetSalary()const;//to get the salary of worker


};
