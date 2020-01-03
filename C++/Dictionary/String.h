
#ifndef __STRING_H__
#define __STRING_H__
#include <assert.h>
#include <iostream>
using namespace std;
class Definition;

class String
{
	char*	str;//array of chars
	int		size;//the size of the array
	void RemoveFor_dot(char**);//remove the unnecessary spaces around '.'
	void RemoveFor_comma(char**);//remove the unnecessary spaces around ','
	void RemoveFor_colon(char**);//remove the unnecessary spaces around ':'
	void ConvetLetters(char**);//convert the letter to her formal letter
	void Remove_Starting_Spaces(char**);//remove the unnecessary spaces in the start of the word
	void Remove_Ending_Spaces(char**);//remove the unnecessary spaces in the end of  the word
	friend class  Definition;
public:
	String() :str(NULL), size(0)
	{}
	String(char*);//ctor
	String(const String&);//copy ctor
	~String();//dtor
	int strlen(char*);//function that calculate the long of an word
	void strcpy(char**, char*);//to copy the right word to the left word
	int strcmp(String);//like the regular strcmp in string

	String& operator = (char* sec);//copy the char* to this
	String& operator=(const String&);//copy the word of string to this
	bool operator==(const String&) const;//check if two words are equal
	bool operator!=(const String&) const;//check if two words are differnat

	friend ostream& operator<<(ostream&, const String&);//print
	friend istream& operator>>(istream&, String&);//insert value


	String& operator -=(const char);//remove the requested char from this
	String& operator+=(const char);//add the char to the end of this

	char& operator[](int) const;//return the letter in place i

	void RemoveSpace();//remove the unnecessary spaces


};


#endif 