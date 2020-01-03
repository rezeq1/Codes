#include"String.h"


class Definition
{
	String word;
	String *means;
	int num;//size of means
	char* GetWord()const;//to get the word
	void Swap_Lexicography1(String*,int);//to sort the means in sort Lexicography 
	friend class  Dictionary;
public:
	Definition();//def ctor
	Definition(char*, int);//ctor
	~Definition();//dtor
	Definition(const Definition&);//copy ctor

	Definition& operator=(const Definition&);//to copy the right Definition in to the left Definition
	bool operator==(const Definition&) const;//to check if the right Definition and the left Definition has the same word

	friend ostream& operator<<(ostream&, const Definition&);//to print the the word and her meaning
	friend istream& operator>>(istream&, Definition&);//to insert  word and her meaning
bool operator () (const Definition&) const;//to check if the are minmum one shared meaning 
	Definition& operator -=(int index);//to remove the meaning number index 
	Definition& operator+=(String);//to add a new meaning to the word

	String& operator[](int index) const;//to return the the meaning number index
};
