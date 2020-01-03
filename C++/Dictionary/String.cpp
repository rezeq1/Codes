
#include "String.h"
#include <assert.h>




void String::ConvetLetters(char **a)//convert the letter to her formal letter
{
	int i = 1;


	if ((*a)[0] >= 'a' && (*a)[0] <= 'z')//convert the first letter to captial letter
		(*a)[0] -= 32;



	while ((*a)[i] != '\0')//conver all the letter to small letter without the first letter
	{
		if ((*a)[i] >= 'A' && (*a)[i] <= 'Z')
			(*a)[i] += 32;
		if ((*a)[i] == '.')//convert the first letter after dot to captial letter
		{
			if ((*a)[i+1] >= 'a' && (*a)[i+1] <= 'z')
				(*a)[i+1] -= 32;
		}
		i++;
	}
}

void String::Remove_Starting_Spaces(char **a)//remove the unnecessary spaces in the start of  the word
{
	int i, c = 0, d = 0, f = 0, len;
	len = strlen(*a);
	char*buffer = NULL;
	strcpy(&buffer, *a);//copy the word


	delete[](*a);

	while (buffer[c] == ' ')//check if they are spaces in the first of the word
	{
		c++;
	}
	*a = new char[len - c + 1];
	for (i = c; i < len; i++)
	{
		(*a)[d++] = buffer[i];
	}
	(*a)[d] = '\0';
	delete[]buffer;
}

void String::Remove_Ending_Spaces(char **a)//remove the unnecessary spaces in the end of  the word
{
	int i = strlen(*a) - 1;
	int len = i + 1, c = 0, d = 0;
	char*buffer = NULL;
	strcpy(&buffer, *a);//copy the word

	delete[](*a);
	while (buffer[i] == ' ')//check if they are spaces in the end of the word
	{
		c++;
		i--;
	}
	*a = new char[len - c + 1];
	for (d = 0; d < len - c; d++)
	{
		(*a)[d] = buffer[d];
	}
	(*a)[d] = '\0';
	delete[]buffer;
}



void String::RemoveFor_dot(char **a)//remove the unnecessary spaces around '.'
{

	int len = strlen(*a);
	int i, c = 0, d = 0;
	char*buffer = NULL;
	strcpy(&buffer, *a);
	delete[](*a);
	for (i = 0; i < len; i++)
	{
		if (buffer[i] == '.')//check if they are unnecessary spaces around '.'
		{
			//calculate the size without spaces
			if (buffer[i - 1] == ' ')

				c++;



			if (buffer[i + 1] == ' ')
				c++;


		}
	}
	*a = new char[len - c + 1];//alocate memory

	for (i = 0; i < len; i++)
	{

		if (buffer[i] == ' ')//copy the word without spaces
		{
			if (buffer[i + 1] == '.')
				i++;
			if (buffer[i - 1] == '.')
				i++;
		}
		(*a)[d++] = buffer[i];

	}
	(*a)[d] = '\0';


	delete[]buffer;




}

void String::RemoveFor_comma(char ** a)//remove the unnecessary spaces around  ','
{

	int len = strlen(*a);
	int i, c = 0, d = 0;
	char*buffer = NULL;
	strcpy(&buffer, *a);
	delete[](*a);
	for (i = 0; i < len; i++)//check if they are unnecessary spaces around ','
	{
		if (buffer[i] == ',')
		{
			//calculate the size without spaces
			if (buffer[i - 1] == ' ')

				c++;



			if (buffer[i + 1] == ' ')
				c++;


		}
	}
	*a = new char[len - c + 1];//alocate memory

	for (i = 0; i < len; i++)
	{

		if (buffer[i] == ' ')//copy the word without spaces
		{
			if (buffer[i + 1] == ',')
				i++;
			if (buffer[i - 1] == ',')
				i++;
		}
		(*a)[d++] = buffer[i];

	}
	(*a)[d] = '\0';


	delete[]buffer;
}

void String::RemoveFor_colon(char **a)//remove the unnecessary spaces around ':'
{
	int len = strlen(*a);
	int i, c = 0, d = 0;
	char*buffer = NULL;
	strcpy(&buffer, *a);
	delete[](*a);
	for (i = 0; i < len; i++)//check if they are unnecessary spaces around ':'
	{
		if (buffer[i] == ':')
		{
			//calculate the size without spaces
			if (buffer[i - 1] == ' ')

				c++;



			if (buffer[i + 1] == ' ')
				c++;


		}
	}
	*a = new char[len - c + 1];//alocate memory

	for (i = 0; i < len; i++)
	{

		if (buffer[i] == ' ')//copy the word without spaces
		{
			if (buffer[i + 1] == ':')
				i++;
			if (buffer[i - 1] == ':')
				i++;
		}
		(*a)[d++] = buffer[i];

	}
	(*a)[d] = '\0';


	delete[]buffer;

}


