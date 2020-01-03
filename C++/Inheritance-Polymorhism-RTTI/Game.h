#include"Team.h"
class Ligat_HaAl;

class Game
{
	Date *date_;  //the date of the game
	Team *team1, *team2;
	string name_winer;
	int gools_team1, gools_team2;  // number of the team gools
	Referee **referee_;   //arrray of referee
	int num_referee;
	bool InFuture()const;   //if the game is in the future
	friend class Ligat_HaAl;

public:
	~Game();//dtor
	Game();  //def ctor
	void AddReffer(Referee&); //to add  a new reffer to the array 
	void AddGool(string); //to add gool
	void print()const; //to print game details
	
	


};
