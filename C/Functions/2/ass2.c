/* Assignment : 2
    Campus Beer Sheva 
    Author : Rezeq Abo  madeghem , ID 211606801
*/
enum// a values of the number of the options 
{
    ONE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN
} Choise;
#define MAX 1000
#define TEN_THOUSAND 10000
#define HUNDRED_THOUSAND 100000

#include <stdio.h>

void CountIntersectDigits(); //this function count how much the digit of the first number appear in the second number ,the function stop when it receive the numbers 0 0
int CountSameDigit(int, int);//counting how much the digit appear in number 2

void PrintFriends();/*this function printing the friend number that the amount of the distributors equal to to the other number 
and the same about the other number that has amount of the distributors equal to to the first number
*/
int SumPartitions(int);//this function count calculate the amount of the partitions of the number

long ReverseDigits(long);//This function reverse the number and returned the value
int CountDigit(long);//this function count the number of the digit of the number
long Power(int);//this function calculate the result of the given power in base 10
void ReverseDigitsAndAdd5();//This function reverse the number and add  5 to it

int MaxDigit(long);//this function find the max digit
long RemoveMaxDigit(long);//this function remove the max digit of the number and returned the new number without the max digit 

int PrintSpecialNumbers();// this function prining the special numbers that have 5 digits and all of her digits are differnt from each other and count how much special numbers they are

int MakeNewNumber(int, int);/* this function makes a new number from the two given numbers by taking the max digit in place i from the two numbers
 and the surplus digits add to new number by the appropriate place*/

 
void PrintPattern(int);//this function  receives a positive number and  printed the  the number in pattern


long InsertValidNumber();/* This function absorbs number and checking if the number is positive 
if the number is negative the function absorbs a number again until absorbing a positive number
*/


/* In the function main we give to the user to chose one of the 7 options until the user enter the option number 8 that mean to exit from the function main 
*/

int main()
{
    int option;
    long num1, num2;
    //printing the options to the user 
    printf("Plese enter a number of your choise:\n");
    printf("1)Same digits.\n");
    printf("2)Friend numbers.\n");
    printf("3)Reverse the digits and add 5.\n");
    printf("4)Remove all max digit.\n");
    printf("5)Print the special numbers.\n");
    printf("6)Make a new number.\n");
    printf("7)Print numbers in pattern.\n");
    printf("8)Exit.\n");

    scanf("%d", &option);
    while (option != 8)// checking if the number of the option is differant from 8
    {
        switch (option)// do the actions  by the appropriate option
        {
        case ONE:
            CountIntersectDigits();// count how much the digit of the first number appear in the second number
            break;
        case TWO:
            PrintFriends();/* printing the friend number that the amount of the distributors equal to to the other number 
            and the same about the other number that has amount of the distributors equal to to the first number */
            break;
        case THREE:
            ReverseDigitsAndAdd5();// reverse the number and add  5 to it
            break;
        case FOUR:
            num1=InsertValidNumber();
            printf("the new number is :%ld\n", RemoveMaxDigit(num1));//remove the max digit of the number and return the new number without the max digit 
            break;
        case FIVE:
            printf("the counter is %d\n", PrintSpecialNumbers());//  prining the special numbers that have 5 digits and all of her digits are differnt from each other and printing the count of them 
            break;
        case SIX:
            printf("please enter a two numbers \n");
            scanf("%ld%ld", &num1, &num2);
            while ((num1 < 0) || (num2 < 0))
            {
                printf("please enter a two numbers again \n");
                scanf("%ld%ld", &num1, &num2);
            }
            printf("the new number is : %d \n", MakeNewNumber(num1, num2));/*  printing the new number from the two given numbers by taking the max digit in place i from the two numbers
            and the surplus digits add to new number by the appropriate place*/
            break;
        case SEVEN:
            num1=InsertValidNumber();
            PrintPattern(num1);//printed the number in pattern
            break;
        default:
            printf("You enterd a wrong letter please try again \n");
        }
        printf("Please enter the number of your option\n");
        scanf("%d", &option);
    }
    printf("Have a nice day!\n");

    return 0;
}


