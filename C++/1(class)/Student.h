#include<iostream>
#include<string>
using namespace std;

class Student {
	char name_student[51];
	long id;
	int number_courses;
	int milga;

public:
	Student(char[], long, int, int);//ctor
	Student() :name_student("empty"), id(0), number_courses(0), milga(0) {}//default ctor
	Student(const Student&);//copy ctor
	~Student() {}//dtor
	int GetMilga();//to get the value of the variable milga
	int GetNumberOfCourses();//to get the number of the courses
	long GetId();//to get the student id 
	char* GetName();//to get the student name
	void SetMilga(int);//to set an value to the variable milga
	void SetNumberOfCourses(int);//to change the number of the courses
	void SetId(long);//to set id to student
	void SetName(char*);//to set a name to student
	int CalculateTuition();//Calculate Tuition fee
	void PrintInformation();//print all of the information of the student



};