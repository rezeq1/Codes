/* Assignment : 3
    Campus Beer Sheva 
    Author : Rezeq Abo  madeghem , ID 211606801
*/
#include<stdio.h>
int PrintDivided(int[],int,int);//function that prints the numbers that divided by the value without rest and returns the count of them
void ArrayScaner(int[],int);//function that takes values to array by his size
void PrintMaxPalindrom(int[],int);//function that prints the longest palindrom in the array
int IndexChecker(int array[],int index1,int index2);//function that check if the numbers between the index1 and index2 is plandrom if yes the function returns 1 else returns 0 
void PrintIndex(int array[],int index1,int index2);//function that prints the numbers from index1 to index2 in the array
#define size_1 14 //the size of the first array
#define size_2 10 //the size of the second array






int main() {
int value,array1[size_1],array2[size_2],return1;





printf("Please enter an value \n");
scanf("%d",&value);
while(value<0)//if the value is negative we asking to insert a second number 
{
printf("Please enter an value again  \n");
scanf("%d",&value);
}
printf("Please enter a values to the array number 1  \n");
ArrayScaner(array1,size_1);//takes values to array1 by his size by the function ArrayScaner
return1=PrintDivided(array1,size_1,value);
if(return1!=0)//check if the value that function return is different from zero

printf("The number of the numbers that divided by the value in array 1 is % d \n",return1);

else
printf("% d \n",return1);
printf("Please enter a values to the array number 2  \n");

ArrayScaner(array2,size_2);//takes values to array2 by his size by the function ArrayScaner
PrintMaxPalindrom(array2,size_2);//prints the longest palindrom in array2



    return 0 ;
}
//--------------------------------
int PrintDivided(int array[],int size,int value)//function that prints the numbers that divided by the value without rest and returns the count of them
{
int count=0,i;
if(value)//check if the value is different from zero
{
printf("the numbers that divided by the value that you enterd is:\n");
for(i=0;i<size;i++)
if(array[i]%value==0)//checking if the element in the place i divided by the value without rest
{
printf("%d \n",array[i]);//prints the elemnts that divided by the value without rest
 count++;//count the elemnts that divided by the value without rest
}
}
else
return -1;

    return count ;
}
//----------------------------------
void PrintMaxPalindrom(int array[],int size){//function that prints the longest palindrom in the array
    int index1,index2,i,j,max=IndexChecker(array,0,1);;//give to the variable max the returns value of the function IndexChecker when the index1 is 0 and index 2 is 1
    for(i=0;i<size-2;i++)
{ 
        for(j=i+1;j<size;j++)
    {
   if(IndexChecker(array,i,j)>max)//check if they are a longer plandrom than the max
    {
   max=IndexChecker(array,i,j);;//if the plandromis longer than the max , max take the plandrom long
   index1=i;//save the the first index of the longest plandrom
   index2=j;//save the the second index of the longest plandrom
    }
    }
}
if(max!=0)//check if they are a plandrom or not
PrintIndex(array,index1,index2);//prints the longer plandrom in the array
else
printf("no plindrom exist \n"); 
}



//-----------------------------------
 void ArrayScaner(int array[],int size)//function that takes values to array by his size
 {
 int i;
 for(i=0;i<size;i++)
 {
 printf("Please enter a number to array[%d]\n",i);
 scanf("%d",&array[i]);//takes a value to the elemint in the place i in the array
 }

 }
 //------------------------------------
 int IndexChecker(int array[],int index1,int index2)//function that check if the numbers between the index1 and index2 is plandrom if yes the function returns 1 else returns 0
 {
 int i,count=0;
 for(i=0;i<(index2-index1)/2+1;i++)
    if(array[index1+i]==array[index2-i])//check if the numbers between the index1 and index 2 is plandrom
    count++;
if(count==(index2-index1)/2+1)
return index2-index1+1;// returns the long of the plandrom 
else 
return 0;
 }
 //----------------------------------------------------
 void PrintIndex(int array[],int index1,int index2){//function that prints the numbers from index1 to index2 in the array
 int i;
 printf("The max palindrom is \n");
 for(i=index1;i<=index2;i++)
 printf("%d",array[i]);//prints the elemint in the place i in the array
 printf("\n");
 }