#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char nameF[80];
	FILE *fileInput,*fileOutput;
	char username[30];
	int score;
	strcpy(nameF,"test.txt");
	//write data to file  "test.txt"
	fileOutput=fopen(nameF,"w");
	if(fileOutput==NULL)
	{
		printf(" unable to open file \n");
		exit(1);
	}
	strcpy(username,"user1"); 
	score=60;
	fprintf(fileOutput,"%s %d\n",username,score);
	strcpy(username,"user2"); 
	score=80;
	fprintf(fileOutput,"%s %d\n",username,score);
	fclose(fileOutput);
	//read data from the file  "test.txt" and write to the file "withfactor.txt" in the current directory- check this files!!
	printf("\n reading\n");
	fileInput=fopen(nameF,"r");
	fileOutput=fopen("withfactor.txt","w");
	if(fileInput==NULL ||fileOutput==NULL  )
	{
		printf(" unable to open file \n");
		exit(1);
	}
	while (!feof(fileInput)) {
		if (fscanf(fileInput, "%s %d", username, &score) != 2) break;
		fprintf(fileOutput, "%s %d\n", username, score+10);// write to file 
		//printf("%s %d\n", username, score+10); write to display 
	}
	fclose(fileInput);
	fclose(fileOutput);
	
 }
