/*


Author:Rezeq Abo Madeghem
Campus:Beer-Sheva
Assigment 1.


*/

#define PRICE_98 7.8 //the price of 98 enleaded fuel
#define PRICE_95 6.25 // the price of 95 octan fuel
#define PRICE_DIESEL 5.97 // the price of diesel fuel
#define MAX_SIZE 150 //the price that if you get above it you will win a newspaper

#include <stdio.h>
//the function calculate how much to pay with a given typed fuel and the capacity of the the fuel in liters
int main()
{
    char fuel;
    int liters = 0;
    float cost;

    printf("Please enter the suitable letter according to this information \n");
    printf("Enter the letter 'S'or 's' if your fuel is 98 enleaded.\nEnter the letter 'R' or 'r' if your fuel is 95 octane.\nEnter the letter 'D' or 'd' if your fuel is diesel.\nEnter the letter 'X' if you dont want to fuel\n ");
   
    scanf(" %c", &fuel);
    getchar();
    if (fuel == 'S' || fuel == 's' || fuel == 'R' || fuel == 'r' || fuel == 'D' || fuel == 'd' || fuel == 'X') // check if the user enter a  letter in the require range
    {
        if (fuel != 'X')
        {
            printf("enter how much liters do you want to fuel\n"); //insert how much liters the user want to fuel
            scanf("%d", &liters);
            if (fuel == 'S' || fuel == 's') 
            {
                cost = (float)liters * PRICE_98; //calculate how much to pay 
                printf("your fuel cost is %f\n", cost);
            }
            else if (fuel == 'R' || fuel == 'r')
            {
                cost = (float)liters * PRICE_95;//calculate how much to pay 
                printf("your fuel cost is %f\n", cost);
            }
            else
            {
                cost = (float)liters * PRICE_DIESEL;//calculate how much to pay 
                printf("your fuel cost is %f\n", cost);
            }

            if(cost>MAX_SIZE)//checking if the user win a newspaper
                printf("You wom a free newspaper\n");
        }
        else
            printf("there is no cost\n");
    }
    else
        printf("you enterd a wrong letter please try again\n"); /
    return 0;
}