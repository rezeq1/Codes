#include"Number.h"

class Game
{
	Number* user;
	Number* pc;
	int Cow()const;//calculate the cows
	int Bull()const;//calculate the bulls
	bool CheckZero(int)const;//checking if the number have the digit 0
public:
	Game(const Game&);//copy ctor
	Game();//ctor
	~Game();//dtor
	void Play();//a function to run the game



};
