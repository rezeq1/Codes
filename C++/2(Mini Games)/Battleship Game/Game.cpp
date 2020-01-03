#include "Game.h"

int Game::del = 0;
int Game::Returnkevon(int row, char col, int kevon, int LongShip)const//function to return the direction that we can put the ship
{
	int index;
	index = ReturnInt(col);
	if (kevon == 1)//vertical
	{
		if ((LongShip + index) <= 10)
			return 1;//right
		if ((index - LongShip) >= 1)
			return 2;//left

	}
	else//horizontal
	{
		if ((LongShip + row) <= 10)
			return 3;//north
		if ((row - LongShip) >= 1)
			return 4;//south


	}

}

int Game::ReturnInt(char letter)const//return the number of the litter
{
	switch(letter)
	{
		case 'A':
			return 1 ;
			break;
		case 'B':
			return 2;
			break;
		case 'C':
			return 3 ;
			break;
		case 'D':
			return 4;
			break;
		case 'E':
			return 5;
			break;
		case 'F':
			return 6;
			break;
		case 'G':
			return 7;
			break;
		case 'H':
			return 8;
			break;
		case 'I':
			return 9;
			break;
		case 'J':
			return 10;
			break;
}

}

char Game::Returnletter(int a)const
{
	switch (a)
	{
	case 1:
		return 'A';
		break;
	case 2:
		return 'B';
		break;
	case 3:
		return 'C';
		break;
	case 4:
		return 'D';
		break;
	case 5:
		return 'E';
		break;
	case 6:
		return 'F';
		break;
	case 7:
		return 'G';
		break;
	case 8:
		return 'H';
		break;
	case 9:
		return 'I';
		break;
	case 10:
		return 'J';
		break;
	}

}



bool Game::CheckPlace(int row, char col, int kevon,int LongShip)// check if we can put a ships by the requested number  and direction
{
	int index;
	index = ReturnInt(col);
	if (kevon == 1)//the direction is vertical
	{
		if ((LongShip + index) <= 10)
			return true;
		if ((index - LongShip) >= 1)
			return true;

		return false;
	}
	else//the direction is herizontal
	{
		if ((LongShip + row) <= 10)
			return true;
		if ((row - LongShip) >= 1)
			return true;

		return false;

	}



}



void Game::BuildBoard()// put a ships by a random place and direction
{
	int kevon, row, col,LongShip,right;
	char letter;
	srand(time(NULL));

	for (int i = 0;i < size;i++) {
		LongShip = GetLongOf(i+1);
		do {	
			kevon = rand() % 2;//random direction
			row = rand() % 10 + 1;	//random index of row
			col = rand() % 10 + 1;	//random index coulmn
			letter = Returnletter(col);
			right = Returnkevon(row, letter, kevon, LongShip);//get the direction

		} while (CheckPlace(row, letter, kevon, LongShip) == false || Help2(row,col,right,LongShip)==false);

			PutShip(row, col, right, LongShip);//put the ship in the requested place
			del += LongShip;
	}
}

bool Game::CheckHit(int a, char b)//checking if the user hit any ship
{
	int col = ReturnInt(b);
	if (board[a - 1][col - 1] == 'S') {
		board[a - 1][col - 1] = '@';//hit
		return true;
	}
	else if (board[a - 1][col - 1] == '@')//hit again
		cout << "you choose this point before" << endl;
	else
		board[a-1][col-1] = 'X';//didint hit
	return false;
}

int Game::GetLongOf(int c)const//get the long of the requested ship
{
	switch (c)
	{
		case 1:
			return 5;
			break;
		case 2:
			return 4;
			break;
		case 3:
			return 3;
			break;
		case 4:
			return 2;
			break;
		case 5:
			return 3;
			break;
}

}

void Game::PutShip(int row, int index, int kevon, int LongShip)//put the ship in the requested place with the requested direction
{
	int i;
	if (kevon == 1)//the direction is right
		for (i =0;i < LongShip;i++)
			board[row-1][i-1+index] = 'S';

	if (kevon == 2)//the direction is lift
		for (i =0;i < LongShip;i++)
			board[row - 1][index-i - 1] = 'S';

	if (kevon == 3)//the direction is south
		for (i = 0;i < LongShip;i++)
			board[row+i-1][index-1] = 'S';

	if (kevon == 4)//the direction is right north
		for (i = 0;i < LongShip;i++)
			board[row-i - 1][index- 1] = 'S';
	

}




bool Game::Help1(int row, int col)const//checking if the we can  put a poiont
{
	
	if (board[row][col] == 'S' || board[row][col - 1] == 'S' || board[row][col + 1] == 'S' || board[row - 1][col] == 'S'|| board[row +1][col] == 'S')
		return false;
	return true;
}

