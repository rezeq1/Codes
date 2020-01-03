#include"Student.h"
#include <typeinfo>

#define _CRT_SECURE_NO_WARNINGS
#ifndef _MYARR_H
#define _MYARR_H

template<class T>
class MyArr
{
	T *array;
	int size;
public:
	MyArr();//def ctor
	~MyArr();//dtor
	void isType()const;//to print the type of the array
	T*  operator [](int)const;//to return a pointer of the value in the place index
	MyArr & operator +=(const T);//to add a value to the array
	MyArr & operator -=(const T);//to remove a value from the array
	template<class T>
	friend ostream& operator<<(ostream&, const MyArr<T> &);//operator cout
	T* findmax()const;//return a pointer to the max value
	T* findmin()const;//return a pointer to the max value
	bool is_sorted()const;//check if the array sorted

};

template<class T>
inline MyArr<T>::MyArr()
{
	size = 0;
	array = NULL;
}

template<class T>
inline MyArr<T>::~MyArr()
{
	if (array)
		delete[]array;
}


template<class T>
inline void MyArr<T>::isType()const
{
	cout <<"the type is :  " <<typeid(T).name() << endl;//print the type of the array
}

template<class T>
inline T*  MyArr<T>::operator[](int index)const//operatror []
{
	if (index < 0 && index >= size)
		throw  string("the index is out of range");
	else
		return &array[index];
}

template<class T>
inline MyArr<T> & MyArr<T>::operator+=(const T add)//add a value to the array
{
	//the restriction is operator =
	if (size != 0) {
		T *help;
		int i;
		help = new T[size]; //a help array to copy the past values

		for (i = 0;i < size;i++) //copy the past values
			help[i] = array[i];

		delete[]array;  //delete the array
		array = new T[size + 1];

		for (i = 0;i < size;i++) //copy the past value to the array
			array[i] = help[i];
		array[i] = add; //add the new value
		size++;
		delete[]help;
	}
	else {
		array = new T[1]; //if the size was zero
		array[0] = add;
		size++;
	}
	return *this;
}

template<class T>
inline MyArr<T> & MyArr<T>::operator-=(const T inc)
{
	//the restriction is operator = ,operator ==
	if (size == 0)
		throw string("error the organ that you want to remove is not found because the size is zero");
	else {

		int count = 0, c = 0;
		T *help;
		int i;
		for (i = 0; i < size; i++)
			if (array[i] == inc) //count how many time the value appear
				count++;

		if (count == 0) //if the value dosent appear
			throw string("error the organ that you want to remove is not found");

		else {
			help = new T[size];

			for (i = 0; i < size; i++) //copy the past values
				help[i] = array[i];

			delete[]array;
			if ((size - count) != 0) {
				array = new T[size - count]; //build the new size

				for (i = 0; i < size; i++) //copy all the value wiithout the requested value
					if (!(help[i] == inc))
						array[c++] = help[i];

				size -= count;
				delete[]help;

			}
			else
			{
				size = 0; //if the size equal to how many times the value appear
				array = NULL;
			}
		}
	}

	return *this;
}

template<class T>
inline T * MyArr<T>::findmax()const
{
	//the restriction is operator =,operator >
	if (size == 0)
		return NULL;
	T max;
	int index;
	max = array[0]; //give the max the value of the array in place zero
	index = 0;
	for (int i = 1;i < size;i++)
		if (array[i] > max) {//check if the they are value bigger than max
			max = array[i];
			index = i;
		}

	return &array[index];
}

template<class T>
inline T * MyArr<T>::findmin()const
{
	//the restriction is operator =,operator >
	if (size == 0)
		return NULL;
	T min;
	int index;
	min = array[0];//give the min the value of the array in place zero
	index = 0;
	for (int i = 1;i < size;i++)
		if (min > array[i]) {//check if the they are value smaller than min
			min = array[i];
			index = i;
		}

	return &array[index];
}

template<class T>
inline bool MyArr<T>::is_sorted()const
{
	//the restriction is operator >

	if (size == 1 || size == 0)
		return true;

	int flag = 0;
	for (int i = 0;i < size;i++)
		for (int j = i + 1;j < size;j++)
			if (array[i] > array[j]) //check if the values of the array sorted
				flag = 1;
	if (flag == 1)
		return false;
	else
		return true;
}


template<class T>
ostream& operator<< (ostream & output, const MyArr<T>& sec) //operator print
{
	//the restriction is operator cout

	sec.isType();
	output << "the size is : " << sec.size << endl << endl;
	if (sec.size != 0) {
		for (int i = 0; i < sec.size; i++)
			output << sec.array[i] << endl;
	}
	else
		output << "empty array!!!" << endl;


	return output;
}


#endif 