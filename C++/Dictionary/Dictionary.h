#include "Definition.h"


class Menu;
class Dictionary
{
	Definition * words;
	int num_words;//number of the words
	friend class Menu;
	bool PrintShared();//to check if the are minmum one shared meaning 
	void Swap_Lexicography();//to sort the words in sort Lexicography
	
public:
	Dictionary();//def ctor
	Dictionary(int);//ctor
	~Dictionary();//dtor
	Dictionary(const Dictionary&);//copy ctor

	Dictionary& operator=(const Dictionary&);//to copy the right Dictionary in to the left Dictionary
	bool operator==(const Dictionary&) const;//to check if the right Dictionary and to the left Dictionary

	friend ostream& operator<<(ostream&, const Dictionary&);//to print the words and her meaning for  each word
	friend istream& operator>>(istream&, Dictionary&);//to insert the words and her meaning for  each word

	Dictionary& operator -=(int);//to remove the definition in place index
	Dictionary& operator +=(const Definition &);//to add a new definition to  words

	Definition& operator[](int) const;//to return the the definition in place index


};