bool Game::Help2(int row, int col, int kevon, int LongShip)const//check if we can put a ship using function help1
{

	for (int i = 0;i < LongShip;i++)
	{
		if (kevon == 1)//the direction is right
		{
			if (Help1(row - 1, col - 1 + i) == false)
				return false;
		}
		if (kevon == 2)//the direction is lift
		{
			if (Help1(row - 1, col - 1 - i) == false)
				return false;
		}
		if (kevon == 3)//the direction is south
		{
			if (Help1(row - 1+i, col - 1 ) == false)
				return false;
		}
		if (kevon == 4)//the direction is north
		{
			if (Help1(row - 1-i, col - 1 ) == false)
				return false;
		}
	}
	return true;
}



void Game::clearboard()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			board[i][j] = '_';
}

void Game::PrintBoard()const
{
	char leter = 'A';
	cout << "  ";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << leter;
		leter++;
	}
	cout << endl;

		for (int i = 0; i < 9; i++) {
			cout << i + 1<<" ";
			for (int j = 0; j < 10; j++)
			{
				if (board[i][j] != 'S')
					cout << " " << board[i][j];
				else
					cout << " " << '_';
			}
			cout << endl;

		}
		cout << 10 << " ";
		for (int i = 0; i < 10; i++)
		{
			if (board[9][i] != 'S')
				cout << board[9][i] << " ";
			else
				cout << '_' << " ";

		}
			cout << endl;

}

void Game::PrintOrginalBoard()const
{
	char leter = 'A';
	cout << "  ";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << leter;
		leter++;
	}
	cout << endl;

	for (int i = 0; i < 9; i++) {
		cout << i + 1 << " ";
		for (int j = 0; j < 10; j++)
			cout << " " << board[i][j];
		cout << endl;

	}
	cout << 10 << " ";
	for (int i = 0; i < 10; i++)
		cout << board[9][i] << " ";
	cout << endl;
}

void Game::PrintClearBoard()const
{

	char leter = 'A';
	cout << "  ";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << leter;
		leter++;
	}
	cout << endl;

	for (int i = 0; i < 9; i++) {
		cout << i + 1 << " ";
		for (int j = 0; j < 10; j++)
			cout << " " << "_";
		cout << endl;

	}
	cout << 10 << " ";
	for (int i = 0; i < 10; i++)
		cout << "_" << " ";
	cout << endl;






}

void Game::play()//the main function to run the game
{
	clearboard();
	BuildBoard();
	char str;
	int x;
	int counter = 0;
	cout << "do you want a hint?? if yes press'y' else enter any char" << endl;
	cin >> str;
	if (str == 'y' || str == 'Y')
		PrintOrginalBoard();
	else
		PrintClearBoard();

	while (counter != del)
	{
		cout << "enter the y coordinates betweent 'A' to 'J' " << endl;
		cin >> str;
		while ((str<'a' || str>'j') && (str<'A' || str>'J'))
		{
			cout << "you enter a wrong coordinates please enter again " << endl;
			cin >> str;
		}
		cout << "enter the x coordinates betweent 1 to 10" << endl;
		cin >> x;
		while (x <= 0 || x > 10)//checking if the index is illegl
		{
			cout << "you enter a wrong coordinates please enter again " << endl;
			cin >> x;
		}
		if (str >= 'a'&&str <= 'j')
			str-= 32;
		if (CheckHit(x, str) == true)
			counter++;
		PrintBoard();
	}
	cout << "*********************************************" << endl;
	cout << "              !!!you win!!!                   "<< endl;
	cout << "*********************************************" << endl;
}



Game::Game(int a)
{
	if (a > 0 && a < 6)
	{
		arr = new Battleship[a];
		size = a;
		

	}
	else {
		a = 1;
		arr = new Battleship[a];
		size = a;
	}
}

Game::~Game()
{
	delete[]arr;
}


bool Game::CheckSunk(int x, char str)const//check if the user hit all the ships
{
	int y = ReturnInt(str);
	int i = 0, flag = 0, j;
	while (i != 4)
	{
		for (j = 1;j < 5 && board[x - 1][y - 1 + j] != '_'&&board[x - 1][y - 1 + j] != 'X';j++)//checking right of the point
		{
			
			if (board[x - 1][y - 1 + j] == 'S')
				return false;
		}
		for (j = 1;j < 5 && board[x - 1][y - 1 - j] != '_'&&board[x - 1][y - 1 - j] != 'X';j++)//checking lift of the point
		{
			
			if (board[x - 1][y - 1 - j] == 'S')
				return false;
		}
		for (j = 1;j < 5 && board[x - 1 + j][y - 1] != '_'&&board[x - 1 + j][y - 1] != 'X';j++)//checking south of the point
		{
			
			if (board[x - 1 + j][y - 1] == 'S')
				return false;
		}
		for (j = 1;j < 5 && board[x - 1 - j][y - 1] != '_'&&board[x - 1 - j][y - 1] != 'X';j++)//checking north of the point
		{
			
			if (board[x - 1 - j][y - 1] == 'S')
				return false;
		}

		i++;
	}
	return true;
}

