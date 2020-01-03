#include"Student.h"

int main()
{
	char name[51];
	int milge, No_Of_Courses;
	long id;
	//insert student information 
	cout << "Enter  name" << endl;
	
	cin.getline(name,51);
	cout << "Enter Id" << endl;
	cin >> id;
	cout << "Enter  milga" << endl;
	cin >> milge;
	cout << "Enter  number of courses" << endl;
	cin >> No_Of_Courses;
	Student std1(name, id, No_Of_Courses, milge);
	std1.PrintInformation();
	No_Of_Courses = std1.GetNumberOfCourses();
	cout << "number of courses is " << No_Of_Courses << endl;
	cout << "Update number of courses " << endl;//updating number of courses
	cin>> No_Of_Courses;
	if (No_Of_Courses >= 0)
		std1.SetNumberOfCourses(No_Of_Courses);
	else
		std1.SetNumberOfCourses(0);
	std1.PrintInformation();
	cout << " Update milga"  << endl;//updating milga
	cin >> milge;
	if (milge >= 0)
		std1.SetMilga(milge);
	else
		std1.SetMilga(0);
	std1.PrintInformation();
	
	//insert information to the seconde stduent

	cout << endl<<"***************************************************************" << endl;
	cout << "Enter information to the seconde stduent" << endl;
	cout << "Enter  name" << endl;
	getchar();
	cin.getline(name, 51);
	cout << "Enter Id" << endl;
	cin >> id;
	cout << "Enter  milga" << endl;
	cin >> milge;
	cout << "Enter  number of courses" << endl;
	cin >> No_Of_Courses;
	Student std2(name, id, No_Of_Courses, milge);
	std2.PrintInformation();
	No_Of_Courses = std2.GetNumberOfCourses();
	cout << "number of courses is " << No_Of_Courses << endl;
	cout << "Update number of courses " << endl;//updating number of courses
	cin>> No_Of_Courses;
	if (No_Of_Courses >= 0)
		std2.SetNumberOfCourses(No_Of_Courses);
	else
		std2.SetNumberOfCourses(0);
	std2.PrintInformation();
	cout << " Update milga"  << endl;//updating milga
	cin >> milge;
	if (milge >= 0)
		std2.SetMilga(milge);
	else
		std2.SetMilga(0);
	std2.PrintInformation();




	system("pause");





	return 0;
}