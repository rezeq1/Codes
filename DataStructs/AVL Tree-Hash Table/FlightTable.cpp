#include "FlightTable.h"

FlightTable::FlightTable(int size)
{
	if (size % 3 == 0)
		tableSize = size / 3;
	else
		tableSize = (size - size % 3) / 3;

	table = new PassengerTree*[tableSize];

	for (int i = 0;i < tableSize;i++)
	{
		table[i] = new PassengerTree;
	}
}

FlightTable::~FlightTable()
{
	for (int i = 0;i < tableSize;i++)
		delete table[i];

	delete table;
}

void FlightTable::addPassenger(int passId)
{
	int index;
	index = h(passId);
	table[index]->treeRoot=table[index]->insertNode(table[index]->treeRoot,passId);

}

void FlightTable::removePassenger(int passId)
{
	int index;
	index = h(passId);
	table[index]->treeRoot = table[index]->RemoveNode(table[index]->treeRoot, passId);
}

void FlightTable::displayTable()
{
	for (int i = 0;i < tableSize;i++)
	{
		cout << "tree number " << i << endl;
		if (table[i]->numOfNodes != 0)
		{
			cout << "nodes: " << table[i]->numOfNodes << " heghit: " << table[i]->HeghitOfTree() << endl;
			table[i]->displayTree();
		}
		else
			cout << "nodes:0 heghit: 0"<<endl;
		cout << "****************************"<<endl;
	}
}

int FlightTable::h(int k)
{
	return k % tableSize;
}

int FlightTable::Check_in(int id)
{
	int index = h(id);
	if (table[index]->numOfNodes == 0)
		return 1;
	else
		return table[index]->Check_(id);
	
}

bool FlightTable::Exist(int id)
{
	int index = h(id);
	if (table[index]->numOfNodes == 0)
		return false;
	else
		return table[index]->IsExist(id);
}

int FlightTable::SizeOfFile(string name_file)
{
	ifstream size(name_file);
	char letter;
	int id, count = 0;
	if (size.is_open())
	{
		while (size >> id)
		{
			count++;
			size >> letter;

		}

		size.close();
	}
	else cout << "Unable to open file";
	return count;
}

void FlightTable::InputFile(string name_file)
{
	ifstream file_inp(name_file);
	char letter;
	int id, count = 0;
	if (file_inp.is_open())
	{
		while (file_inp >> id)
		{
			addPassenger(id);
			file_inp >> letter;

		}
		file_inp.close();
	}
	else cout << "Unable to open file";

}

void FlightTable::OutputArr(string name_file,int*arr,int size)
{
	ofstream out(name_file, fstream::app);
		for (int i=0;i<size-1;i++)
		out <<arr[i]<<", ";

		out << arr[size - 1]<<endl;

		out.close();

}

void FlightTable::OutputTaple(string name_file)
{
	ofstream out(name_file, fstream::app);
	for (int i = 0;i < tableSize - 1;i++)
		if (table[i]->numOfNodes == 0)
			out << "0,0 ";
		else
			out << table[i]->numOfNodes << "," << table[i]->HeghitOfTree() << " ";
	

	if (table[tableSize - 1]->numOfNodes == 0)
		out << "0,0";
	else
		out << table[tableSize - 1]->numOfNodes << "," << table[tableSize - 1]->HeghitOfTree();
	out << endl;


	out.close();
}

void FlightTable::OutputAverage(string name_file,int a)
{
	ofstream out(name_file, fstream::app);
		out << a << endl;
	out.close();
}

int FlightTable::AvergSteps(string name_file)
{
	ifstream size(name_file);
	char letter;
	int id, count = 0;
	if (size.is_open())
	{
		while (size >> id)
		{
			count += Check_in(id);
			size >> letter;

		}

		size.close();
	}
	else cout << "Unable to open file";

	return (count - count % SizeOfFile(name_file)) / SizeOfFile(name_file);
}

int* FlightTable::FinalPassengers(string name_file1, string name_file2,string name_file3)
{
	int* arr;
	ifstream input(name_file1), help_input(name_file1);
	char letter;
	int searc, flag = 0, size2 = SizeOfFile(name_file2);
	arr = new int[size2];
	int i, size = SizeOfFile(name_file1);
	if (input.is_open())
	{
		for (i = 0;i < size;i++)
		{

			while (input >> searc)
			{
				if (Exist(searc))
					arr[flag++] = searc;
				input >> letter;
			}

		}
	}
	else
	cout << "Unable to open file";
	input.close();

	if (help_input.is_open())
	{
		for (i = 0;i < size;i++)
		{
			while (help_input >> searc && flag < size2)
			{
				if (!(Exist(searc)))
					arr[flag++] = searc;
				help_input >> letter;
			}

		}
	}
	else cout << "Unable to open file";
	help_input.close();


	sort(arr, arr + size);

	OutputArr(name_file3, arr, size);
	return arr;
}