//------------------------------------------------------------------
/* This function absorbs number and checking if the number is positive 
if the number is negative the function absorbs a number again until absorbing a positive number
*/

long InsertValidNumber()
{
    long num;
    printf("Enter a number:\n");
    scanf("%ld", &num);

    while (num < 0)//checking if the number is negative
    {
        printf("Enter Valid number\n");
        scanf("%ld", &num);
    }

    return num;
}

//-------------------------------------------------------------------
// Question 1
//-------------------------------------------------------------------

void CountIntersectDigits()//this function count how much the digit of the first number appear in the second number and the function stop when they receive the numbers 0 0
{
    int digit, count = 0,flag = 0;//flag is an variable to know if the the number is zero
    long num1,num2;

    num1=InsertValidNumber();//absorbing a number until the number is positive
    num2=InsertValidNumber();;//absorbing a number until the number is positive

    while (num1 != 0 || num2 != 0)//checking if they are a number zero
    {
        if (num1 == 0)
            flag = 1;
        if (flag == 1)
            count += CountSameDigit(num2, 0);//counting how much the digit 0 appear in number 2
        else
        {
            while (num1 != 0)
            {
                digit = num1 % 10;//taking the last digit
                count += CountSameDigit(num2, digit);//counting how much the digit appear in number 2
                num1 /= 10;//remove  the last digit
            }
        }

        printf("The counter is %d\n", count);
        printf("Plese enter 2 numbers \n");
        num1=InsertValidNumber();;//absorbing a number until the number is positive
        num2=InsertValidNumber();;//absorbing a number until the number is positive

        count = 0;//reset the variable value
        flag = 0;//reset the variable value
    }
}

int CountSameDigit(int num, int digit)//counting how much the digit appear in number 2
{
    int count = 0;

    while (num != 0)
    {
        if (digit == num % 10)//checking if the two digit are same
            count++;//counting hoe much the two digit are same
        num /= 10;//remove the last digit
    }
    return count;
}
//-------------------------------------------------------------------
// Question 2
//-------------------------------------------------------------------

/*this function printing the friend number that the amount of the distributors equal to to the other number 
and the same about the other number that has amount of the distributors equal to to the first number
*/
void PrintFriends()
{
    int i, j;
    int num1, num2;
    for (i = 1; i <= MAX; i++)//checking the numbers between 1 and 1000
    {
        for (j = 1; j <= MAX; j++)
        {
            num1 = SumPartitions(i);//this count calculate the amount of the partitions of the number
            num2 = SumPartitions(j);//this count calculate the amount of the partitions of the number

            if ((num1 ==j) &&(num2==i))
                printf("The number %d and %d are Friends\n", i, j);
        }
    }
}

int SumPartitions(int num)//this function count calculate the amount of the partitions of the number
{
    int i, sum = 0;
    for (i = 1; i < num; i++)
    {
        if (num % i == 0)//checking if the number divisible by the value i without remnant
            sum += i;//counting the amount of the distributors of the number
    }
    return sum;
}

//-------------------------------------------------------------------
// Question 3
//-------------------------------------------------------------------

long ReverseDigits(long num)//This function reverse the number and returned the value
{
    long reverse = 0;//the value of the reverse number
    int digit_count, digit;
    digit_count = CountDigit(num);//count the number of the digit of the number
    while (num != 0)
    {
        digit = num % 10;//calculate the last digit
        num /= 10;//remove the last digit
        reverse += digit * Power(digit_count);//counting the revers number
        digit_count--;
    }
    return reverse;
}
int CountDigit(long num)//this function count the number of the digit of the number
{
    int count = 0, i;
    while (num != 0)
    {
        num /= 10;//remove the last digit
        count++;
    }
    return count - 1;
}
long Power(int n)//this function calculate the result of the given power in base 10 
{
    int i, power = 1;
    for (i = 0; i < n; i++)
    {
        power *= 10;//multiply the number in 10
    }
    return power;
}
void ReverseDigitsAndAdd5()//This function reverse the number and add  5 to it 
{
    long num;
    num=InsertValidNumber();
    printf("The revers of your number +5 is =%ld\n ", ReverseDigits(num) +FIVE);
}
//-------------------------------------------------------------------
//Question 4
//-------------------------------------------------------------------