String::String(char* flag)
{


	if (flag) {
		size = strlen(flag);
		str = new char[size + 1];
		strcpy(&str, flag);
		RemoveSpace();
	}
	else {
		str = NULL;
		size = 0;
	}
}


String::String(const String& sec)//copy ctor
{

	size = sec.size;
	if (sec.str)
	{
		str = new char[size + 1];
		strcpy(&str, sec.str);
	}
	else
		str = NULL;
}


String::~String()//dtor
{
	if (str)
	{
		delete[] str;
		str = NULL;
	}
	size = 0;
}


int String::strlen(char *st)//function that calculate the long of an word
{

	int i;
	for (i = 0; st[i] != '\0'; i++)
		;
	return i;
}

void String::strcpy(char ** a, char *b)//to copy the right word to the left word
{
	if ((*a) != NULL) {
		delete[](*a);
	}
	*a = new char[strlen(b) + 1];
	int i = 0;
	while (b[i] != '\0')
	{
		(*a)[i] = b[i];
		i++;
	}
	(*a)[i] = '\0';
}

int String::strcmp( String st2)
{
	int  i = 0,flag=0;
	while (flag == 0)
	{
		if (str[i] > st2.str[i])
		{
			flag = 1;
		}
		else if (str[i] < st2.str[i])
		{
			flag = -1;
		}
		else
		{
			i++;
		}
	}
	return flag;
}

String & String::operator=(char * sec)//copy the char* to this
{
	if (str != sec)//check if they are self placement
	{
		if (str)
		{
			delete[] str;
			str = NULL;
		}
		size = strlen(sec);
		if (sec)
		{
			str = new char[size + 1];//alocate memory
			strcpy(&str, sec);//copy the word
		}
	}

	return *this;
}



String& String::operator = (const String& sec)//copy the word of string to this
{
	if (this != &sec)//check if they are self placement
	{
		if (str)
		{
			delete[] str;
			str = NULL;
		}
		size = sec.size;
		if (sec.str)
		{
			str = new char[size + 1];
			strcpy(&str, sec.str);
		}
	}

	return *this;
}

bool String::operator == (const String& s2) const//check if two words are equal
{
	if (size == s2.size)
	{
		for (int i = 0; i < size; i++)
			if (str[i] != s2.str[i])
				return false;

		return true;
	}
	else
		return false;
}

bool String::operator != (const String& s) const//check if two words are differnat
{
	return !((*this) == s);
}

ostream& operator << (ostream& out, const String& sec)//print
{

	if (sec.str) {
		out << sec.str;
	}

	return out;
}



istream& operator >> (istream& input, String& sec)//insert value
{
	char buffer[80];
	input.getline(buffer, 80 + 1);
	sec.size = strlen(buffer);
	sec.strcpy(&sec.str, buffer);
	return input;
}

String& String::operator += (const char st)//add the char to the end of this
{
	if (str != NULL)
	{
		char *buffer;
		buffer = new char[size + 1];
		strcpy(&buffer, str);
		delete[]str;
		size++;
		str = new char[size + 1];
		strcpy(&str, buffer);
		str[size - 1] = st;
		str[size] = '\0';
		delete[]buffer;
	}
	else {
		size = 1;
		str = new char[size + 1];
		str[0] = st;
		str[1] = '\0';
	}
	return *this;
}

String& String::operator -= (const char st)//remove the requested char from this
{
	int count = 0, i, c = 0;
	char *buffer;
	if (size != 0)
	{
		for (i = 0; i < size; i++)
			if (str[i] == st)
				count++;
		buffer = new char[size + 1];
		strcpy(&buffer, str);
		delete[]str;
		str = new char[size - count + 1];
		for (i = 0; i < size; i++)
		{
			if (buffer[i] != st)
				str[c++] = buffer[i];
		}
		str[c] = '\0';
		delete[]buffer;

	}

	return *this;

}



char& String::operator [] (int index) const//return the letter in place i
{
	assert(index >= 0 && index < size);
	return str[index];
}





void String::RemoveSpace()//remove the unnecessary spaces
{
	int i = 0, count = 0, c = 0;
	char *buffer = NULL;
	Remove_Starting_Spaces(&str);
	Remove_Ending_Spaces(&str);
	if (size != 0) {

		strcpy(&buffer, str);
		delete[]str;

		for (i = 0; i < size; i++)
		{
			if (buffer[i] == ' ')
			{
				while (buffer[i + 1] == ' ')
				{
					count++;
					i++;
				}
			}
		}
		str = new char[size - count + 1];
		for (i = 0; i < size; i++)
		{
			str[c++] = buffer[i];
			if (buffer[i] == ' ')
			{
				while (buffer[i + 1] == ' ')
				{
					count++;
					i++;
				}
			}
		}
		str[c] = '\0';
		size = size - count;
	}
	RemoveFor_dot(&str);
	RemoveFor_comma(&str);
	RemoveFor_colon(&str);
	ConvetLetters(&str);


	delete[]buffer;
}

