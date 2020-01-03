
/* Assignment:4
    Campus : Beer Sheva
    Author : Rezeq Abu Mdeagm ID: 211606801

*/
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
typedef enum {FALSE,TRUE} BOOL ;
#define ZERO 0
void PrintMatrix(int **matrix, int row, int column);//the function gets a matrix and ther size(number of the columns and of the rows) and printing it 
void GetMinMax(int **matrix, int row, int column, int *pMin, int *pMax);//the function  gets a matrix and ther number of the columns and the number  of the rows and a pointer to the minimum value and pointer to the maximum value the function change the value of the pointer and give to evry pointer the appropriate
void AddRow(int ***matrix, int *pRow, int column, int *newRow, int columns);//the function  gets an address of the matrix and ther number of the columns and the number  of the rows and and an array of numbers and her size and the function add the array as a row to a new matrix and change the address of the matrix
void RemoveColumn(int ***matrix, int row, int *pColumn, int columnNumber);//the function  gets a matrix and ther number of the columns and the number  of the rows and a number of the requested column number to remove it from the matrix the function change the address of the matrix
void BuildMatrix(int ***matrix, int row, int column);//the function  gets an address of the matrix and ther number of the columns and the number  of the rows and  and assigning memory  to the matrix with size row*column and inters a values to the matrix
void FreeMaatrix(int ***matrix, int row);//the function  gets an address of the matrix and ther number of the columns and the number  of the rows and the function release of the memory that the matrix full in the heap
void MatrixCreat(int ***matrix, int row, int column);//the function  gets an address of the matrix and ther number of the columns and the number  of the rows and  and assigning memory  to the matrix with size row*column
void BuildGroup(int **Group, int *pCountSize);//function that get the address of a group and her size and assigning memory  to the group according to the give size and inters an values to the array 
void Scanner(int **arr, int size);//the function gets an address of array and her size and the function inters a values to array
void CheckNumber(int *numberColumn, int SizeColumn);//function that scan a number of the requested column to remove from the matrix and the function check if the number is legal if not the function scan again
int main()
{
    int column, Min, Max, row, **matrix = NULL, *array = NULL, size, NumberColumn;


    printf("please enter the number of the rows in the matrix \n");
    scanf("%d", &row);//inters the number of the rows
    printf("please enter the number of the columns in the matrix \n");
    scanf("%d", &column);//inters the number of the columns
    BuildMatrix(&matrix, row, column);//assigning memory  to the matrix with size row*column and inters a values to the matrix


    printf("Your matrix is : \n");
    PrintMatrix(matrix, row, column);//printing the matrix


    BuildGroup(&array, &size);//assigning memory  to the group according to the give size and inters an values to the array
    AddRow(&matrix, &row, column, array, size);//add the array as a row to a new matrix and change the address of the matrix
    printf("the matrix after add the row is  : \n");
    PrintMatrix(matrix, row, column);


    CheckNumber(&NumberColumn, column);//scaning a number of the requested column to remove from the matrix and the function check if the number is legal if not the function scan again
    RemoveColumn(&matrix, row, &column, NumberColumn);//remove the given number of column from the matrix and change the address of the matrix
    printf("the matrix after remover the column number %d is : \n",NumberColumn);
    PrintMatrix(matrix, row, column);


    GetMinMax(matrix, row, column, &Min, &Max);//give the pointer min the value of the minimum elemnt in the matrix  and give the pointer max the value of the maximum elemnt in the matrix
    printf("the max elemnt is %d and the min elemnt is %d \n", Max, Min);


    FreeMaatrix(&matrix,row);//release of the memory that the matrix full in the heap
    matrix=NULL;//gives the pointer of the pointer matrix the value zero

    return 0;
}

/////////////////////////////////////////////////////////////////////////

