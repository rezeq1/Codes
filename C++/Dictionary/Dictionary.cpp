#include "Dictionary.h"


bool Dictionary::PrintShared()//to check if the are minmum one shared meaning 
{
	int flag = 0;
	for (int i = 0;i < num_words;i++) {
		for (int j = i + 1;j < num_words;j++) {
			if (words[i](words[j])==true)//check if the two meaning are equal
			{
				flag = 1;
				cout << "this words have a partner meaning" << endl;
				cout << words[i] << endl;
				cout << words[j] << endl;
			}
		}
	}
	if (flag == 1)
		return true;
	else
		return false;

}

void Dictionary::Swap_Lexicography()//to sort the words in sort Lexicography
{
	int i, j;
	Dictionary sec = *this;
	String temp;
	
	for (i = 0;i < num_words - 1;++i)
		for (j = i + 1;j < num_words;++j)
		{
			if (words[i].word.strcmp(words[j].word)>0)
			{
				temp = words[i].word;
				words[i].word = words[j].word;
				words[j].word = temp;

			}
		}
}



Dictionary::Dictionary()//def ctor
{
	words = NULL;
	num_words = 0;
}

Dictionary::Dictionary(int a)//ctor
{
	words = new Definition[a];
	num_words = a;

}

Dictionary::~Dictionary()//dtor
{
	delete[]words;
}

Dictionary::Dictionary(const Dictionary &sec)//copy ctor
{
	if (words)
		delete[]words;
	num_words = sec.num_words;
	words = new Definition[num_words];
	for (int i = 0;i < num_words;i++)
		words[i] = sec.words[i];
}

Dictionary & Dictionary::operator=(const Dictionary &sec)
{
	if (sec.words != words)
	{
		if (words)//check if words is empty
			delete[]words;
		num_words = sec.num_words;
		words = new Definition[num_words];
		for (int i = 0;i < num_words;i++)
			words[i] = sec.words[i];//copy the words and the meaning

	}
	return *this;
}

bool Dictionary::operator==(const Dictionary &sec) const//to check if the right Dictionary and to the left Dictionary
{
	int flag = 0;
	if (sec.num_words != num_words)//to check if the two dictionary have the same number of words
	{
		for (int i = 0;i < num_words;i++)
		{
			flag = 0;
			for (int j = 0;j < num_words;j++) {
				if (words[i] == sec.words[j])//check if the words and the meaning are equal
					flag = 1;
			}
			if (flag == 0)
				return false;
		}
	}
	else
		return false;

	return true;
}

Dictionary & Dictionary::operator-=(int a)//to remove the definition in place index
{
	int i, d = 0;
	if (a >= 0 && a < num_words) {//check if the index is illegal
		Dictionary help = *this;
		if (words)
			delete[]words;
		num_words--;
		words = new Definition[num_words];
		for (i = 0;i < num_words + 1;i++)
			if (i != a)
				words[d++] = help.words[i];//copy the words without word in place index
	}
	else
		cout << "the index not found" << endl;


	return *this;
}

Dictionary &Dictionary::operator+=(const Definition &sec)//to add a new definition to  words
{
	int i, flag = 0;
	for (i = 0;i < num_words;i++)
		if (words[i] == sec)//to check if the word is exits
			flag = 1;
	if (flag == 0)
	{
		Dictionary help = *this;
		if (words)
			delete[]words;
		num_words++;
		words = new Definition[num_words];
		for (i = 0;i < num_words - 1;i++)//copy the words and the meanings
			words[i] = help.words[i];
		words[i] = sec;//copy the new word and her meaning

		Swap_Lexicography();
	}
	return *this;
}

Definition & Dictionary::operator[](int index) const//to return the the definition in place index
{
	assert(index >= 0 && index < num_words);
	return words[index];
}

ostream & operator<<(ostream &out, const Dictionary &sec)//to print the words and her meaning for  each word
{
	for (int i = 0;i < sec.num_words;i++)
	{
		out << "word number : " << i + 1 << endl;
		out << sec.words[i];
		out << endl;
	}
	return out;
}

istream & operator>>(istream &inp, Dictionary &sec)//to insert the words and her meaning for  each word
{
	int flag = 0;
	cout << "please enter the number of the words : " << endl;
	inp >> sec.num_words;
	sec.words = new Definition[sec.num_words];
	getchar();
	inp >> sec.words[0];
	for (int i = 1;i < sec.num_words;i++)
	{
		inp >> sec.words[i];//scaning the words and her meaning
		while (flag != i) {
			while (sec.words[i] == sec.words[flag])//to check if the word the insert is exits
			{
				cout << "you have add this Definition before please try again!!!!" << endl;
				inp >> sec.words[i];
			}
			flag++;
		}
		flag = 0;
	}
	sec.Swap_Lexicography();
	return inp;
}
