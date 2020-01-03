/* Assignment : 5
    Campus Beer Sheva 
    Author : Rezeq Abo  madeghem , ID 211606801
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE 80
int Strlen(char *str);//the function count the long of the word
int ConverTotBinary(int num);//the function takes a number on base 10 and returns the number in base binary
int MinimumDigit(int);//the function takes a number and returns the minimum digit in the number
int CheckAllOdd(int[], int);//the function takes an array of a numbers and his size and check if all the numbers is odd
int SumOfEvens(int arr[], int size);//the function takes a number and his size and returns the sum of the even numbers
int strcmp(char *word1, char *word2);//the function takes a 2 words and return the diff of the code asqe
void ConvertToSumElemints(int *arr, int size);//the function take an array of numbers and his size and changes the values to the sum of the numbers
int TheLongestWord(char **string, int size, int *);//the function takes a words and find the maximum long word and the count of them
void BuildArray(int**array,int*size);//the function takes an address of an array and an address of the variable size and allocation memory to the array and fill the array values

int main()
{
    char word1[SIZE], word2[SIZE], word3[SIZE],*string[] = {"test", "corRrect", "data", "onRRRRRe", "reRplace"};
    int x ,*array=NULL, ptr = 1,size;
printf("Please enter  a number to find the minimum digit \n");
scanf("%d",&x);
if(x>=0)//check if the number is  positive or zero
printf("the minimum digit is %d\n",MinimumDigit(x));
else
printf("the minimum digit is %d\n",MinimumDigit(-x));

printf("Please enter  a number in base 10 to convert it to base 2 \n");
scanf("%d",&x);
printf("the number in base 2 is %d\n",ConverTotBinary(x));

printf("please enter an information to array to check if all of the values is odd \n");
BuildArray(&array,&size);//allocation memory to the array and fill the array values
if(CheckAllOdd(array,size)==0)//checking if ot all of the values are odd
printf("not all of the values are odd\n");
else
printf("all of the values are odd\n");
free(array);//release the memory of the pointer array
array=NULL;//rest the pointer array

printf("please enter an information to array to count the sum of the even values \n");
BuildArray(&array,&size);//allocation memory to the array and fill the array values
printf("the sum of the even values is %d\n",SumOfEvens(array,size));
free(array);//release the memory of the pointer array
array=NULL;//rest the pointer array

printf("please enter an information to array to build the new array \n");
BuildArray(&array,&size);//allocation memory to the array and fill the array values
ConvertToSumElemints(array,size);
printf("the new array is \n");
for(int i=0;i<size;i++)
printf("%d ",array[i]);
printf("\n");
free(array);//release the memory of the pointer array
array=NULL;//rest the pointer array

printf("please enter a word to count the long of the word \n");
scanf("%s",word1);
getchar();//remove the the char enter
printf("the long of the word is %d\n",Strlen(word1));

printf("please enter a 2 words to count the diff of the 2 words \n");
scanf("%s",word2);
getchar();//remove the the char enter
scanf("%s",word3);
getchar();//remove the the char enter
printf("the diff of the 2 words is %d\n",strcmp(word2,word3));

printf("the long of the longest word is %d\n", TheLongestWord(string, 5, &ptr));
printf("they are %d words that have this long\n", ptr);




    return 0;
}



int ConverTotBinary(int num)//the function takes a number on base 10 and returns the number in base binary
{
    if (num == 0)//stop conditions
        return 0;
        else{
    return (num%2)+10*ConverTotBinary(num / 2);
        }
}



int Strlen(char *str)//the function count the long of the word
{
    if (*str == '\0')//stop conditions
        return 0;
    else
        return 1 + Strlen(str + 1);
}




int MinimumDigit(int num)//the function takes a number and returns the minimum digit in the number
{
    int rest;
    if (num / 10 == 0)//stop conditions
        return num;
    else
    {
        rest = MinimumDigit(num / 10);
        if (rest > num % 10)
            return num % 10;
        else
            return rest;
    }
}




int CheckAllOdd(int arr[], int size)//the function takes an array of a numbers and his size and check if all the numbers is odd
{
    if (size == 1)//stop conditions
    {
        if (arr[0] % 2 == 0)
            return 0;
        else
            return 1;
    }
    else if (arr[size - 1] % 2 != 0)
        return CheckAllOdd(arr, size - 1);
    else
        return 0;
}



int SumOfEvens(int arr[], int size)//the function takes a number and his size and returns the sum of the even numbers
{
    if (size == 1)//stop conditions
    {
        if (arr[size - 1] % 2 == 0)
            return arr[size - 1];
        else
            return 0;
    }
    else
    {
        if (arr[size - 1] % 2 == 0)
            return arr[size - 1] + SumOfEvens(arr, size - 1);
        else
            return SumOfEvens(arr, size - 1);
    }
}





int strcmp(char *word1, char *word2)//the function takes a 2 words and return the diff of the code asqe
{
    if (word1[0] == '\0' && word2[0] == '\0')//stop conditions
        return 0;
    else
    {
        if (word1[0] == word2[0])
        {
            return strcmp(word1 + 1, word2 + 1);
        }
        else
            return (word1[0] - word2[0]) + strcmp(word1 + 1, word2 + 1);
    }
}





void ConvertToSumElemints(int *arr, int size)//the function take an array of numbers and his size and changes the values to the sum of the numbers
{
    if (size == 1)//stop conditions
        return;
    else
    {
        arr[1] += arr[0];
        ConvertToSumElemints(arr + 1, size - 1);
    }
}





int TheLongestWord(char **string, int size, int *ptr)//the function takes a words and find the maximum long word and the count of them
{
    int rest, count;
    if (size == 1)//stop conditions
        return Strlen(string[0]);
    else
    {
        rest = TheLongestWord(string + 1, size - 1, ptr);
        if (Strlen(string[0]) > rest)
            return Strlen(string[0]);
        else
        {
            if (Strlen(string[0]) == rest){
                 (*ptr)++;//count how much words that have the maximum long of word
                return rest;
            }

            else
                return rest;
        }
    }
}






void BuildArray(int**array,int*size)//the function takes an address of an array and an address of the variable size and allocation memory to the array and fill the array values
{
printf("Please enter the size of the array \n");    
scanf("%d",size);//insert a size of the array
*array=(int*)malloc((*size)*sizeof(int));//allocation memory to the array
if((*array)==NULL)//checking if the are no enough memory
{
printf("the are no memory \n");
exit(1);    
}
for(int i=0;i<(*size);i++)//fill the array values
{
printf("please enter a value to array[%d]\n",i);
scanf("%d",&(*array)[i]);

}


}