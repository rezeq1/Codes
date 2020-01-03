
/* Assignment:4
    Campus : Beer Sheva
    Author : Rezeq Abu Mdeagm ID: 211606801

*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
typedef enum
{
    FALSE,
    TRUE
} BOOL;
#define ZERO 0
int *intersection(int *group1, int size1, int *group2, int size2, int *psizeInter);//the function gets a 2 array and her sizes and takes a pointer to the size of the intersection of the 2 array to changer the value of it and the function returned the address of the intersecton group of the two array
void BuildGroup(int **Group, int *pCount);//function that get the address of a group and her size and assigning memory  to the group according to the give size and inters an values to the array without returned values 
int *Union(int *, int, int *, int, int *);//the function gets a 2 array and her sizes and takes a pointer to the size of the union of the 2 array to changer the value of it and the function returned the address of the union group of the two array
int *diff(int *group1, int size1, int *group2, int size2, int *pSizeDiff);//the function gets a 2 array and her sizes and takes a pointer to the size of the diff of the 2 array to changer the value of it and the function returned the address of the diff group of the two array
void PrintGroup(int *group, int size);//the function gets an array and her size and printing the the array in a brackets as a group of numbers 
void Scanner(int **arr, int size);//the function gets an address of array and her size and the function inters a values to array without a returned values /same values in the array
BOOL ValidValue(int **arr, int index, int value);//the function gets an address of array and an value and an index to check if the value is in the array until to arrive to the index in the array ,the function returns false if the number is in the array and returns true if the number is not in the array

int main()
{
    int size1, size2, sizeUnion = 0, *ptr1 = NULL, *ptr2 = NULL, *UnionArr = NULL;
    int *DiffArr = NULL, sizeDiff, psizeInter, *InterArr = NULL;
    BuildGroup(&ptr1, &size1);//assigning memory  to the group1 according to the give size and inters an values to the array without returned values
    BuildGroup(&ptr2, &size2);//assigning memory  to the group2 according to the give size and inters an values to the array without returned values
    printf("the first group is :\n");
    PrintGroup(ptr1, size1); //printing the group1 values in brackets
    printf("the second group is :\n");
    PrintGroup(ptr2, size2);//printing the group2 values in brackets

    printf("the diff of group1 from group 2 is :\n");
    DiffArr = diff(ptr1, size1, ptr2, size2, &sizeDiff);//gives the address of the diff group of the two groups to the pointer DiffArr
    PrintGroup(DiffArr, sizeDiff);//printing the diff group in a brackets

    printf("the union of the groups are :\n");
    UnionArr = Union(ptr1, size1, ptr2, size2, &sizeUnion);//gives the address of the union group of the two groups to the pointer UnionArr
    PrintGroup(UnionArr, sizeUnion);//printing the union group in a brackets

    printf("the intersection of the groups are :\n");
    InterArr = intersection(ptr1, size1, ptr2, size2, &psizeInter);//gives the address of the intersection group of the two groups to the pointer InterfArr
    PrintGroup(InterArr, psizeInter);//printing the intersection group in a brackets

//release of memory to all of the pointers:UnionArr,InterArr,DiffArr,ptr2,ptr1 . and give them a value 0
    free(UnionArr);
    UnionArr = NULL;
    free(InterArr);
    InterArr = NULL;
    free(DiffArr);
    DiffArr = NULL;
    free(ptr2);
    ptr2=NULL;
    free(ptr1);
    ptr1=NULL;

    return 0;
}
///////////////////////////////////////////////////////////////////

void BuildGroup(int **Group, int *pCountSize)//function that get the address of a group and her size and assigning memory  to the group according to the give size and inters an values to the array without returned values 
{
    int value;
    printf("Please enter the requested size of your array:\n");
    scanf("%d", pCountSize);//scaning a size  requested of the  group
    *Group = (int *)malloc(*(pCountSize) * sizeof(int));//assigning memory  to the group according to the inters size
    if (*Group == NULL)//checking if the are enough memory to the pointer in the heap
    {
        printf("They are not enugh memory : \n");
        exit(1);// to exit from the program if the are not enough memory to the pointer in the heap
    }
    Scanner(Group, *pCountSize);//inters an values to the array without returned values
}
///////////////////////////////////////////////////////////////////

int *Union(int *group1, int size1, int *group2, int size2, int *psizeUnion)//the function gets a 2 array and her sizes and takes a pointer to the size of the union of the 2 array to changer the value of it and the function returned the address of the union group of the two array
{
    int i, j, count = size1 + size2;
    int *ar, flag = 0, c = 0;
    for (i = 0; i < size2; i++)//count the size of the union group by checking how many numbers are same int the two groups
    {
        for (j = 0; j < size1; j++)
        {
            if (group2[i] == group1[j])
            {
                count--;
            }
        }
    }
    *psizeUnion = count;//gives the pointer  the size of the union of the 2 groups
    ar = (int *)malloc((*psizeUnion) * sizeof(int));//assigning memory  to the union group according to the inters size
    if (ar == NULL)//checking if the are enough memory to the pointer in the heap
    {
        printf("They are not enugh memory : \n");
        exit(1);
    }
    for (i = 0; i < size1; i++)//fill the values of the first group to the union group
        ar[i] = group1[i];

    for (i = 0; i < size2; i++)//fill the values of the union group
    {
        flag = 0;//an helping variable to know if the number is in the two groups 
        for (j = 0; j < size1; j++)
        {
            if (group2[i] == group1[j])
            {
                flag = 1;
            }
        }
        if (flag == 0)//if the number is not in the two groups to put it in the union group
            ar[(c++) + size1] = group2[i];
    }
    return ar;//return the address of the unoin group
}

///////////////////////////////////////////////////////////////////

int *intersection(int *group1, int size1, int *group2, int size2, int *psizeInter)//the function gets a 2 array and her sizes and takes a pointer to the size of the intersection of the 2 array to changer the value of it and the function returned the address of the intersecton group of the two array
{
    int i, j, c = 0, count = 0, *ar = NULL;
    for (i = 0; i < size1; i++)//count the size of the intersection group of the two groups
    {
        for (j = 0; j < size2; j++)
        {
            if (group1[i] == group2[j])
                count++;
        }
    }
    *psizeInter = count;//gives the pointer  the size of the intersection of the 2 groups
    ar = (int *)malloc((*psizeInter) * sizeof(int));//checking if the are enough memory to the pointer in the heap
    if (ar == NULL)//checking if the are enough memory to the pointer in the heap
    {
        printf("They are not enugh memory : \n");
        exit(1);
    }
    for (i = 0; i < size1; i++)//puts of the intersection numbers in the intersection group
    {
        for (j = 0; j < size2; j++)
        {
            if (group1[i] == group2[j])//checking if the numbers is in the two groups 
            {
                ar[c++] = group1[i];
            }
        }
    }
    return ar;//return the address of the intersection group 
}
///////////////////////////////////////////////////////////////////

int *diff(int *group1, int size1, int *group2, int size2, int *pSizeDiff)//the function gets a 2 array and her sizes and takes a pointer to the size of the diff of the 2 array to changer the value of it and the function returned the address of the diff group of the two array
{

    int i, j, c = 0, flag = 0, *ar = NULL;
    *pSizeDiff = size1;
    for (i = 0; i < size1; i++)//count the size of the diff group of the two groups
        for (j = 0; j < size2; j++)
            if (group1[i] == group2[j])
                (*pSizeDiff)--;

    ar = (int *)malloc((*pSizeDiff) * sizeof(int));//checking if the are enough memory to the pointer in the heap
    if (ar == NULL)//checking if the are enough memory to the pointer in the heap
    {
        printf("the are no enugh memory \n");
        exit(1);
    }
    for (i = 0; i < size1; i++)//puts of the intersection numbers in the diff group
    {
        flag = 0;
        for (j = 0; j < size2; j++)
            if (group1[i] == group2[j])
                flag = 1;
        if (flag == 0)
            ar[c++] = group1[i];
    }
    return ar;//return the address of the diff group
}

///////////////////////////////////////////////////////////////////

void PrintGroup(int *group, int size)//the function gets an array and her size and printing the the array in a brackets as a group of numbers 
{
    int i;
    if (size != 0)//checking if the size is zero
    {
        printf("{");//printing the opened brackets 
        for (i = 0; i < size - 1; i++)
            printf(" %d ,", group[i]);
        printf(" %d ", group[size - 1]);
        printf("}\n");//printing the cloesed brackets
    }
    else
        printf("{ }\n");// if the size is zero printing a brackets without numbers
}

///////////////////////////////////////////////////////////////////////////////////
void Scanner(int **arr, int size)//the function gets an address of array and her size and the function inters a values to array without a returned values /same values in the array
{
    int i = 0, value;
    printf("please enter a values to array \n");
    while (i != size)
    {
        printf("enter a value to array[%d]\n", i);
        scanf("%d", &value);//scaning a value 
        while (ValidValue(arr, i, value) != 1)//cheking if the value is in the group
        {
            printf("the value already in the array please enter an value again to array[%d] \n", i);
            scanf("%d", &value);//scaning a value 
        }
        (*arr)[i++] = value;//put the  value in the array in the place i and added to the variable i the value 1 
    }
}
///////////////////////////////////////////////////////////////////////////////////////
BOOL ValidValue(int **arr, int index, int value)//the function gets an address of array and an value and an index to check if the value is in the array until to arrive to the index in the array ,the function returns false if the number is in the array and returns true if the number is not in the array
{
    for (int i = 0; i < index; i++)//check if the value is in the array until to arrive to the index in the array
    {
        if ((*arr)[i] == value)
            return FALSE;//return false  if the value is in the array until to arrive to the index in the array
    }
    return TRUE;//return true  if the value is in the array until to arrive to the index in the array
}