void PrintMatrix(int **matrix, int row, int column)//the function gets a matrix and ther size(number of the columns and of the rows) and printing it
{
    int i, j;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

/////////////////////////////////////////////////////////////////////////

void GetMinMax(int **matrix, int row, int column, int *pMin, int *pMax)//the function  gets a matrix and ther number of the columns and the number  of the rows and a pointer to the minimum value and pointer to the maximum value the function change the value of the pointer and give to evry pointer the appropriate
{
    int i, j;
    *pMin = matrix[ZERO][ZERO];//gives the pointer max the value 0
    *pMax = matrix[ZERO][ZERO];//gives the pointer max the value 0
    for (i = 0; i < row; i++)
    {
        for (j = ZERO; j < column; j++)
        {
            if (matrix[i][j] > *pMax)
                *pMax = matrix[i][j];//gives the pointer max the value of the maximum elemnt in the matrix
            if (matrix[i][j] < *pMin)
                *pMin = matrix[i][j];//gives the pointer min the value of the minimum elemnt in the matrix 
        }
    }
}

/////////////////////////////////////////////////////////////////////////

void AddRow(int ***matrix, int *pRow, int column, int *newRow, int columns)//the function  gets an address of the matrix and ther number of the columns and the number  of the rows and and an array of numbers and her size and the function add the array as a row to a new matrix and change the address of the matrix
{
    int i, j, **matrix2;
    if (columns == column)//checking if the size of the array is legal 
    {
        MatrixCreat(&matrix2, *pRow + 1, column);//assigning memory  to the matrix2 with size prow+1*column
        for (i = ZERO; i < *pRow; i++)//puts all of the matrix's elemnts to the matrix2
            for (j = ZERO; j < column; j++)
                matrix2[i][j] = (*matrix)[i][j];

        for (j = ZERO; j < columns; j++)//puts the array as a row in the under of the matrix2
            matrix2[*pRow][j] = newRow[j];
    }
    else
        printf("the sizeof the array is not appropriate to the size of the matrix \n");

FreeMaatrix(matrix,*pRow);//release the memory that pointer matrix fill in the heap
    *pRow = (*pRow) + 1;//change the value of the variable pRow ,add 1 to it
   *matrix = matrix2;//gives the pointer of the pointer matrix the address of matrix2
}

/////////////////////////////////////////////////////////////////////////

void RemoveColumn(int ***matrix, int row, int *pColumn, int columnNumber)//the function  gets a matrix and ther number of the columns and the number  of the rows and a number of the requested column number to remove it from the matrix the function change the address of the matrix
{
    int i, j, **matrix2;
        MatrixCreat(&matrix2, row, *pColumn-1);//assigning memory to the matrix2 with size prow*column-1
        for (i = 0; i < row; i++)//puts of the elemnts of matrix from column number zero until columnNumber in matrix2
        {
            for (j = 0; j < columnNumber; j++)
                matrix2[i][j] =(*matrix)[i][j];
        }

        for (i = 0; i < row; i++)//puts of the elemnts of matrix from columnNumber until pColumn in matrix2
        {
            for (j = columnNumber + 1; j < *pColumn; j++)
            {
                matrix2[i][j-1] = (*matrix)[i][j];
            }
        }
    *pColumn = (*pColumn) - 1;//change the value of the variable pColumn ,subtract 1 to it
    FreeMaatrix(matrix,row);//release the memory that pointer matrix fill in the heap
    *matrix = matrix2;//gives the pointer of the pointer matrix the address of matrix2
}
/////////////////////////////////////////////////////////////////////////

void BuildMatrix(int ***matrix, int row, int column)//the function  gets an address of the matrix and ther number of the columns and the number  of the rows and  and assigning memory  to the matrix with size row*column and inters a values to the matrix
{
    *matrix = (int **)malloc(row * sizeof(int *));//assigning memory to an array of pointers with size row
    if (*matrix == NULL)//checking if the are enough memory to the pointer in the heap
    {
        printf("the are no enugh memory \n");
        exit(1);// to exit from the program if the are not enough memory to the pointer in the heap
    }
    for (int i = 0; i < row; i++)
    {
        (*matrix)[i] = (int *)malloc(column * sizeof(int));//assigning memory  to the matrix in place i with size column
        if ((*matrix)[i] == NULL)//checking if the are enough memory to the pointer in the heap
        {
            printf("the are no enugh memory \n");
            FreeMaatrix(matrix, row);//releace the memory of the pointer matrix
            exit(1);// to exit from the program if the are not enough memory to the pointer in the heap
        }
    }
    for (int i = 0; i < row; i++)//receiving values to matrix
    {
        for (int j = 0; j < column; j++)
        {
            printf("please enter a value to matrix[%d][%d]\n", i, j);
            scanf("%d", &(*matrix)[i][j]);
        }
    }
}

//////////////////////////////////////////////////////////////////////////

void FreeMaatrix(int ***matrix, int row)//the function  gets an address of the matrix and ther number of the columns and the number  of the rows and the function release of the memory that the matrix full in the heap
{
    for (int i = 0; i < row; i++)
    {
        free((*matrix)[i]);//release of the memory that the matrix in place i fill in the heap
        (*matrix)[i] = NULL;//gives the pointer matrix in place i the value 0
    }
    free(*matrix);//release of the memory that the matrix fill in the heap
    *matrix = NULL;//gives the pointer matrix  the value 0
}
////////////////////////////////////////////////////////////////////////////

void MatrixCreat(int ***matrix, int row, int column)//the function  gets an address of the matrix and ther number of the columns and the number  of the rows and  and assigning memory  to the matrix with size row*column
{
    *matrix = (int **)malloc(row * sizeof(int *));//assigning memory to an array of pointers with size row
    if (*matrix == NULL)
    {
        printf("the are no enugh memory \n");
        exit(1);
    }
    for (int i = 0; i < row; i++)
    {
        (*matrix)[i] = (int *)malloc(column * sizeof(int));//assigning memory  to the matrix in place i with size column
        if ((*matrix)[i] == NULL)
        {
            printf("the are no enugh memory \n");
            FreeMaatrix(matrix, row);
            exit(1);
        }
    }
}
///////////////////////////////////////////////////////////////
void Scanner(int **arr, int size)//the function gets an address of array and her size and the function inters a values to array 
{
    int i = 0, value;
    printf("please enter a values to array \n");
    while (i != size)
    {
        printf("enter a value to array[%d]\n", i);
        scanf("%d", &value);
        (*arr)[i++] = value;
    }
}
////////////////////////////////////////////////////////////////////
void BuildGroup(int **Group, int *pCountSize)//function that get the address of a group and her size and assigning memory  to the group according to the give size and inters an values to the array
{
    int value;
    printf("Please enter the requested size of your array:\n");
    scanf("%d", pCountSize);//scaning the requested size of the array
    *Group = (int *)malloc(*(pCountSize) * sizeof(int));//assigning memory  to the group according to the inters size
    if (*Group == NULL)
    {
        printf("They are not enugh memory : \n");
        exit(1);
    }
    Scanner(Group, *pCountSize);
}
/////////////////////////////////////
void CheckNumber(int *numberColumn, int SizeColumn)//function that scan a number of the requested column to remove from the matrix and the function check if the number is legal if not the function scan again
{
    printf("Please enter the number of the requested column to remove it \n");
    scanf("%d", numberColumn);//scaning a number of the requested column to remove it
    while (*numberColumn >= SizeColumn || *numberColumn < 0)//checking if the number of the requested column to remove it is legal if no to scan again
    {
        printf("the number of the column is not found please enter again \n");
        scanf("%d", numberColumn);
    }
}