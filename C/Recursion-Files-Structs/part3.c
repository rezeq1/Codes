/* Assignment : 5
    Campus Beer Sheva 
    Author : Rezeq Abo  madeghem , ID 211606801
*/



#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#define SIZE 10 //the maximum size of the player's name

typedef struct//definition of struct that include the necessary hours and the minutes and seconds to complete the marathon  ,in name task time
{
    int hours, minutes, seconds;
} TaskTime;

typedef struct//definition of struct that include a  name and his id and the struct task time ,in name marathon
{
    char name[SIZE];
    char id[SIZE];
    TaskTime time;
} Marathon;

int CalculatePlayer(char *);//calculate how much players they are in the input file and returns it
void Build(Marathon **players, int size, char *);//build an array of the struct marathon and allocation memory to the pointer players  and fill the array by the information that is in the input file
void PrintStruct(Marathon **players, int size);//printing the information of the players in the array of the struct marathon
void FindTheFaster(Marathon *players, int size, char *filename);//prints the information of the fasters player in the output file
int help(Marathon *players, int size, int index);//function that takes an array of struct players and the number of the players and a number of the players to check if the player is the faster 

int main()
{

    Marathon *players = NULL;
    char InputFile[2 * SIZE], OutputFile[2 * SIZE];
    int size;
    printf("Please enter the name of the input file \n ");
    scanf("%s", InputFile);//scaning the name of the input file 
    getchar();//remove the char enter
    printf("Please enter the name of the output file \n ");
    scanf("%s", OutputFile);//scaning the name of the output file 
    getchar();//remove the char enter

    size = CalculatePlayer(InputFile);//save the number of the players
    Build(&players, size, InputFile);//build an array of the struct marathon and fill the information to it
    FindTheFaster(players, size, OutputFile);//find the faster player and print it in the output file 
    free(players);//release the memory of the pointer array
    players=NULL;//rest the pointer players

    printf("****** The mission done successfully ****** \n");
    return 0;
}


//////////////////////////////////////
int CalculatePlayer(char *filename)//calculate how much players they are in the input file 
{
    int count = 0;
    char letter;
    FILE *Input = fopen(filename, "r");//open the input file to read

    if (Input == NULL)//checking if the opening file done successfully
    {
        printf("Error the input file dose not found \n");
        exit(1);
    }
    while (!feof(Input))//checking if we dosent arraive to the end of the input file
    {
        letter = fgetc(Input);//scaning a char
        if (letter == '\n')//counts how many enters they are in the input file 
            count++;
    }
    fseek(Input,-1L,SEEK_END);//moving the pointer to the last char in the file 
    letter = fgetc(Input);//scaning the last char
    if(letter!='\n')//checking if the char is enter
    count++;

    fclose(Input);//close the  input file

    return count ;//returns thow much players they are in the input file
}
/////////////////////////////////////////
void FillStruct(char *filename, Marathon **players, int size)//fill the array of the struct marathon by the information that is in the input file
{
    int i = 0;
    FILE *Input = fopen(filename, "r");//open the input file to read
    if (Input == NULL)//checking if the opening file done successfully
    {
        printf("Error the input file dose not found \n");
        exit(1);
    }
    while (!feof(Input))//checking if we dosent arraive to the end of the input file
    {
        if (fscanf(Input, "%s %s %d %d %d", (*players)[i].name, (*players)[i].id, &((*players)[i].time).hours, &((*players)[i].time).minutes, &((*players)[i].time).seconds) != 5)//scaning the information of the struct marathon and check id the line is lligal
            break;

        i++;
    }

    fclose(Input);//close the  input file 
}
//////////////////////////////////////
void Build(Marathon **players, int size, char *filename)//build an array of the struct marathon and allocation memory to the pointer players  and fill the array by the information that is in the input file 
{
    *players = (Marathon *)malloc(size * sizeof(Marathon));//allocation memory to the pointer players 
    if (*players == NULL)//checking if they are enough memory
    {
        printf("They are no enuogh memory \n ");
        exit(1);//exit from the function
    }
    FillStruct(filename, players, size);//fill the array by the information that is in the input file
}

//////////////////////////////////////////////////

void FindTheFaster(Marathon *players, int size, char *filename)//prints the information of the fasters player in the output file
{
    int i;
    FILE *output = NULL;
    output = fopen(filename, "r+");//open the output file to write the faster players 
    if (output == NULL)//checking if the file open successfully
    {
        printf("Error the input file dose not found \n");
        exit(1);//exit from the function 
    }
    for (i = 0; i < size; i++)
    {
        if (help(players, size, i) == 1)
            fprintf(output, "%s %s %d %d %d\n", players[i].name, players[i].id, players[i].time.hours, players[i].time.minutes, players[i].time.seconds);//prints the information of the fastes player in the output file
    }

    fclose(output);//close the output file 
}

//////////////////////////////////////////////////////////////
int help(Marathon *players, int size, int index)//function that takes an array of struct players and the number of the players and a number of the players to check if the player is the faster
{
    int i;
    for (i = 0; i < size; i++)
    {
        if ((players[i].time).hours > (players[index].time).hours)//checking if the necessary hours to complete the marathon of the player is the minimum
            ;
        else
        {
            if ((players[i].time).hours < (players[index].time).hours)
                return 0;
            else
            {
                if ((players[i].time).minutes > (players[index].time).minutes)//checking if the necessary minutes to complete the marathon of the player is the minimum
                    ;
                else
                {
                    if ((players[i].time).minutes < (players[index].time).minutes)
                        return 0;
                    else
                    {
                        if ((players[i].time).seconds > (players[index].time).seconds)//checking if the necessary secondes to complete the marathon of the player is the minimum
                            ;
                        else
                        {
                            if ((players[i].time).seconds < (players[index].time).seconds)
                                return 0;
                            else
                                ;
                        }
                    }
                }
            }
        }
    }
    return 1;//return 1 if the player is the faster
}
