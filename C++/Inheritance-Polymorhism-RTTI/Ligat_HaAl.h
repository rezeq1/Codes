#include"Game.h"
#include<typeinfo>

class Ligat_HaAl
{
	Team** teams_liga;  //the teams of the liga
	Game** games_liga;   // the games of the liga
	Worker** workers_liga;  //the liga workers
	int num_workers;	 //number of the liga workers
	void GiveId()const;		// to give the footballers in the liga a differnt id
	void GiveMangerCoach()const; //to add to every team a manger and coach with differnt id
	void SetWorkers()const; //to set the footballers and the coachs and the mangers to the ligaa's workers
	void AddReferee(string, string, string, int); // to add a new referee to the liga workers
	int ReturnPoints(string);  //to return the points of the team
	void PrintChoises()const;  // to print the Menu choises 
	string PrintRoles()const;  // to print the roles of the footballer to  choose one of them
	bool IsFound(string)const; //if this id found in the workers of the liga
	void help_Footballer(Footballer); // to add a new footballer to the workers liga
public:
	Ligat_HaAl(); //def ctor
	~Ligat_HaAl(); //dtor
	void Menu();
};