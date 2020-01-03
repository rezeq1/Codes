#include"Menu.h"

Menu::Menu()
{
	dictionar = new Dictionary;
}

Menu::~Menu()
{
	delete dictionar;
}

void Menu::MainMenu()
{
	int a, flag_1 = 0, flag_4 = 0,flag_2=0;
	cout << "1) To creat dictionary and to insert values " << endl;
	cout << "2) To  add a new definition for the dictionary " << endl;
	cout << "3) To  add a new meaning for a one of the  dictionary's definition " << endl;
	cout << "4) To  search  a definition in dictionary " << endl;
	cout << "5) To  show all of the definitions that have at leaset a one common meaning " << endl;
	cout << "6) To  exit " << endl;
	
	do {
		cout << "choose your option" << endl;
		cout << "********************" << endl;
		cin >> a;
		while (a < 1 || a>6)
		{
			cout << "you entered a wrong option" << endl;
			cout << "********************" << endl;
			cin >> a;
		}
		if (a == 1)
		{
			cout << "********************" << endl;
			if (flag_1 == 0) {//to check if the dictionar is created befor
				flag_1 = 1;
				cin >> *dictionar;
			}
			else
				cout << "you have created a dictionary before" << endl;
			cout << "********************" << endl;
		}
		if (a == 2) {
			cout << "********************" << endl;
			Definition help;
			 flag_2 = 0;
			getchar();
			cout << "enter your definitions" << endl;
			cin >> help;
			for (int i = 0;i < dictionar->num_words;i++)
				if (dictionar->words[i] == help)//check if the definition are existing
					flag_2 = 1;
			if (flag_2 == 1)
				cout << "!!!!!!!!the definition that you enterd  are existing!!!!!!!!!!!" << endl;
			else
				(*dictionar) += help;//to add the definition that enterd
			cout << "********************" << endl;
		}
		if (a == 3) {
			cout << "********************" << endl;
			char help3_1[200+1];
			getchar();
			cout << "enter your definition to add for it a new meaning" << endl;
			cin.getline(help3_1,201);
			Definition help2(help3_1, 0);
			char help3[200];
			int i, flag = 0, index = -1;
			for (i = 0;i < dictionar->num_words;i++)
				if (dictionar->words[i] == help2)//check if the meaning the enterd are existing
					index = i;
			if (index == -1)
				cout << "the dfinition not found" << endl;
			else
			{
				cout << "enter the new meaning" << endl;
				cin.getline(help3, 200 + 1);
				dictionar->words[index] += help3;
			}
			cout << "********************" << endl;
		}

		if (a == 4)//to search  a definition in dictionary
		{
			cout << "********************" << endl;
			char help1[80+1];
			cout << "enter your definition to search for it" << endl;
			getchar();
			cin.getline(help1, 80 + 1);
			Definition help2(help1, 0);
			for (int i = 0;i < dictionar->num_words;i++)
				if (dictionar->words[i] == help2) {//check if the definition is available in the dictionary
					cout << dictionar->words[i] << endl;
					flag_4 = 1;
				}
			if (flag_4 == 0)
				cout << "the difintion not found" << endl;
			cout << "********************" << endl;

		}
		
		if (a == 5)
		{
			cout << "********************" << endl;
			if (dictionar->PrintShared() == false)
				cout << "they are no common meaning for each  words " << endl;
			cout << "********************" << endl;
		}
		
		if (a == 6)
		{
			cout << "exit option" << endl;
		}

	} while (a != 6);
}


