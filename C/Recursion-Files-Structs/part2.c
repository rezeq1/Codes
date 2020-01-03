/* Assignment : 5
    Campus Beer Sheva 
    Author : Rezeq Abo  madeghem , ID 211606801
*/


#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#define SIZE 20  //the maximum size of the name 
#define NUMBER 5 //the number of the platoons in the factory
typedef enum
{
    True,
    False
} BOOL;//enum that have the values of the bool

typedef struct//definition of struct that include a pointer to name and the salary of an employee and the platoon number in the fuctory ,in name employee
{
    char *name;
    float salary;
    int PlatoonNumber;

} Employee;

BOOL intiEmployee(Employee *);//functon that absorbs from the user a data to the struct employee. name and her salary and the number of the platoon number  
void calcAverages(Employee *data, int size, float *result);//the function takes an array of the struct employee and her size and fill the array result the average of every platoon respectively 
float Avereg(Employee *data, int size, int platoon);//function that takes an array of the struct employee and  her size and the number of the platoon and calculate the average of the platoon
int buildFactory(Employee **pdata);//the function takes an address of an array of the struct employee and scaning the number of the employees in the function and allocation memory to the array
void PrintEmployee(Employee *emp, int size);//the function takes an array of the struct employee and her size and prints all of the employees information
void PrintAverage(float *result);//function that takes an array of the average of every platoon and prints average of every platoon respectively

int main()
{
    Employee *employee = NULL;
    float array[NUMBER];//an array that include the average of the employee's salary of the platoons in the fuctory
    int size,i;
    size = buildFactory(&employee);//save the number of the emplyoees in the factory
    PrintEmployee(employee, size);

    calcAverages(employee, size, array);
    PrintAverage(array);
    for(i=0;i<size;i++)
        free(employee[i].name);//release the memory of the pointer name in the struct
    free(employee);//release the memory of the pointer emplyoee 
   employee[i].name=NULL;//rest the pointer name in the struct 
   employee=NULL;//rest the the pointer emplyoee

    return 0;
}

/////////////////////////////////////////////////////////////////////////

BOOL intiEmployee(Employee *employee)//functon that absorbs from the user a data to the struct employee. name and her salary and the number of the platoon number  
{
    char buffer[SIZE + 1];

    printf("Please enter the name of the  employee \n");
    scanf("%s", buffer);//inters a name of the employee
    getchar();//remove the char enter

    employee->name = (char *)malloc((strlen(buffer) + 1));//allocation memory to pointer name
    if(employee->name==NULL)
    {
    printf("the are no memory \n");
    return False;    
    }
    strcpy(employee->name, buffer);//copy the name to the pointer name

    printf("Please enter the salary of the employee \n");
    scanf("%f", &employee->salary);//inters the salary of the employee

    printf("Please enter the  platoon number of the employee \n");
    scanf("%d", &employee->PlatoonNumber);//inters the platoon number  of the employee

    while (employee->PlatoonNumber < 1 || employee->PlatoonNumber > 5)//checking if the platoon number is llegal
    {
        printf("The platoon number is illegal please enter again \n");
        scanf("%d", &employee->PlatoonNumber);
    }
    if(employee->name!=NULL)
    return True;
}
/////////////////////////////////////////////////////////////////////////////




float Avereg(Employee *employee, int size, int platoon)//function that takes an array of the struct employee and  her size and the number of the platoon and calculate the average of the platoon
{
    float sum = 0.0;
    int count = 0, i;
    for (i = 0; i < size; i++)
        if (employee[i].PlatoonNumber == platoon)
        {
            sum += employee[i].salary;//count the average of the platton 
            count++;
        }
    if (count == 0)//checking if the are no employee
        return -1;
    else
        return (float)(sum / count);//returns the average

}

//////////////////////////////////////////////////////////////////////////////////////

void calcAverages(Employee *data, int size, float *result)//the function takes an array of the struct employee and her size and fill the array result the average of every platoon respectively
{
    int i;

    for (i = 0; i < NUMBER; i++)
        result[i] = Avereg(data, size, i + 1);//fill the array result the average of every platoon respectively
}
//////////////////////////////////////////////////////////////////////////////////////


int buildFactory(Employee **pdata)//the function takes an address of an array of the struct employee and scaning the number of the employees in the function and allocation memory to the array
{
    int i, size;
    printf("Please enter the number of the employee in the factory : \n");
    scanf("%d", &size);//scaning the number of the employees
    *pdata = (Employee *)malloc(size * sizeof(Employee));//allocation memory to the array of the employees
    if (*pdata == NULL)//checking if the are enough memory
    {
        printf("They are no enuogh memory \n ");
        exit(1);//exit from the function 
    }
    for (i = 0; i < size; i++)
    {
        printf("Please enter the information of the employee number %d:\n", i + 1);
        if(intiEmployee(&(*pdata)[i])==True)//fill the information of all the employees in the factory
        ;
    }

    return size;//returns the number of the employees
}

/////////////////////////////////////////////////////////
void PrintEmployee(Employee *employee, int size)//the function takes an array of the struct employee and her size and prints all of the employees information
{
    printf("\n************ Employees ************* \n");
    for (int i = 0; i < size; i++)
    {
        printf("The information of the employee number %d : \n", i + 1);
        printf("The name is %s \n", employee[i].name);//prints the name of the employee
        printf("The number of the platoon is %d \n", employee[i].PlatoonNumber);//prints the number of the platoon  of the employee
        printf("The amount of the salary  is %.2f \n\n", employee[i].salary);//prints the salary of the employee
    }
}

///////////////////////////////////////////////////////////
void PrintAverage(float *result)//function that takes an array of the average of every platoon and prints average of every platoon respectively
{
    for (int i = 0; i < NUMBER; i++)
    {
        if (result[i] == -1)//checking if they are no employees in the platoon
            printf("The are no employee in the platoon %d \n",i+1);
        else
            printf("The average of the employees's salary  in the platoon number %d is : %.3f\n", i + 1, result[i]);////prints the average of the employees's salary in the platoon
    }
}
/////////////////////////////////////////////////////////////