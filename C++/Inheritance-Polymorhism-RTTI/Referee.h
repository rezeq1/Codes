#include "Coach.h"
class Game;
class Referee :public Worker
{
	int wrongs;
	int judged_games;
	static int Max_wrongs;
	friend class Game;
public:
	Referee(int e = 0, int f = 0, int d = 0, string a = "empty", string b = "empty", string c = "empty") :Worker(d, a, b, c)//ctor and def ctor
	{
		wrongs = e;
		judged_games = f;
	}
	~Referee(){}
	int GetSalary()const;
	 void print()const;
	void AddGames();//add her judged games number
	void AddWrongs(int);//to add wrongs to the referee
	bool Outstanding()const;//check if the referee is Outstanding

};
