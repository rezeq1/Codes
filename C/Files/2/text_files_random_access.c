#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Random access to file data
int main()
{
	char nameF[80],buffer[80];
	FILE *fileInput,*fileOutput;
	char letter;
	strcpy(nameF,"check.txt"); // in the project directory
	//write to file
	strcpy(buffer,"123456789abcdefg");
	fileOutput=fopen(nameF,"w");
	if(fileOutput==NULL)
	{
		printf(" unable to open file \n");
		exit(1);
	}
	fprintf(fileOutput,"%s",buffer);
	fclose(fileOutput);
	//read from file 
	fileInput=fopen(nameF,"r");
	fseek(fileInput,2,SEEK_SET); //3 
	letter=fgetc(fileInput);
	printf("%c\n",letter); 

	fseek(fileInput,3,SEEK_CUR);
	letter=fgetc(fileInput);
	printf("%c\n",letter); // 7 

	fseek(fileInput,-2,SEEK_END); 
	letter=fgetc(fileInput);
	printf("%c\n",letter); // f

		
	fclose(fileInput);
}
	
