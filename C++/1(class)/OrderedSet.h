#include<iostream>
using namespace std;

class OrderedSet
{
	int* group;
	int size;
	int	Check(int*,int,int);//a help function to check how many times appears a number in an array

public:
	OrderedSet(int*, int);//ctor 
	OrderedSet():group(NULL),size(0){}//defualt ctor 
	OrderedSet(const OrderedSet&);//copy ctor
	~OrderedSet();//dtor 
	int* ChangeGroup(int*, int*);//function to check if the array is a representative a group ,sort the array from the smallest to the biggest and they remove the repeated numbers
	bool Contain(OrderedSet&);//function that check if the group contain in the other group
	bool Contain(int);//function that check if number contain in the  group
	bool CheckEmpty();//check if the group is empty
	bool CheckEquals(OrderedSet &);//check if two groups are equals
	OrderedSet  Union(OrderedSet &);//function that return the unions group of the two groups 
	OrderedSet  Diff(OrderedSet &);//function that return the diff group of the two groups 
	OrderedSet  Intersection(OrderedSet &);//function that return the Intersections group of the two groups 
	int* GetGroup();//function to get the address of the group
	int GetSize();//function to get the size of the group
	void Print();//function to print a group

	

};
