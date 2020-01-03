/* Assignment : 3
    Campus Beer Sheva 
    Author : Rezeq Abo  madeghem , ID 211606801
*/

#include <stdio.h>
#define SIZE 5
int Ring(int [][SIZE], int);//function that takes a matrix and a number of the requested ring and printed the sum of the numbers that are in the ring
int NumOfRings( );//function that count the rings of the matrix by her size
void MatrixScaner(int [] [SIZE]);//function that takes an values to matrix 
int AllRings(int [][SIZE]);//function that takes a matrix and prints the sum of the numbers that are in the matrix

int main()
{
    int matrix[SIZE][SIZE],id,sum;
    printf("pleae enter a values to the matrix\n:");
    MatrixScaner(matrix);//takes an values to matrix
    printf("Please enter a number of a ring\n");
    scanf("%d",&id);//absorping a number of a ring
    if(id>=0&&id<NumOfRings( )){//checking if the number of the ring is proper
    sum=Ring(matrix, id);//give the value of the function to the variable sum  
    printf("the sum of the numbers of the choosen range is %d\n",sum);//printing the sum of the numbers in the given number of the ring in the matrix
    }
    else//if the number of the ring is not proper
    {
    printf("Number is illegal \n");
    printf("%d\n",sum);
    }
    sum=AllRings(matrix);
    printf("the sum of all the rings is %d\n",sum);//prints the sum of all the numbers that are in the matrix






    return 0;
}
int Ring(int matrix[][SIZE], int id)//function that takes a matrix and a number of the requested ring and printed the sum of the numbers that are in the ring
{
    int i, sum = 0;
    if(id>=0&&id<NumOfRings( ))//checking if the number of the ring is proper 
    {
        if(SIZE%2==1&&id==NumOfRings( )-1)//checking if the length of the square is odd and if the number thats inters is the number of the ring the most internal in the matrix
        return matrix[SIZE/2][SIZE/2];//return the value of the elemint the most internal int the matrix
         else {
    for (i = id; i < SIZE - id; i++)
        sum = sum + matrix[id][i] + matrix[i][id] + matrix[i][SIZE - 1 - id] + matrix[SIZE - 1 - id][i];//count the numbers in row id and in size-1-id and in column id and size-1-id
        sum = sum - matrix[id][id] - matrix[id][SIZE - 1 - id] - matrix[SIZE - 1 - id][id] - matrix[SIZE - 1 - id][SIZE - 1 - id];//delete the repeated elemints that we count before
    return sum;
        }
        
    }
    else
    return 0;
}
//-------------------
int NumOfRings( )//function that count the rings of the matrix by her size
{
    int count = 1,i;
    for (i = SIZE; i > 2; i -= 2)
        count++;//count the rings of the matrix by her size
    return count;// returns the count of the rings of the matrix by her size
}
//----------------------------
void MatrixScaner(int matrix[][SIZE])//function that takes an values to matrix
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            printf("please enter an value to matrix[%d][%d]\n", i, j);
            scanf("%d", &matrix[i][j]);// takes an value to elemint in row number i and column number j in the  matrix
        }
    }
}
//-----------------------------------------
int AllRings(int matrix[][SIZE])//function that takes a matrix and prints the sum of the numbers that are in the matrix
{
    int sum=0,i;
    for(i=0;i<NumOfRings();i++)//count the numbers that are in the matrix by the function Ring
    sum+=Ring(matrix,i);;



    return sum;//returns the count of the numbers that are in the matrix by the function Ring
}