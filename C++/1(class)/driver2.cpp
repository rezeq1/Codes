#include"OrderedSet.h"


int main()
{
	int *arr1,size,i, *arr2, *arr3;

	cout << "Creating a OrderedSet orderedSet1 with the following parameters:" << endl<<"Enter size1 :"<<endl;
	cin >> size;
	arr1 = new int[size];//alloctaing memory
	cout << "Enter the elemnt of the group" << endl;
	for (i = 0;i < size;i++)
		cin >> arr1[i];//insert the numbers to the array
	OrderedSet group1(arr1, size);
	cout << "Printing the OrderedSet orderedSet1:" << endl;
	group1.Print();
	cout << "************************************************************" << endl;

	cout << "Creating a OrderedSet orderedSet2 with the following parameters:" << endl << "Enter size2 :" << endl;
	cin >> size;
	arr2 = new int[size];//alloctaing memory
	cout << "Enter the elemnt of the group" << endl;
	for (i = 0;i < size;i++)
		cin >> arr2[i];//insert the numbers to the array
	OrderedSet group2(arr2, size);
	cout << "Printing the OrderedSet orderedSet2:" << endl;
	group2.Print();
	cout << "************************************************************" << endl;


	cout << "Creating empty orderedSet orderedSet3 without parameters " << endl;
	OrderedSet group3;
	cout << "Printing the OrderedSet orderedSet3" << endl;
	group3.Print();

	cout << "************************************************************" << endl;

	cout << "calculating the difference of orderedSet1 and orderedSet2" << endl;
	OrderedSet diff12 = group1.Diff(group2);
	diff12.Print();

	cout << "************************************************************" << endl;



	cout << "calculating the difference of orderedSet1 and orderedSet3" << endl;
	OrderedSet diff13 = group1.Diff(group3);
	diff13.Print();

	cout << "************************************************************" << endl;


	cout << "calculating the intersection of orderedSet1 and orderedSet2" << endl;
	OrderedSet inter12 = group1.Intersection(group2);
	inter12.Print();

	cout << "************************************************************" << endl;



	cout << "calculating the intersection of orderedSet1 and orderedSet3 " << endl;
	OrderedSet inter13 = group1.Intersection(group3);
	inter13.Print();

	cout << "************************************************************" << endl;

	cout << "calculating the union of orderedSet1 and orderedSet2 " << endl;
	OrderedSet union12 = group1.Union(group2);
	union12.Print();

	cout << "************************************************************" << endl;

	cout << "calculating the union of orderedSet2 and orderedSet3 " << endl;
	OrderedSet union23 = group2.Union(group3);
	union23.Print();

	cout << "************************************************************" << endl;

	if (group1.Contain(group3))
		cout << "orderedSet1 contains orderedSet3" << endl;
	else
		cout << "orderedSet1 doesn't contains orderedSet3" << endl;

	cout << "************************************************************" << endl;

	if (group2.Contain(group1))
		cout << "orderedSet2 contains orderedSet1" << endl;
	else
		cout << "orderedSet2 doesn't contain orderedSet1 " << endl;




	system("pause");

	return 0;
}
