/*


Author:Rezeq Abo Madeghem
Id: 211606801
Campus:Beer-Sheva
Assigment 1.


*/
#define TEN 10 
#define HANDRED 100
#define THOUSAND 1000
#define TEN_HOUNSAND 10000

enum Option{One=1,Two,Three};// an enum that discrbed the options number

#include <stdio.h>
// the function do the slected option from the user ,the are a three option to Count the number of digits or to Check if number is even or odd or Square a negative number
int main()

{
    int number, squared, amount, option;

    printf("please enter an intger number between %d and %d \n",-TEN_HOUNSAND,TEN_HOUNSAND);
    scanf("%d", &number);

    if (-TEN_HOUNSAND < number && number < TEN_HOUNSAND)//checking if the enterd number between -10000 and 10000
    {
        printf("Plese select an option:\n");//
        printf("1) Count the number of digits. \n");
        printf("2) Check if number is even or odd.\n");
        printf("3) Square a negative number.\n");
        
        scanf("%d", &option);
        
        switch (option)
        {
        
        case One:// Count the number of digits
            if (-TEN < number && number < TEN)
                printf("number the  digits of your number is 1\n ");
            if ((-TEN >= number && number > -HANDRED) || (TEN <= number && number < HANDRED))
                printf("number the  digits of your number is 2 \n");
            if ((-HANDRED >= number && number > -THOUSAND) || (HANDRED <= number && number < THOUSAND))
                printf("number the  digits of your number is 3 \n");
            if ((-THOUSAND >= number && number > -TEN_HOUNSAND) || (THOUSAND <= number && number < TEN_HOUNSAND))
                printf("number the  digits of your number is 4 \n");
            break;
        case Two: //Check if number is even or odd
            if (number % 2 == 0)
                printf("the number you enterd is even\n");
            else
                printf("the number you enterd is odd\n");
            break;
        case Three: //Square a negative number
            if (0 > number && number > -TEN_HOUNSAND)
            {
                squared = number * number;
                printf("the squared of your number is %d\n", squared);
            }
            else
                printf("your number is not a negative number\n");
            break;
        default:// if the user enter a wrong number of the option
            printf("you enterd a wrong number please try again\n");
        }
    }
    else
        printf("you enterd a number outside the required range\n ");

    return 0;
}
