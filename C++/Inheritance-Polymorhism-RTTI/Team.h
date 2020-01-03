#include "Stadium.h"
class Game;
class Ligat_HaAl;
class Team
{
	string name_team;
	Stadium* stadium_;
	Footballer** players;
	int num_players;
	Coach * coach_;
	Manger* manger_;
	bool IsManger; //if they are manger in the team
	friend class Game;
	friend class Ligat_HaAl;
public:
	
	Team(); // def ctor
	Team(Stadium);//ctor 
	Team(const Team&);//copy ctor
	~Team();//dtor
	
	void AddPlayer(Footballer *); // to add a new player to the team
	Footballer* ReturnPlayer(int);//to return the address of the player in the place index

	Stadium getStadium()const;//to get the team's stadium
	Manger getManger()const;//to get the team's Manger
	Coach getCoach() const;//to get the team's coach

	void AddManger(Manger *);//to add manger to the team
	void AddCoach(Coach *);//to add coach to the team
	void print()const;//print the team's details
	Team& operator =(const Team&);//operator =
	Footballer& operator  [](int)const;//to return the player in the place index
	
};
