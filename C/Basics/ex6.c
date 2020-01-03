/*


Author:Rezeq Abo Madeghem
Id: 211606801
Campus:Beer-Sheva
Assigment 1 .


*/

#include <stdio.h>
int main() // the function is simple calculater that takes an opreation and two numbers and return  the result
{
	char operation;
	float answer;
	int number1, number2;

	printf("please enter a one operation from this operations : * - / %% +\n");
	scanf("%c", &operation); // insert an opration 
	getchar(); // to prevent taking the enter as a char
	
	if (operation == '*' || operation == '/' || operation == '-' || operation == '+' || operation == '%')// checking if the user enterd a wrong symbol 
	{
		printf("please enter a two numbers to do a calculation by the operation that you enterd  \n");
		scanf("%d%d", &number1, &number2); //insert a two numbers

		if (operation == '%') // calculate the result if the insert opration is %
		{
			if (number2 != 0) // checking if the number differnt from the number 0 because they will give eror
			{
				printf("I am the smart calculator: %d %% %d = %d\n", number1, number2, number1 % number2);
			}
			else
				printf(" a number can't be divided by zero\n");
		}
		else if (operation == '/') // calculate the result if the insert opration is /
		{
			if (number2 != 0) // checking if the number differnt from the number 0 because they will give eror
			{
				printf("I am the smart calculator: %d / %d = %f\n", number1, number2, (float)number1 / number2);
			}
			else
				printf(" a number can't be divided by zero\n");
		}
		else if (operation == '+') // calculate the result if the insert opration is +
		{
			printf("I am the smart calculator: %d + %d = %d\n", number1, number2, number1 + number2);
		}
		else if (operation == '-') // calculate the result if the insert opration is -
		{
			printf("I am the smart calculator: %d - %d = %d\n", number1, number2, number1 - number2);
		}
		else // calculate the result if the insert opration is *
		{
			printf("I am the smart calculator: %d * %d = %d\n", number1, number2, number1 * number2);
		}
	}

	else
		printf("your input is incorrect!!! \n ");

	return 0;
}
