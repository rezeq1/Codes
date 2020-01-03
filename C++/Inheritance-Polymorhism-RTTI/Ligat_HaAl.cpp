#include "Ligat_HaAl.h"

void Ligat_HaAl::GiveId() const //give a different ids to the footballers
{
	teams_liga[0]->players[0]->id = "001100";
	teams_liga[0]->players[1]->id = "000221";
	teams_liga[0]->players[2]->id = "003302";
	teams_liga[0]->players[3]->id = "001034";
	teams_liga[0]->players[4]->id = "003205";
	teams_liga[0]->players[5]->id = "001206";
	teams_liga[0]->players[6]->id = "0034207";
	teams_liga[0]->players[7]->id = "004308";
	teams_liga[0]->players[8]->id = "0002349";
	teams_liga[0]->players[9]->id = "0002310";
	teams_liga[0]->players[10]->id = "010011";
	teams_liga[0]->players[11]->id = "100012";
	teams_liga[0]->players[12]->id = "100013";
	teams_liga[0]->players[13]->id = "100014";
	teams_liga[0]->players[14]->id = "100015";


	teams_liga[1]->players[0]->id = "112211";
	teams_liga[1]->players[1]->id = "1133511";
	teams_liga[1]->players[2]->id = "111255";
	teams_liga[1]->players[3]->id = "1111145";
	teams_liga[1]->players[4]->id = "1113335";
	teams_liga[1]->players[5]->id = "1111236";
	teams_liga[1]->players[6]->id = "112217";
	teams_liga[1]->players[7]->id = "112318";
	teams_liga[1]->players[8]->id = "112319";
	teams_liga[1]->players[9]->id = "1112310";
	teams_liga[1]->players[10]->id = "112211";
	teams_liga[1]->players[11]->id = "111212";
	teams_liga[1]->players[12]->id = "111213";
	teams_liga[1]->players[13]->id = "111214";
	teams_liga[1]->players[14]->id = "111215";


	teams_liga[2]->players[0]->id = "2222322";
	teams_liga[2]->players[1]->id = "2222321";
	teams_liga[2]->players[2]->id = "2223232";
	teams_liga[2]->players[3]->id = "2222234";
	teams_liga[2]->players[4]->id = "0222335";
	teams_liga[2]->players[5]->id = "12426";
	teams_liga[2]->players[6]->id = "643227";
	teams_liga[2]->players[7]->id = "0122318";
	teams_liga[2]->players[8]->id = "0121139";
	teams_liga[2]->players[9]->id = "00123010";
	teams_liga[2]->players[10]->id = "0032011";
	teams_liga[2]->players[11]->id = "0011012";
	teams_liga[2]->players[12]->id = "0012013";
	teams_liga[2]->players[13]->id = "1021014";
	teams_liga[2]->players[14]->id = "0023015";



	teams_liga[3]->players[0]->id = "1100900";
	teams_liga[3]->players[1]->id = "1208001";
	teams_liga[3]->players[2]->id = "1304002";
	teams_liga[3]->players[3]->id = "1401004";
	teams_liga[3]->players[4]->id = "1502005";
	teams_liga[3]->players[5]->id = "160006";
	teams_liga[3]->players[6]->id = "170007";
	teams_liga[3]->players[7]->id = "180008";
	teams_liga[3]->players[8]->id = "280009";
	teams_liga[3]->players[9]->id = "12300010";
	teams_liga[3]->players[10]->id = "1100011";
	teams_liga[3]->players[11]->id = "1600012";
	teams_liga[3]->players[12]->id = "78090013";
	teams_liga[3]->players[13]->id = "4006014";
	teams_liga[3]->players[14]->id = "5060015";



	teams_liga[4]->players[0]->id = "0000";
	teams_liga[4]->players[1]->id = "0001";
	teams_liga[4]->players[2]->id = "0002";
	teams_liga[4]->players[3]->id = "0004";
	teams_liga[4]->players[4]->id = "0005";
	teams_liga[4]->players[5]->id = "0006";
	teams_liga[4]->players[6]->id = "0007";
	teams_liga[4]->players[7]->id = "0008";
	teams_liga[4]->players[8]->id = "0009";
	teams_liga[4]->players[9]->id = "00010";
	teams_liga[4]->players[10]->id = "00011";
	teams_liga[4]->players[11]->id = "00012";
	teams_liga[4]->players[12]->id = "00013";
	teams_liga[4]->players[13]->id = "00014";
	teams_liga[4]->players[14]->id = "00015";

}

