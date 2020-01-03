#include"Footballer.h"

class Team;
class Coach :public Worker
{
	string group_name;
	bool IsPlayer;  //if the coach was player in the past
	int Championships;  //number of the Championships
	friend class Team;
public:
	Coach(string f = "empty", bool x = false, int e = 0, int d = 0, string c = "empty",string a = "empty", string b = "empty");//ctor and def ctor
	~Coach() {}
	int GetSalary()const;
	bool Outstanding()const; //check if the coach is Outstanding
	void print()const; //print coach referee
	Coach& operator=(const Coach&);//operator =
};
