/*


Author:Rezeq Abo Madeghem
Id: 211606801
Campus:Beer-Sheva
Assigment 1 .


*/

#define ZERO 0
#define TEN 10
#define HANDRED 100
#define THOUSAND 1000
#define TEN_THOUNSAND 10000
#define HANDRED_THOSAND 100000

#include <stdio.h>
int main() // the function checking if the number is blendrom
{
  int number, a, b, c, d, e, num1;//evry leter discribe the digit of the number

  printf("please enter an intger number between 9999 and 100000 without the digit 0\n");
  scanf("%d", &number);//inset a number
  
  if (number >=TEN_THOUNSAND && number < HANDRED_THOSAND)// checking if the number has 4 digits
  {     //caluclate the digits of the number
    a = number % TEN;
    b = (number % HANDRED - a) / TEN;
    c = (number % THOUSAND) / HANDRED;
    d = (number % TEN_THOUNSAND) / THOUSAND;
    e = number / TEN_THOUNSAND;
  
    if (a != ZERO && b != ZERO && c != ZERO && d != ZERO && e != ZERO)// checing if all of the digits differnt from the number 0  
      {
      num1 = a * TEN_THOUNSAND + b * THOUSAND + c *HANDRED + d * TEN + e; // creat the inverse number
      if (num1 == number)// checking if the number is blendrom 
        printf("yes the number is blendrom\n");
      else
        printf("the number you enterd is not blendrom\n");
    }

    else
      printf("you enterd the digit 0 pleaes enter another number\n");
  }
  else
    printf("the number you enterd is outside of the required range\n");

  return 0;
}