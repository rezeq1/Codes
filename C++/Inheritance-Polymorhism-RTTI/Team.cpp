#include "Team.h"

Team::Team()//def ctor
{
	name_team = "empty";
	stadium_= NULL;
	num_players = 0;
	coach_ = NULL;
	manger_ = NULL;
	IsManger = false;
	players = NULL;
}

Team::Team(Stadium a)//ctor
{
	stadium_ = new Stadium;
	*stadium_ = a;
	name_team = "empty";
	
	num_players = 0;
	coach_ = NULL;
	manger_ = NULL;
	IsManger = false;
	players = NULL;
}

Team::Team(const Team &sec)//copy ctor
{
	IsManger = sec.IsManger;
	num_players = sec.num_players;
	name_team = sec.name_team;
	if (sec.num_players) {			//check if the array of the players is empty
		players = new Footballer*[num_players];

		for (int i = 0;i < num_players;i++) {
			players[i] = new Footballer;
			*(players[i]) = sec[i];
		}
	}

	if (sec.coach_) { //check if they are coach
		coach_ = new Coach;
		*coach_ = sec.getCoach();
	}

	if (sec.manger_) { //check if they are manger
		manger_ = new Manger;
		*manger_ = sec.getManger();
	}

	if (sec.stadium_) { //check if they are stadium
		stadium_ = new Stadium;
		*stadium_ = sec.getStadium();
	}
}

Team::~Team()//dtor
{
	if (manger_)
		delete manger_;
	if (coach_)
		delete coach_;
	if (stadium_)
		delete stadium_;
	IsManger = false;
	for (int i = 0;i < num_players;i++)
		if(players[i])
		delete players[i];

	if (players)
		delete	[]players;
}

void Team::AddPlayer(Footballer *sec)//to add a new footballer to the team
{
	int i = 0;
	Footballer* arr;
	if (num_players != 0) {    //check if the array of the players is empty
		arr = new Footballer[num_players];

		for (int j = 0; j < num_players; j++)
			arr[j] = *(players[j]);

		for (int k = 0; k < num_players; k++)
			delete players[k];
		delete[]players;

		players = new Footballer*[1 + num_players];

		for (i = 0; i < num_players; i++) {
			players[i] = new Footballer;
			*(players[i]) = arr[i];
		}

		players[num_players] = new Footballer;
		*(players[num_players]) = *sec;

		num_players++;
		delete[]arr;


	}
	else    // if the array of the players is empty
	{

		num_players = 1;
		players = new Footballer*[1];
		players[0] = new Footballer;
		*(players[0]) = *sec;
	}
}

void Team::AddManger(Manger *sec)// to add manger
{
	if (IsManger == false) //check if the are manger before
	{
		IsManger = true;
		manger_ = new Manger;
		*manger_ = *sec;



	}
	else
		cout << "the are manger before!!" << endl;
}

void Team::AddCoach(Coach *sec) //add coach
{
	if (coach_==NULL) //check if they are coach before
	{
		coach_ = new Coach;
		*coach_ = *sec;

	}
	else
		cout << "the are coach before" << endl;
}

Footballer*  Team::ReturnPlayer(int index)   //to return the address of the player in the place index
{
	assert(index >= 0 && index < num_players);
		return players[index];
}

Stadium Team::getStadium()const  // get the team's stadium
{
	return *stadium_;
}

Manger Team::getManger()const  // get the team's manger
{
	return *manger_;
}

Coach Team::getCoach()const   // get the team's coach
{
	return *coach_;
}

void Team::print() const  // print team details
{
	cout << "the name of the team is :  " << name_team << endl;
	cout << "***************************" << endl;
	cout << "the information about the stadium is :" << endl;
	stadium_->print();
	cout << "***************************" << endl;
	cout << "the information about the coach is :" << endl;
	if(coach_)
	coach_->print();
	else
		cout<< "the team does not have a coach" << endl;
	cout << "***************************" << endl;
	if (IsManger == true) {
		cout << "the information about the manger is :" << endl;
		manger_->print();
	}
	else
		cout << "the team does not have a manger" << endl;
	cout << "***************************" << endl;
	if (num_players == 0)
		cout << "the are no players in the team !!" << endl;
	else
		for (int i = 0;i < num_players;i++) {
			cout << "the information about the player number" <<i+1<<"  is:"<<endl;
			players[i]->print();
			cout << "////////////////////////" << endl;

		}
}

Team & Team::operator=(const Team &sec) //operator =
{
	if (&sec != this)  //check if this differnt from sec address
	{
		
		IsManger = sec.IsManger;
		num_players = sec.num_players;
		name_team = sec.name_team;
		if (sec.num_players) {//check if the array of the player is empty
			players = new Footballer*[num_players];

			for (int i = 0;i < num_players;i++) {
				players[i] = new Footballer;
				*(players[i]) = sec[i];
			}
		}
		
		if (sec.coach_) {
			coach_ = new Coach;
			*coach_ = sec.getCoach();
		}

		if (sec.manger_) {
			manger_ = new Manger;
			*manger_ = sec.getManger();
		}
		
		if (sec.stadium_) {
			stadium_ = new Stadium;
			*stadium_ = sec.getStadium();
		}
		

	}
	return *this;
}
 
Footballer& Team::operator[](int index)const  //to return the player in the place index
{
	assert(index >= 0 && index < num_players);
	return *(players[index]);
	
}
