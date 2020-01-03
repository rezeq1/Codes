#include "PassengerTree.h"


class FlightTable
{

private:
	PassengerTree** table;
	int tableSize;

public:

	FlightTable(int size);
	~FlightTable();
	void addPassenger(int passId);
	void removePassenger(int passId);
	void displayTable();
	int h(int);
	int Check_in(int id);
	bool Exist(int id);
	int SizeOfFile(string name_file);
	void InputFile(string name_file);
	void OutputArr(string name_file, int*arr, int size);
	void OutputTaple(string name_file);
	void OutputAverage(string name_file,int);
	int AvergSteps(string name_file);
	int* FinalPassengers(string name_file, string name_file2, string name_file3);


};
