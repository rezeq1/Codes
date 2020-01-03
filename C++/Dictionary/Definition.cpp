#include "Definition.h"


char * Definition::GetWord() const//to get the word
{

	return word.str;
}

void Definition::Swap_Lexicography1(String*sec,int godl)//to sort the means in sort Lexicography 
{
	int i, j;
	String temp;
	
	for(i=0;i< godl -1;++i)
		for (j = i + 1;j < godl;++j)
		{
			if (sec[i].strcmp(sec[j]) > 0)
			{
				temp = sec[i];
				sec[i]= sec[j];
				sec[j]=temp;

			}
		}
}



Definition::Definition()//def ctor
{
	word.str = NULL;
	means = NULL;
	num = 0;
}

Definition::Definition(char *word1, int num1)//ctor
{

	means = new String[num1];
	word = word1;
	word.RemoveSpace();
	num = num1;


}

Definition::~Definition()//dtor
{
	delete[]means;
}

Definition::Definition(const Definition &sec)//copy ctor
{
	means = new String[sec.num];
	num = sec.num;
	word = sec.word;
	for (int i = 0;i < num;i++)
		means[i] = sec.means[i];
	
}

Definition & Definition::operator=(const Definition &sec)//to copy the right Definition in to the left Definition
{
	if (this != &sec)//check if they are self placement
	{
		means = new String[sec.num];
		num = sec.num;
		word = sec.word;//copy the word
		word.RemoveSpace();
		for (int i = 0;i < num;i++) {//copy the meaning 
			means[i] = sec.means[i];
			means[i].RemoveSpace();
		}
		
	}
	return *this;
}



bool Definition::operator==(const Definition &sec) const//to check if the right Definition and the left Definition has the same word
{
	if (word == sec.word)
		return true;
	else
		return false;
}

bool Definition::operator()(const Definition &sec) const//to check if the are minmum one shared meaning 
{
	for(int i=0;i<num;i++)
		for (int j = 0;j < sec.num;j++)
		{
			if (means[i] == sec.means[j])//check if the two meaning are equal
				return true;
		}
	return false;
}

Definition & Definition::operator-=(int a)//to remove the meaning number index 
{
	int d = 0;
	if (means) {//ceck if means are empty
		if (a >= 0 && a < num)//check if the index is illegal
		{
			Definition flag(*this);
			delete[]means;
			means = new String[num - 1];
			for (int i = 0;i < num;i++)
			{
				if (i != a)//copy all the meaning without meaning number index
					means[d++] = flag.means[i];

			}
			num--;
		}
	}
	return *this;
}

Definition & Definition::operator+=(String a)//to add a new meaning to the word
{
	int i, Flg = 0;
	for (i = 0;i < num;i++)
		if (means[i] == a)//to check if the meaning is exits
			Flg = 1;
	if (Flg == 0)
	{
		Definition flag(*this);
		delete[]means;
		means = new String[num + 1];
		for (i = 0;i < num;i++)//to copy the meaning
			means[i] = flag.means[i];
		means[i] = a;//copy the new meaning
		num++;
		Swap_Lexicography1(means,num);
	}
	return *this;
}

String & Definition::operator[](int index) const//to return the the meaning number index
{
	assert(index >= 0 && index < num);
	return means[index];
}

ostream & operator<<(ostream &out, const Definition &sec)//to print the the word and her meaning
{
	if (sec.GetWord()) {
		cout << "the word is" << endl;
		out << sec.word << endl;
		out << "number of the definition is : ";
		out << sec.num << endl;
		if (sec.num != 0)
		{
			for (int i = 0;i < sec.num;i++)
				out << sec[i] << endl;
		}
	}

	return out;




}

istream & operator>>(istream &inp, Definition &sec)//to insert  word and her meaning
{
	int flag = 0;
	cout << "please enter a word" << endl;
	inp >> sec.word;//insert the word
	sec.word.RemoveSpace();//remove the unnecessary spaces
	cout << "please enter the number of the Definition" << endl;
	inp >> sec.num;//insert the size of the meaning
	sec.means = new String[sec.num];
	getchar();
	cout << "enter the definition number 0 "<< endl;
		inp >> sec.means[0];
		sec.means[0].RemoveSpace();

	for (int i = 1;i < sec.num;i++)//insert the meaning
	{
		cout << "enter the definition number " << i << endl;
		inp >> sec.means[i];
		sec.means[i].RemoveSpace();
		while (flag != i)
		{
			while (sec.means[i] == sec.means[flag])
			{
				cout << "you have enterd this meaning before please try again!!!!" << endl;
				inp >> sec.means[i];
				sec.means[i].RemoveSpace();
			}
			
		flag++;
		}
		flag = 0;
	}
	sec.Swap_Lexicography1(sec.means,sec.num);
	return inp;


}
