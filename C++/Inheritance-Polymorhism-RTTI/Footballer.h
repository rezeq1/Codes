#include"Worker.h"
 class Team;
 class Game;
class Footballer:public Worker
{
	string name_group;
	int Gools;
	const int num_games = 8;
	string role;
	friend class Team;
	friend class Game;

public:
	Footballer(string g = "Back",string e = "empty", int f = 0,  int d = 0, string a = "empty", string b = "empty", string c = "empty");
	~Footballer(){}//dtor
	Footballer(const Footballer&);//copy dtor
	float Percent_Success()const;//to print the  Percent of Success to the footballer
	virtual	bool Outstanding()const;//check if the footballer is outstandning
	void Scoring(int);//to add to the player her scoring gool
	int GetSalary()const;//to get the player salary
	void print()const;//to print the footballer information
	Footballer& operator=(const Footballer&);// operator =
};