void Ligat_HaAl::GiveMangerCoach() const //add the coachs and the mangers of the teams  and give to thim details
{
	Manger a1(1, "asd", "Asdsa", "2123213"), b1(0, "baf", "ASfsa", "9999979"), c1(2, "fasd", "mfas", "2133122222");
	Manger d1(5, "lab", "kvas", "12212121210"), e1(0, "emas", "fdasda", "0002102");

	Coach a2("RealMadierd", true, 2, 2, "2001230", "danger"), b2("Barclona", true, 0, 0, "10908230", "mster");
	Coach c2("Manshester", false, 0, 3, "046730", "booas"), d2("Levarbool", false, 2, 3, "0812830", "verya");
	Coach e2("United", false, 2, 1, "077230", "plas");

	//add the coachs and the mangers to the teams
	teams_liga[0]->AddManger(&a1);
	teams_liga[0]->AddCoach(&a2);

	teams_liga[1]->AddManger(&e1);
	teams_liga[1]->AddCoach(&e2);

	teams_liga[2]->AddManger(&d1);
	teams_liga[2]->AddCoach(&d2);

	teams_liga[3]->AddManger(&b1);
	teams_liga[3]->AddCoach(&b2);

	teams_liga[4]->AddManger(&c1);
	teams_liga[4]->AddCoach(&c2);



}

void Ligat_HaAl::SetWorkers() const//set the footballers and the mangers and the coachs to the workers
{
	int m = 0;
	int f = 0;

	for (m = 0;m < teams_liga[0]->num_players;m++)   //set the footballers to the workers
		workers_liga[f++] = new Footballer((*teams_liga[0])[m]);
	

	for (m = 0;m < teams_liga[1]->num_players;m++)
		workers_liga[f++] = new Footballer((*teams_liga[1])[m]);
	

	for (m = 0;m < teams_liga[2]->num_players;m++)
		workers_liga[f++] = new Footballer((*teams_liga[2])[m]);
	

	for (m = 0;m < teams_liga[3]->num_players;m++)
		workers_liga[f++] = new Footballer((*teams_liga[3])[m]);
	

	for (m = 0;m < teams_liga[4]->num_players;m++)
		workers_liga[f++] = new Footballer((*teams_liga[4])[m]);
	


	workers_liga[f++] = new Manger (teams_liga[0]->getManger());//set the mangers to the workers
	workers_liga[f++] = new Manger (teams_liga[1]->getManger());
	workers_liga[f++] = new Manger (teams_liga[2]->getManger());
	workers_liga[f++] = new Manger (teams_liga[3]->getManger());
	workers_liga[f++] = new Manger (teams_liga[4]->getManger());

	workers_liga[f++] = new Coach (teams_liga[0]->getCoach());//set the coachs to the workers
	workers_liga[f++] = new Coach(teams_liga[1]->getCoach());
	workers_liga[f++] = new Coach(teams_liga[2]->getCoach());
	workers_liga[f++] = new Coach(teams_liga[3]->getCoach());
	workers_liga[f++] = new Coach(teams_liga[4]->getCoach());

}

void Ligat_HaAl::AddReferee(string a, string b, string c, int d)//add a new referee to the workers
{
	int i;
	Referee f(0, 0, d, a, b, c);

	Worker **arr;
	arr = new Worker*[num_workers];

	for (i = 0;i < num_workers;i++) //copy the past referee to help array
		arr[i] = workers_liga[i];

	delete[]workers_liga;

	workers_liga = new Worker*[num_workers + 1];

	for (i = 0;i < num_workers;i++) //copy the past referees and the new referee
		workers_liga[i] = arr[i];
	workers_liga[i] = new Referee(f);

	num_workers++;
	delete[]arr;

}

int Ligat_HaAl::ReturnPoints(string sec)//to return the points of the team
{
	int a = 0;
	for (int i = 0;i < 20;i++)
		if (games_liga[i]->team1->name_team == sec || games_liga[i]->team2->name_team == sec)
		{
			if (games_liga[i]->name_winer == sec)//check if the team is wining in the game
				a += 3;
			else
				if (games_liga[i]->name_winer == "equal")// teko
					a++;
		}
	return a;
}

void Ligat_HaAl::PrintChoises() const //to print the cohises of the menu function
{
	cout << "To Add Footballer enter 1" << endl;
	cout << "To Add Referee  enter 2" << endl;
	cout << "To Print Team details  enter 3" << endl;
	cout << "To Print referee details  4" << endl;
	cout << "To Print future games details  enter 5" << endl;
	cout << "To Print worker salary  6" << endl;
	cout << "To Add Goal  enter 7" << endl;
	cout << "To Add judgment errors   enter 8" << endl;
	cout << "To Print outstanding people   enter 9" << endl;
	cout << "To Print table  enter 10" << endl;
	cout << "To Print footballer details with smallest salary   enter 11" << endl;
	cout << "To Exit  enter 12" << endl;

}

