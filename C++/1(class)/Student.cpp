#include"Student.h"


Student::Student(char* name, long id_student, int number_of_courses, int melga_student)//ctor
{
	SetName(name);//set name
	SetId(id_student);//set id 
	if(number_of_courses<0)//check if the number of the courses is positive
		SetNumberOfCourses(0);
	else
	SetNumberOfCourses(number_of_courses);
	if (melga_student < 0)//checing the milga value
		SetMilga(0);
	else
	SetMilga(melga_student);

}



Student::Student(const Student& std)//copy ctor
{

	int i = 0;
	while (std.name_student[i] != '\0')//a loop to copy the name like strcpy
	{
		name_student[i] = std.name_student[i];
		i++;
	}
	name_student[i] = '\0';
	id=std.id;
	number_courses=std.number_courses;
	milga= std.milga;

}

int Student::GetMilga()
{
	return milga;//returns the milga value
}

int Student::GetNumberOfCourses()
{
	return number_courses;//returns number of student courses
}

long Student::GetId()
{
	return id;//returns student id
}

char* Student::GetName()
{
	return name_student;//returns the name of the student
}

void Student::SetMilga(int number)
{
	milga = number;//set milga
}

void Student::SetNumberOfCourses(int number)
{
	number_courses = number;//set number of courses
}

void Student::SetId(long number)
{
	id = number;//set id 
}

void Student::SetName(char* name)
{
	int i = 0;
	while (name[i] != '\0')//loop like srtcpy
	{
		name_student[i] = name[i];
		i++;
	}
	name_student[i] = '\0';
}

int Student::CalculateTuition()//Calculate Tuition fee
{
	int tuition;
	tuition = number_courses * 1500 - milga;
	if (tuition < 0)
		return 0;
	else
		return tuition;
}

void Student::PrintInformation()//Print all of the student Information
{

	cout << "student name : " << name_student << ",ID :" << id << ",number of courses : " << number_courses << ", milga " << milga << endl;
	cout << " the tuition is : " << CalculateTuition() << endl;

}