int MaxDigit(long num)//this function find the max digit
{
    int max, digit;
    max = num % 10;
    while (num != 0)
    {
        digit = num % 10;//calculate the last digit
        num /= 10;//remove the last digit
        if (max < digit)
            max = digit;
    }
    return max;
}
long RemoveMaxDigit(long num)//this function remove the max digit of the number and returned the new number without the max digit 
{
    int digit, count = 0, max_digit;
    long new_number = 0;
    max_digit = MaxDigit(num);//find the max digit
    while (num != 0)
    {
        digit = num % 10;//calculate the last digit
        num /= 10;//remove the last digit
        if (digit != max_digit)//checking if the digit different from the max digit 
        {
            new_number += Power(count) * digit;//calculate the new number without the max digit
            count++;
        }
    }
    return new_number;
}

//------------------------------------------------------
//Question 5
//------------------------------------------------------

int PrintSpecialNumbers()// this function prining the special numbers that have 5 digits and all of her digits are differnt from each other and count how much special numbers they are
{
    int i, num, digit, flag = 0;//we use the variable flag to know if they are digit that appear than one time 
    int count = 0;
    for (i = TEN_THOUSAND ; i <HUNDRED_THOUSAND ; i++)
    {
        num = i;
        while (num != 0)
        {
            digit = num % 10;
            num /= 10;
            if (CountSameDigit(i, digit) != 1)//checking if the given digit appear in the given number above from 1
                flag = 1;// the value of flag is 1 if the number is not special
        }
        if (flag == 0)// checking if the value of flag is 0 then the number is special
        {
            printf("%d \n", i);//printing the special number
            count++;
        }
        flag = 0;//reset the variable value
    }
    return count;
}

//--------------------------------------------------------
//Question 6
//--------------------------------------------------------
/* this function makes a new number from the two given numbers by taking the max digit in place i from the two numbers
 and the surplus digits add to new number by the appropriate place
 */
int MakeNewNumber(int num1, int num2)
{
    int newnumber = 0, maxCountdigit, minCountdigit;
    int count = 0, size;
    maxCountdigit = CountDigit(num2);// finding the max and the min count of digit of the two numbers 
    minCountdigit = CountDigit(num1);

    if (CountDigit(num1) > CountDigit(num2))
    {
        maxCountdigit = CountDigit(num1)+1;
        minCountdigit = CountDigit(num2)+1;//the end of finding the max and the min count of digit of the two numbers
    }
    size = minCountdigit;
    while (size != 0)
    {
        if (num1 % 10 > num2 % 10)//checking if the the number 1 digit is bigger than the number 2 digit 
            newnumber += Power(count) * (num1 % 10);//adding the max digit in the appropriate place
        else
            newnumber += Power(count) * (num2 % 10);
        count++;
        num1 /= 10;//remove the last digit of number 1
        num2 /= 10;//remove the last digit of number 2
        size--;
    }

    if (CountDigit(num1) > CountDigit(num2))//add the surplus digits to the new number by the appropriate place
        newnumber += Power(minCountdigit) * num1;
    else
        newnumber += Power(minCountdigit) * num2;
    return newnumber;
}
//-----------------------------------------------------
//Question 7
//-----------------------------------------------------
//this function  receives a positive number and  printed the  the number in pattern
void PrintPattern(int num)
{
    int i, j, a, b;
    for (i = 0; i < num; i++)
    {
        for (j = 0; j <= i; j++)

            printf("%d", j + 1);//printing the first triangle that contains the numbers
        for (a = 0; a < 2 * (num - i - 1); a++)
            printf(" ");//printing the second triangle that contains the space 
        for (b = i; b >= 0; b--)
            printf("%d", b + 1);//printing the third triangle that contains the numbers in reverse order
        printf("\n");
    }
}