string Ligat_HaAl::PrintRoles() const	// to print the roles of the footballer to  choose one of them
{
	int a;
	cout << "for Back enter 1" << endl;
	cout << "for Goalkeeper enter 2" << endl;
	cout << "for Defender enter 3 " << endl;
	cout << "for Forward enter 4 " << endl;
	cout << "for Midfielder enter 5 " << endl;
	cin >> a;
	while (a < 0 || a>5)
	{
		cout << "you enterd a wrong role please enter again" << endl;
		cin >> a;
	}

	switch (a)
	{
	case 1:
		return "Back";
		break;
	case 2:
		return "Goalkepper";
		break;
	case 3:
		return "Defender";
		break;
	case 4:
		return "Forward";
		break;
	case 5:
		return "Midfielder ";
		break;
	}



}

bool Ligat_HaAl::IsFound(string d) const //if the id is found in the array of liga's workers
{

	for (int i = 0;i < num_workers;i++){
		if (workers_liga[i]->GetId() == d) 
			return true;
		
		}

	return false;
}

void Ligat_HaAl::help_Footballer(Footballer f) // to add a new footballer to the workers liga
{
	int i;

	Worker **arr;
	arr = new Worker*[num_workers];

	for (i = 0; i < num_workers; i++) //copy the past workers to a help array
		arr[i] = workers_liga[i];

	delete[]workers_liga;

	workers_liga = new Worker*[num_workers + 1];

	for (i = 0; i < num_workers; i++)//copy the past workers and the new footballer to the array
		workers_liga[i] = arr[i];
	workers_liga[i] = new Footballer(f);

	num_workers++;
	delete[]arr;

	
}

Ligat_HaAl::Ligat_HaAl() //ctor
{
	int j, c = 0, v = 0, indexRef=0;
	Referee e11(12, 23, 1, "rezeq", "abomad", "2113213411321");
	Referee e12(1, 0, 4, "yosi", "abtat", "0212330221");
	Referee e13(2, 0, 3, "michal", "flamda", "6575765768");
	Referee e14(3, 13, 2, "yosef", "moshay", "9765234433");
	Referee arr[] = { e11,e12,e13,e14 };
	Stadium f1("amerca", "beer sheva", 4000), f2("vina", "Netevot", 5620), f3("forFoot", "Isreal", 12000), f4("loveBool", "australia", 4020), f5("fbcClub", "Spain", 7600);
	teams_liga = new Team*[5];

	
		teams_liga[0] = new Team(f1);//add a stadiums to the teams
		teams_liga[1] = new Team(f2);
		teams_liga[2] = new Team(f3);
		teams_liga[3] = new Team(f4);
		teams_liga[4] = new Team(f5);


	games_liga = new Game*[20];//build 20 game

	for (int i = 0;i < 20;i++)
		games_liga[i] = new Game;



	num_workers = (17 * 5) + 4;   //build array of liga workers
	workers_liga = new Worker*[num_workers];






	Footballer a1("Goalkeeper"), a2("Defender"), a3("Back"), a4("Forward"), a5("Midfielder");
	for (int i = 0;i < 5;i++) //add to the 5 teams a 15 footballers with different roles and empty details
	{


		for (j = 0;j < 2;j++) {
			teams_liga[i]->AddPlayer(&a1);
		}

		for (j = 0;j < 3;j++) {
			teams_liga[i]->AddPlayer(&a2);
		}

		for (j = 0;j < 3;j++) {
			teams_liga[i]->AddPlayer(&a3);

		}

		for (j = 0;j < 3;j++) {
			teams_liga[i]->AddPlayer(&a4);

		}

		for (j = 0;j < 4;j++)
		{
			teams_liga[i]->AddPlayer(&a5);

		}

		

	}



	GiveId(); // give a different id to the footballers
	GiveMangerCoach();//give every team a coach and a manger
	SetWorkers(); //set the footballers and the mangers and the coachs to the workers liga

	srand(time(NULL));
	teams_liga[0]->name_team = "RealMadierd"; //give names to the teams
	teams_liga[1]->name_team = "Barclona";
	teams_liga[2]->name_team = "Manshester";
	teams_liga[3]->name_team = "Levarbool";
	teams_liga[4]->name_team = "United";

	for (int i = 0;i < 4;i++)
		for (j = i + 1;j < 5;j++)
		{
			
			indexRef = rand() % 4; //set 3 referees to each game
		for (int v = 0; v < 4; v++)
				if (v != indexRef)
					games_liga[c]->AddReffer(arr[v]);
			
			games_liga[c]->team1 = new Team(*(teams_liga[i])); //set the teams of the games
			games_liga[c]->team2 = new Team(*(teams_liga[j]));

			games_liga[c]->date_ = new Date;         //set the date of the games
			games_liga[c]->date_->SetDay(rand() % 30 + 1);
			games_liga[c]->date_->SetMonth(rand() % 12 + 1);
			games_liga[c]->date_->SetYear(rand() % 2 + 2019);

			c++;

			
			indexRef = rand() % 4;    //build another game with the same teams but with differnt date and referees
			for (int v = 0; v < 4; v++)
				if (v != indexRef)
					games_liga[c]->AddReffer(arr[v]);
			
			games_liga[c]->team1 = new Team(*(teams_liga[i]));
			games_liga[c]->team2 = new Team(*(teams_liga[j]));

			games_liga[c]->date_ = new Date;
			games_liga[c]->date_->SetDay(rand() % 30 + 1);
			games_liga[c]->date_->SetMonth(rand() % 12 + 1);
			games_liga[c]->date_->SetYear(rand() % 2 + 2019);

			c++;
		}


	//add a 4 referees to the workers liga
	workers_liga[85] = new Referee(e11);
	workers_liga[86] = new Referee(e12);
	workers_liga[87] = new Referee(e13);
	workers_liga[88] = new Referee(e14);


}

