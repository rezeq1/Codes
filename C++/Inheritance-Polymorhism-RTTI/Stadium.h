#include"Manger.h"
class Team;
class Stadium
{
	int seats;  //number of the stadium seats
	string name_stadium;
	string town;
	friend class Team;
public:
	Stadium(string b="empty",string c="empty", int a = 0):seats(a),name_stadium(b),town(c){} //ctor and def ctor
	~Stadium(){}
	void print()const; //print the stadium details
	Stadium& operator=(const Stadium&);//operator =


};
