/*


Author:Rezeq Abo Madeghem
ID: 211606801
Campus:Beer-Sheva
Assigment 1.


*/
#define hour 60                 // number of minutes in hour
#include<stdio.h>

//this function calculates the required timeto take arrive from (place to other*using the destance) with user vilocity.
int main()

{
	int distance,speed;
	float time;

	printf("please enter a distance between source and destination in units km\n");   //insert the requird destance
	scanf("%d",&distance);
	
	printf("please enter the speed in units km/hour \n");                              // insert user vilocty
	scanf("%d",&speed);
	
	time=(float)(distance*hour)/speed;                                         // calculate the time and prints the result into the screen
	printf("the time to arrive is %.2f in minutes\n",time);
	
	return 0;

}
