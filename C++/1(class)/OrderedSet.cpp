#include"OrderedSet.h"

int OrderedSet::Check(int*arr, int size1, int num)//a help function to check how many times appears a number in an array
{
	int c = 0;
	for (int j = 0;j < size1;j++)
		if (arr[j] == num)
			c++;
	return c;//how many times the number appear in the array

}


OrderedSet::OrderedSet(int*arr, int size1)//ctor
{
	
		int *ar2 = ChangeGroup(arr, &size1);//changing the array to a group
		if (ar2 == NULL)//if the array representative a group
		{
			cout << "The array is a group" << endl;
			group = arr;
			size = size1;
		}
		else//if the array dosent representative a group
			group = ar2;
		size = size1;
		


}

int* OrderedSet::ChangeGroup(int*arr, int* size1_)//function to check if the array is a representative a group ,sort the array from the smallest to the biggest and they remove the repeated numbers
{

		int temp, i, j, count = 0, flag = 0, *ar2, c = 0;
		int size1 = *size1_;
		for (i = 0; i < size1; ++i)//sort the array from the smallest to the biggest 
		{
			for (j = i + 1; j < size1; ++j)
				if (arr[i] > arr[j])
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
		}


		for (i = 0; i < size1; i += count)//calculate the size of the group,and remove the repeated numbers
		{
			count = Check(arr, size1, arr[i]);
			if (count != 1)
				flag = flag + count;
		}
		
			flag = (flag + 1) / 2;
			flag = size1 - flag;
			*size1_ = flag;
		
		


			if (flag != size1)
			{
				count = 0;
				ar2 = new int[flag];
				for (i = 0; i < size1; i += count)
				{
					count = Check(arr, size1, arr[i]);
					ar2[c++] = arr[i];
				}
				delete[]arr;//deleting the memory 
			}
			else
				return NULL;

		return ar2;



}



OrderedSet::OrderedSet(const OrderedSet& ordered)//copy ctor
{
	size = ordered.size;//copy the size
	this->group=new int[size];//copy the numbers
	for (int i = 0;i < size;i++)
		group[i] = ordered.group[i];
	

}

OrderedSet::~OrderedSet()//dtor
{
	if (group)
		delete []group;//delete the memory 
}

bool OrderedSet::Contain(OrderedSet& group2)//function that check if the group contain in the other group
{
	int size1 = group2.GetSize();
	if (size1 != 0) {
		int *group1 = group2.GetGroup();
		int count = 0;
		for (int i = 0;i < size1;i++)
			for (int j = 0;j < size;j++)
				if (group1[i] == group[j])//calculate how many numbers of group2 appears in group
					count++;
		if (count == size1)//checking if group contains group2 
			return true;
		else
			return false;
	}
	else
		return true;
}

bool OrderedSet::Contain(int number)//function that check if the number contain in  group
{
	for (int i = 0;i < size;i++)
		if (group[i] == number)
			return true;
	return false;
}

bool OrderedSet::CheckEmpty()//check if the group is empty
{
	if (size == 0)
		return true;
	else
		return false;
}

bool OrderedSet::CheckEquals( OrderedSet & group_one)//check if two groups are equals
{
	int c = 0;
	int size1 = group_one.GetSize();
	int*group1 = group_one.GetGroup();
	if (size != size1)//checking if the two sizes are simallar
		return false;
	for (int i = 0;i < size;i++)
		if (group[i] == group1[i])//checking if the numbers of the two groups are simallar
			c++;
	if (c = size)
		return true;
	else
		return false;
}



OrderedSet  OrderedSet::Union(OrderedSet & group_one)//function that return the unions group of the two groups 
{
	int size2 = group_one.GetSize();
	int*group2 = group_one.GetGroup();
	int i, j, size3 = size + size2;
	int *group3, flag = 0, c = 0;

	for (i = 0; i < size2; i++)//calculate the size of the nuion group
		for (j = 0; j < size; j++)
		{
			if (group2[i] == group[j])
			{
				size3--;
			}
		}
	

	group3 = new int[size3];//allocating memory to the union group


	for (i = 0; i < size; i++)//copy the numbers of group to the union group
		group3[i] = group[i];


	for (i = 0; i < size2; i++)//copy the numbers of the union to the union group
	{
		flag = 0;
		for (j = 0; j < size; j++)
		{
			if (group2[i] == group[j])
			{
				flag = 1;
			}
		}
		if (flag == 0)
			group3[(c++)+size] = group2[i];
	}
	OrderedSet g4(group3, size3);
	return g4;//returned the object

}

OrderedSet  OrderedSet::Diff(OrderedSet & group_one)//function that return the diff group of the two groups 
{
	int i, j, c = 0, flag = 0, size3 = size;
	OrderedSet g4;
	int size2 = group_one.GetSize();
	int*group2 = group_one.GetGroup();

	for (i = 0; i < size; i++)//calculate the size of the diff group
		for (j = 0; j < size2; j++)
			if (group[i] == group2[j])
				size3--;
	g4.size = size3;

	g4.group = new int[size3];//allocating memory to the diff group




	for (i = 0; i < size; i++)//copy the numbers of the diff to the diff group
	{
		flag = 0;
		for (j = 0; j < size2; j++)
			if (group[i] == group2[j])
				flag = 1;
		if (flag == 0) 
			g4.group[c++] = group[i];
			
	}
	
	return g4;//returned the object

}

OrderedSet  OrderedSet::Intersection(OrderedSet & group_one)
{
	int i, j, c = 0, size3= 0, *group3 ;
	int size2 = group_one.GetSize();
	int*group2 = group_one.GetGroup();
	for (i = 0; i < size; i++)//calculate the size of the Intersection group
	{
		for (j = 0; j < size2; j++)
		{
			if (group[i] == group2[j])
				size3++;
		}
	}
	
	group3 = new int[size3];//allocating memory to the Intersection group

	for (i = 0; i < size; i++)//copy the numbers of the Intersection to the diff group
	{
		for (j = 0; j < size2; j++)
		{
			if (group[i] == group2[j])
			{
				group3[c++] = group[i];
			}
		}
	}
	OrderedSet g4(group3, size3);
	return g4;//returned the object

}




int* OrderedSet::GetGroup()//function to get the address of the group
{
	return group;
}

int OrderedSet::GetSize()//function to get the size of the group
{
	return size;
}

void OrderedSet::Print()//function to print a group
{
	if (size != 0) {
		cout << "{";
		for (int i = 0;i < size - 1;i++)
			cout << group[i] << ",";

		cout << group[size - 1] << "}" << endl;
	}
	else
		cout << "{ }"<<endl;

}