Ligat_HaAl::~Ligat_HaAl() //dtor
{
	for (int i = 0;i < 5;i++) //teams
		if (teams_liga[i])
			delete teams_liga[i];

	if (teams_liga)
		delete[]teams_liga;
	///////
	for (int i = 0;i < 20;i++) {  //games
		if (games_liga[i]->date_)  //the date of the games
			delete games_liga[i]->date_;
		if (games_liga[i])
			delete games_liga[i];
	}
	if (games_liga)
		delete[]games_liga;
	///////
	for (int i = 0;i < num_workers;i++)  // the workers
			delete workers_liga[i];

	if (workers_liga)
		delete[]workers_liga;
}
///*
void Ligat_HaAl::Menu()
{
	int x, i, help = -1, flag = 0, num, w, flag2 = 0, flag8 = -1, flagId = 0, flagA;
	int row = 0, col = 0;
	Referee ne,*ref_help;
	string a, b, c, e, d;
	PrintChoises();
	cin >> x;
	while (x != 12) {
		switch (x)
		{
		case 1:
			flag = 0;
			for (i = 0;i < 5;i++)
				cout << "for team :  " << teams_liga[i]->name_team << "  enter the number : " << i << endl;
			cin >> help;
			if (help > 4 || help < 0) //check if the input is illegal
				cout << "the team that you enterd not found" << endl;
			else
			{
				cout << "enter the id of the player" << endl;
				cin >> b;

				if (IsFound(b)==false) //check if the id founds in the workers
				{
					cout << "enter the name of the player" << endl; //input ditals
					cin >> c;
					cout << "enter the name of the player's family" << endl;
					cin >> d;
					cout << "enter the  player's seniority" << endl;
					cin >> num;
					cout << "enter the  player's role" << endl;
					e = PrintRoles();
					Footballer a2(e, teams_liga[help]->name_team, 0, num, c, d, b);
					teams_liga[help]->AddPlayer(&a2); //add the new footballer to the team
					help_Footballer(a2);   //add the new footballer to the workers liga
				

				}
				else
					cout << "the are a worker with this id" << endl;
			}
			break;
		case 2:
			flag2 = 0;
			cout << "enter the id of the new referee" << endl;
			cin >> b; 
			for (i = 0;i < num_workers;i++) {  //check if the id founds
				if (workers_liga[i]->GetId() == b)
					flag2 = 1;
			}
			if (flag2 == 1)
				cout << "Warnning They are person with this id" << endl;
			else
			{
				cout << "enter the name" << endl;
				cin >> c;
				cout << "enter the name of his family" << endl;
				cin >> d;
				cout << "enter her seniority" << endl;
				cin >> num;
				AddReferee(c, d, b, num);


			}






			break;
		case 3:
			for (i = 0;i < 5;i++)
				cout << "for print details of team :  " << teams_liga[i]->name_team << "  enter the number : " << i + 1 << endl;
			cin >> num;
			if (num > 5 || num < 1) //check if the input is illigal
				cout << "you have enter a wrong number" << endl;
			else
				teams_liga[num - 1]->print();  //printing team diteals

			break;
		case 4:
			for (i = 0;i < num_workers;i++) {
				if (typeid(*workers_liga[i]) == typeid(Referee)) //check if the player is referee
					workers_liga[i]->print();
			}


			break;
		case 5:
			cout << "the future games is : " << endl;
			for (i = 0;i < 20;i++)
				if (games_liga[i]->InFuture()) { //check if the date is in the future
					cout << "the name of first team is: " << games_liga[i]->team1->name_team << endl;
					cout << "the name of first team is: " << games_liga[i]->team2->name_team << endl;
					cout << "the date of the game is: ";
					games_liga[i]->date_->PrintDate();
					cout << endl;
				}


			break;
		case 6:
			cout << "enter the id of the player" << endl;
			cin >> b;
			help = -1;
			for (i = 0;i < num_workers;i++) //check if the id founds in the worker liga
				if (workers_liga[i]->GetId() == b)
					help = i;
			if (help == -1)
				cout << "you have enter a worng id" << endl;
			else
				cout << "the salary of the player is: " << workers_liga[help]->GetSalary() << endl;


			break;
		case 7:
			help = -1;
			for (i = 0;i < 20;i++) //printing the games details to choose
			{
				cout << "*********************" << endl;
				cout << "To chose this game enter :  " << i << endl;
				cout << "*********************" << endl;
				cout << "the name of first team is : " << games_liga[i]->team1->name_team << endl;
				cout << "the name of seconde team is : " << games_liga[i]->team2->name_team << endl;
				cout << "the date of the game is :" << endl;
				games_liga[i]->date_->PrintDate();
				cout << "*********************" << endl;
				
			}
			cin >> w;
			if (w >= 0 && w <= 19) //check if the input illigal
			{
				cout << "enter the player id to add to him a gool" << endl;
				cin >> b;
				help = -1;
				for (i = 0; i < num_workers; i++)
					if (workers_liga[i]->GetId() == b)
						help = i;
				if (help == -1)
					cout << "you have enter a worng id" << endl;
				else
				{
					games_liga[w]->AddGool(b);
				}


			}
			else
				cout << "Your choise is uncorrect" << endl;

			break;
		case 8:
			flag8 = -1;
			flagId = 0;
			cout << "enter the id of the Referee to add to him an error" << endl;
			cin >> b;
			for (i = 0; i < num_workers; i++)
			{
				if (typeid(*workers_liga[i]) == typeid(Referee))
				{
					if (workers_liga[i]->GetId() == b)
						flag8 = i;
				}
			}
			if (flag8 == -1)
				cout << "the are no referee with this id " << endl;
			else
			{
	
					flagA = -2;
					for (i = 0;i < 20;i++)				//add an error to referee how jude in games
					{
						for (int l = 0;l < games_liga[i]->num_referee;l++)
						{
							if (games_liga[i]->referee_[l]->id == b)
							{
								games_liga[i]->referee_[l]->AddWrongs(1);
								flagA = 0;
								col = i;
								row = l;
							}
						}
					}


					if (flagA == -2) { //add an error to referee how dose not jude in any  game 
						ne.name = workers_liga[flag8]->name;
						ne.family = workers_liga[flag8]->family;
						ne.id = workers_liga[flag8]->GetId();
						ne.seniority = workers_liga[flag8]->seniority;
						ne.AddWrongs(1);
						delete workers_liga[flag8];
						workers_liga[flag8] = new Referee(ne);
					}
					else
					{ //copy the the referee after the add error to liga worker
						ref_help = games_liga[col]->referee_[row];
						delete workers_liga[flag8];
						workers_liga[flag8] = new Referee(*ref_help);
					}


				}
			
			break;
		case 9:
			for (i = 0; i < num_workers; i++) {
				
				if (workers_liga[i]->Outstanding() == true)
				{

					workers_liga[i]->print();
					cout << endl;
				}
			}
			break;
		case 10:
			for (i = 0;i < 5;i++)
			{
				cout << "the points of team " << teams_liga[i]->name_team;
				cout << "  is " << ReturnPoints(teams_liga[i]->name_team) << endl;
			}

			break;
		case 11:
			int min = (*teams_liga[0])[0].GetSalary();
			for (i = 0;i < 5;i++)
				for (int j = 0;j < 15;j++)
					if ((*teams_liga[i])[j].GetSalary() < min)
					{
						row = i;
						col = j;
					}
			cout << "*********************************" << endl;
			cout << "the smallest footbooler salary is" << endl;
			(*teams_liga[row])[col].print();

			break;

		}
		if (x > 11 || x < 0)
			cout << "you enterd a wrong choise" << endl;
		cout << "********************** " << endl;
		cout << "enter your next choise" << endl;
		cin >> x;
	}




}
//*/