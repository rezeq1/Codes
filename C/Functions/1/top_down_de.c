/***Procedural decomposition :
Example : 
Square Roots by Newton's Method - this a method of successive approximations , which says that whenever we have a guess  "guess" for the value of the square root of a number "value",
we can perform a simple manipulation to get a better guess (one closer to the actual square root) by averaging "guess" with "value"/"guess".
Continue this process , we obtain better and better approximations to the square root.
*/
#include <stdio.h>
/*************** constants declaration */
#define EPS 0.00001
#define INIT_GUESS 1.0
/**********************/
/*************** new type BOOL */
typedef enum { FALSE,TRUE } BOOL;
/***********************/
/****************** declare functions */
float Sqrt(float);
float SqrtIter(float,float);
BOOL GoodEnough(float,float);
float ImproveGuess(float,float);
float Average(float,float);
float Square(float);
float Absolute(float);
/**************************************/
/**************************************************************** main program - testing */
int main(){
printf("%.5f\n",Sqrt(25));
printf("%.5f\n",Sqrt(2));
}
/*******************************************************************/
/* function's  implementation */
float Average(float arg1,float arg2){
	/* Function receives 2 float numbers and returns their average */
	return (arg1+arg2)/2;
}
float Square(float arg){
	/* Function receives a float number and returns it's power of two  */
	return arg*arg;
}
float Absolute(float value){ 
	/* Function receives a float number and returns its absolute value */
	if(value>=0)
		return value;
	else
		return -value;
}
float ImproveGuess(float guess,float value){
	/* Function receives 2 float numbers : current guess and a value, and returns the improved guess by Newton's formula : (guess+ value/guess)/2 */
	return Average(guess,value/guess);
}
BOOL GoodEnough(float guess,float value){
	/* Function receives 2 float numbers : current guess and a value, and checks if the current guess is within thw following limit : |guess* guess- value|<0.0000001 (the margin of error between the square of the guess and the value is infinitesimally small) */
	if(  Absolute ( Square(guess) - value ) < EPS  )
		return TRUE;
	else
		return FALSE;
}
float SqrtIter(float guess,float value){
	/* Function receives 2 float numbers : current guess and a value, and makes the iteration */
	while ( GoodEnough(guess,value)== FALSE)/* or   while ( !GoodEnough(guess,value))   */
		guess=ImproveGuess(guess,value);
	return guess;

}
float Sqrt(float value){
	/*Function receives a float number : a value that we want to find and returns it's square root as the result */
	return SqrtIter(INIT_GUESS,value);
}
