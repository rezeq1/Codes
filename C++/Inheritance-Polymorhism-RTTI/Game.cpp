#include "Game.h"
void Game::AddGool(string id_)
{
	Footballer help;
	int i,flag=0;
	int size1 = team1->num_players;
	int size2 = team2->num_players;
	for (i = 0;i < size1;i++)
	{
		help = (*team1)[i];
		if (id_ == help.id) //check if the id found in the team1 
		{
			flag = 1;
			team1->players[i]->Scoring(1); //add the gool to player
			gools_team1++;  //add gool to the team1
		}
			
	}
	if (flag == 0)
	{
		for (i = 0;i < size2;i++)//check if the id found in the team2 
		{
			help = (*team2)[i];
			if (id_ == help.id)//add the gool to player
			{
				flag = 1;
				gools_team2++; //add gool to the team2
			}
			
		}
	}
	if (flag == 0) //check if the id not found
		cout << "the id is not found to any player in the game" << endl;
		if (gools_team2 > gools_team1) //check how is the winner
			name_winer = team2->name_team;
		else
			if (gools_team2 == gools_team1)
			{
				if(gools_team1!=0)
				name_winer = "equal"; //if the two teams have the same number of gools
			}
			else
				name_winer = team1->name_team;
	
}

void Game::print() const //print team details
{
	cout << "the information of the team 1 is :" << endl;
	cout << "**********************************" << endl;
	team1->print();
	cout << "**********************************" << endl;
	cout << "the information of the team 2 is :" << endl;
	cout << "**********************************" << endl;
	team2->print();
	cout << "**********************************" << endl;
	cout << "the winer is :" << endl;
	cout << "**********************************" << endl;
	cout << name_winer<<endl;
	cout << "the date of the game is :" << endl;
	cout << "**********************************" << endl;
	date_->PrintDate();
	cout << endl;

}




bool Game::InFuture() const //if the game in the future
{
	Date a;
	if ((*date_) > a)
		return true;
	else
		return false;
}

Game::~Game() //dtor
{
	for (int i = 0;i < 3;i++)
		if (referee_[i])
			delete referee_[i];

	if (referee_)
		delete[]referee_;

	if (team1)
		delete team1;

	if (team2)
		delete team2;

	if (date_)
		delete date_;

}

Game::Game() //def ctor
{
	date_ = NULL;
	team1 = NULL;
	team2 = NULL;
	name_winer = "empty";
	gools_team1 = 0;
	gools_team2 = 0;
	num_referee = 0;
	referee_ = NULL;

}

void Game::AddReffer(Referee &sec) //to add  a new reffer to the array
{
	int i;
	if (num_referee == 0) // if the array of the referee is empty
	{
		num_referee++;
		referee_ = new Referee*[1];
		referee_[0] = new Referee(sec);
	}
	else // if the array of the referee is not  empty
	{
		Referee** help;
		help = new Referee*[num_referee]; //a help array pointers to copy the past referee
		for (i = 0; i < num_referee; i++) {
			help[i] = new Referee(*referee_[i]);  //copy the past referee 
			delete referee_[i];
		}
		delete[]referee_;
		referee_ = new Referee*[num_referee + 1];//build the array
		for (i = 0; i < num_referee; i++) 
			 referee_[i]= new Referee(*help[i]) ; //copy the past referee
			 referee_[i] = new Referee(sec);  //copy the new referee

			 for(i=0;i< num_referee;i++)
				 delete help[i];

			 delete[]help;

		num_referee++;
	}
}
