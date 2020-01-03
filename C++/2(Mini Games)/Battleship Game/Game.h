#include "Battleship.h"
class Game
{
	char board[10][10];
	Battleship * arr;
	int size;
	static int  del;    //static variabl for all of the long ships

	int Returnkevon(int, char, int, int)const;    //function to return the direction that we can put the ship
	int ReturnInt(char)const;                    //return the number of the litter
	char Returnletter(int)const;
	void clearboard();
	bool CheckHit(int a, char b);          //checkin if the user hit the ship
	int GetLongOf(int)const;                //get the long of the ship
	void PutShip(int, int, int, int);      //put the ship in the requested place with the requested direction
	bool CheckSunk(int, char)const;
	bool Help1(int, int)const;            //check if we can put a point
	bool Help2(int, int, int, int)const;  //check if we can put a ship using function help1
	void PrintBoard()const;
	void PrintOrginalBoard()const;
	void PrintClearBoard()const;
	void BuildBoard();                    //put a ships by the requested number 
	bool CheckPlace(int, char, int, int);     // check if we can put a ships by the requested number  and direction


public:
	Game(int);
	~Game();
	void play();
};