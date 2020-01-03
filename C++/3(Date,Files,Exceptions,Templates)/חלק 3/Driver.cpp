#include"MyArr.h"
#include<stdlib.h>
#include<fstream>

Student InsertStd();
int main()
{
	
	string name, family, id;
	int day, month, year, num;
	float average, help;
	Student new_std1, new_std2;
	MyArr<Student> std1, std2;
	MyArr<float> flt1, flt2;
	ifstream input_flt1("arrfloat1.txt"), input_flt2("arrfloat2.txt");
	ifstream input_Std2("arrstud2.txt"), input_Std1("arrstud1.txt");
	try {//if the files not opend
		if (!input_Std1)
			throw string("error we can not open the file");

		if (!input_Std2)
			throw string("error we can not open the file");

		if (!input_flt2)
			throw string("error we can not open the file");

		if (!input_flt1)
			throw string("error we can not open the file");

	}
	catch(const string & a)
	{
		cout << a << endl;
		exit(1);
	}

	while (!input_Std1.eof())//insert a values fro, file to the opject std1
	{
		input_Std1 >> name;
		input_Std1 >> family;
		input_Std1 >> day;
		input_Std1 >> month;
		input_Std1 >> year;
		input_Std1 >> id;
		input_Std1 >> num;
		input_Std1 >> average;
			std1 += Student(name, family, Date(day, month, year), id, num, average);
	}
	
	while (!input_Std2.eof())//insert a values fro, file to the opject std2
	{
		input_Std2 >> name;
		input_Std2 >> family;
		input_Std2 >> day;
		input_Std2 >> month;
		input_Std2 >> year;
		input_Std2 >> id;
		input_Std2 >> num;
		input_Std2 >> average;
			std2 += Student(name, family, Date(day, month, year), id, num, average);
	}
	while (!input_flt1.eof())//insert a values fro, file to the opject flt1
	{
		input_flt1 >> help;
		flt1 += help;
	}
	while (!input_flt2.eof())//insert a values fro, file to the opject flt2
	{
		input_flt2 >> help;
		flt2 += help;
	}
	
	
		cout << "**********************" << endl;
		cout << "the first object (student): " << endl;
		cout << "**********************" << endl;
		try{
		new_std1 = InsertStd();//add a new student to the array from the user
		std1 += new_std1;//add the new value to the array
	}
	catch (const string &sec)
	{
		cout << sec << endl;
	}
	cout << std1 << endl;//print the array
	if(std1.findmax()==NULL)
		cout << "the array is empty" << endl;
	else
	{
		cout << "**********************" << endl;
		cout << "the minmum of the object is" << endl << *(std1.findmin()) << endl;//print the max value
		cout << "**********************" << endl;
		cout << "the maxmum of the object is" << endl << *(std2.findmax()) << endl;//print the min value
		cout << "**********************" << endl;
	}
	if (std1.is_sorted())
		cout << "the object is sorted" << endl;
	else
		cout << "the object is not sort" << endl;


	cout << "**********************" << endl;
	cout << "the seconde object is(student) : " << endl;
	cout << "**********************" << endl;
	try {
		new_std2 = InsertStd();
		std2 += new_std2;
	}
	catch (const string &sec)
	{
		cout << sec << endl;
	}
	cout << std2 << endl;
	if(std2.findmax()==NULL)
		cout << "the array is empty" << endl;
	else {
		cout << "**********************" << endl;
		cout << "the minmum of the object is" << endl << *(std2.findmin()) << endl;
		cout << "**********************" << endl;
		cout << "the maxmum of the object is" << endl << *(std2.findmax()) << endl;
		cout << "**********************" << endl;
	}
	if (std2.is_sorted())
		cout << "the object is sorted" << endl;
	else
		cout << "the object is not sort" << endl;


	cout << "**********************" << endl;
	cout << "the third object is(float) : " << endl;
	cout << "**********************" << endl;
	cout << "enter a float value to add thim to the end of the array" << endl;
	cin >> help;
	flt1 += help;
	cout << flt1 << endl;
	if(flt1.findmax()==NULL)
		cout << "the array is empty" << endl;
	else {
		cout << "**********************" << endl;
		cout << "the minmum of the object is" << endl << *(flt1.findmin()) << endl;
		cout << "**********************" << endl;
		cout << "the maxmum of the object is" << endl << *(flt1.findmax()) << endl;
		cout << "**********************" << endl;
	}
	if (flt1.is_sorted())
		cout << "the object is sorted" << endl;
	else
		cout << "the object is not sort" << endl;


	cout << "**********************" << endl;
	cout << "the fourth object is(float) : " << endl;
	cout << "**********************" << endl;
	cout << "enter a float value to add thim to the end of the array" << endl;
	cin >> help;
	flt2 += help;
	cout << flt2 << endl;
	if(flt2.findmax()==NULL)
		cout << "the array is empty" << endl;
	else
	{
		cout << "**********************" << endl;
		cout << "the minmum of the object is" << endl << *(flt2.findmin()) << endl;
		cout << "**********************" << endl;
		cout << "the maxmum of the object is" << endl << *(flt2.findmax()) << endl;
		cout << "**********************" << endl;
	}
	if (flt2.is_sorted())
		cout << "the object is sorted" << endl;
	else
		cout << "the object is not sort" << endl;

	

	cout << "enter a float value to remove thim fronm the third object's array" << endl;
	cin >> help;
	try { //use the operator -=
		flt1 -= help;
	}
	catch (const string& sec)
	{
		cout << sec << endl;
	}

	
	
	input_flt1.close();//close the files
	input_flt2.close();
	input_Std1.close();
	input_Std2.close();

	

	system("pause");
	return 0;
}

Student InsertStd()//enter a values to an opject of type Student
{
	string name, family, id;
	int day, month, year, num;
	float average;
	cout << endl << "enter a information of student to add thim to the end of the array " << endl;
	cout << "enter the name" << endl;
	cin >> name;
	cout << "enter the name of family" << endl;
	cin >> family;
	cout << "enter the  day of date born" << endl;
	cin >> day;
	cout << "enter the month of date born" << endl;
	cin >> month;
	cout << "enter the year of date born" << endl;
	cin >> year;
	cout << "enter the id" << endl;
	cin >> id;
	cout << "enter the quantity of marks" << endl;
	cin >> num;
	cout << "enter the average" << endl;
	cin >> average;
		return Student(name, family, Date(day, month, year), id, num, average);

}