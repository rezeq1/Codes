#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char nameF[80],text[80];
	FILE *fileInput,*fileOutput;
	char letter;
	int len;
	printf("enter name of file :");
	scanf("%s",nameF);
	
	//write to file 
	fileOutput=fopen(nameF,"w");
	if(fileOutput==NULL)
	{
		printf(" unable to open file %s\n",nameF);
		exit(1);
	}
	getchar();/*clear buffer*/
	do{
		printf("enter string or EXIT for stop :");
		fgets(text,80,stdin);
		len = strlen(text);
		if (len > 0 && text[len - 1] == '\n')
			text[len - 1] = '\0'; //remove '\n'
		if(strcmp(text,"EXIT")!=0)
			fprintf(fileOutput,"%s\n",text);
			
	}while(strcmp(text,"EXIT")!=0);
	fclose(fileOutput);

	
	//read from file
	printf("\nRead from file %s \n",nameF);
	fileInput=fopen(nameF,"r");
	if(fileInput==NULL)
	{
		printf(" unable to open file %s\n",nameF);
		exit(1);
	}
	fgets(text,80,fileInput);
	while(!feof(fileInput))
	{
		puts(text);
		fgets(text,80,fileInput);
	}
	
	fclose(fileInput);
	
}

