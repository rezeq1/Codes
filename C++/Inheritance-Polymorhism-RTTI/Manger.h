#include"Referee.h"

 class Team;
class Manger :public Worker
{
protected:
	friend class Team;
public:
	Manger(int d = 0, string a = "empty", string b = "empty", string c = "empty"):Worker(d,a,b,c){}//ctor and def ctor
	~Manger(){}//dtor
	bool Outstanding()const;//check if the manger is Outstanding
	int GetSalary()const;//to get salary of the manger
	Manger& operator=(const Manger&);//operator =
	void print()const;//to print the manger information

};
