
/* Assignment:4
    Campus : Beer Sheva
    Author : Rezeq Abu Mdeagm ID: 211606801

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef enum {FALSE,TRUE} BOOL ;
#define ZERO 0
#define MAX 10
#define VALUE ('a' - 'A')
void wordFrequency(char **words, int countwords);//the function gets a text that include  words and the number of thim and prints the frequency of the words
void ConvertToSmall(char **str, int countwords);//convert all of the letters to small letter
void textPreprocessing(char ***text, int *countWord, char **stopwords, int countStopwords);//the function get a text that include a words and the count of the words and the function get a text that include the stop words and the count of the stop words  the function remover the stop words of the text and the numbers and convert all of the letters to small letter and change the address of the text
BOOL RemoveNumbers(char *str);//the function gets a word and check if they are numbers in the word the function return true if the are else returns false
void FreeStr(char ***str, int countword);//the function  gets an address of the the text and ther number of the number of the words the function release of the memory that the text fill in the heap
void BuildStr(char ***word, int countword);//function that get the address of the text and the number of the words and assigning memory to the text according to the give size and the long of the words and scaning a words
void PrintfString(char **str, int size);//the function gets a text that include  words and the number of thim and prints the words
BOOL Check(char **string, int index);//the function gets a text of words and checking if the word in place indext appears from text[0] until text[index] the function returns false if the are simmial word else return true

int main()
{
    char **str = NULL, **stopwords = NULL;
    int countwords, countstopwords, *ar;
    printf("please enter the number of the words \n");
    scanf("%d", &countwords);//scaning the number of requested  words
    BuildStr(&str, countwords);//assigning memory to the text of words according to the give size and the long of the words and scaning a words
    printf("please enter the number of the stop words \n");
    scanf("%d", &countstopwords);//scaning the number of the requested stop words
    BuildStr(&stopwords, countstopwords);//assigning memory to the text of the stop words according to the give size and the long of the words and scaning a words
    textPreprocessing(&str, &countwords, stopwords, countstopwords);//remover the stop words from the str and the words that include numbers and convert all of the letters to small letter
    printf("The new words is : \n");
    PrintfString(str, countwords);//printing the words
    printf("\n\nThe frequency of the words is :\n\n");
    wordFrequency(str,countwords);//printing the frequency of the words that in the text str
    FreeStr(&str, countwords);//releace the memory that the pointer of pointer str fill in th heap
    str=NULL;//rest the value of the pointer of pointer str
    return 0;
}

//////////////////////////////////////////////////////////
void wordFrequency(char **words, int countwords)//the function gets a text that include  words and the number of thim and prints the frequency of the words
{
    int i, j, count = 0;
    for (i = 0; i < countwords; i++)
    {
        count = 0;
        for (j = 0; j < countwords; j++)
        {
            if (strcmp(words[i], words[j]) == 0)//count the frequency of the words
                count++;
        }
        if (Check(words,i) == 1)//checking if the word found more than one times
            printf("--%s : appers %d times\n", words[i], count);//prints the frequency of the words
    }
}
///////////////////////////////////////////////////////////
void textPreprocessing(char ***text, int *countWord, char **stopwords, int countStopwords)//the function get a text that include a words and the count of the words and the function get a text that include the stop words and the count of the stop words  the function remover the stop words of the text and the numbers and convert all of the letters to small letter and change the address of the text
{
    char **string;
    int c = 0, flag = 0, i, j, count = *countWord;
    ConvertToSmall(stopwords, countStopwords);//convert all of the letters of the stop words to small letters
    for (j = 0; j < *countWord; j++)
    {
        for (i = 0; (*text)[j][i] != '\0'; i++)//convert all of the letters of the words that in text to small letters
            if ((*text)[j][i] >= 'A' && (*text)[j][i] <= 'Z')
                (*text)[j][i] = (*text)[j][i] + VALUE;
    }

    for (i = 0; i < *countWord; i++)//count the words of the new text that will creat in the end of the function
    {
        flag = 0;//variable to know if the word dosent include a numbers and dosent found in the stop word
        for (j = 0; j < countStopwords; j++)
        {
            if (strcmp((*text)[i], stopwords[j]) == 0 || RemoveNumbers((*text)[i]) == 1)//checking if the word dosent include a numbers and dosent found in the stop word
                flag = 1;
        }
        if (flag == 1)
            count--;
    }

    string = (char **)calloc(count, sizeof(char *));//assigning memory to array of pointers that pointer to the words
    if (string == NULL)//checking if they are enough memory in the heap
    {
        printf("the are no enugh memory \n");
        exit(1);
    }

    for (i = 0; i < *countWord; i++)//puts the final words to the new text
    {
        flag = 0;//variable to know if the word dosent include a numbers and dosent found in the stop word
        for (j = 0; j < countStopwords; j++)
        {
            if (strcmp((*text)[i], stopwords[j]) == 0 || RemoveNumbers((*text)[i]) == 1)//checking if the word dosent include a numbers and dosent found in the stop word
                flag = 1;
        }
        if (flag == 0)
        {
            string[c] = (char *)malloc(strlen((*text)[i]) + 1);//assigning memory  to the string in place c with size that is the long of the word+1 becuase the \0
            if (string == NULL)
            {
                printf("the are no enugh memory \n");
                FreeStr(&string, *countWord);//release memory of the string that fill in the heap
                exit(1);
            }
            strcpy(string[c], (*text)[i]);//copy the words that in text[i] to string[c]
            c++;
        }
    }
    FreeStr(text, *countWord);//release memory of the text that fill in the heap
    *text = string;//gives the pointer of the pointer the address of the pointer of pointer string
    *countWord = count;//change the countword of the text  
}

///////////////////////////////////////////////////////////////

void ConvertToSmall(char **str, int countwords)//convert all of the letters to small letter
{
    int i, j;
    for (j = 0; j < countwords; j++)
    {
        for (i = 0; str[j][i] != '\0'; i++)
            if (str[j][i] >= 'A' && str[j][i] <= 'Z')
                str[j][i] = str[j][i] + VALUE;//add the diff of the code acqe of the capital letter and the small letter
    }
}
//////////////////////////////////////////////////////////////////
BOOL RemoveNumbers(char *str)//the function gets a word and check if they are numbers in the word the function return true if the are else returns false
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] >= '0' && str[i] <= '9')//checking if the word include numbers
            return TRUE;
    return FALSE;
}

//////////////////////////////////////////////////////////////////////
void BuildStr(char ***word, int countword)
{
    char flag[MAX];
    int i, longstring;
    *word = (char **)calloc(countword, sizeof(char *));//assigning memory to array of pointers that pointer to the words
    if (*word == NULL)
    {
        printf("the are no enugh memory \n");
        exit(1);
    }
    getchar();//to didint scan the enter as a letter
    for (i = 0; i < countword; i++)
    {
        printf("please enter the word number %d\n", i + 1);
        fgets(flag, MAX, stdin);//inter a word
        longstring = strlen(flag);//give the variable longstring the long of the word
        if (longstring > 0 && flag[longstring - 1] == '\n')//remover the \n from the word
            flag[longstring - 1] = '\0';//puts \0 in place \n
        (*word)[i] = (char *)malloc(strlen(flag) + 1);//assigning memory  to the string in place c with size that is the long of the word+1 becuase the \0
        if ((*word)[i] == NULL)
            FreeStr(word, countword);
        strcpy((*word)[i], flag);//puts the word in the text[i] 
    }
}
////////////////////////////////////////////////////////////////////

void FreeStr(char ***str, int countword)//the function  gets an address of the the text and ther number of the number of the words the function release of the memory that the text fill in the heap
{
    for (int i = 0; i < countword; i++)
    {
        free((*str)[i]);//release the memory of the string[i]
        (*str)[i] = NULL;//rest the value of the st
    }
    free(*str);//release the pointer of the pointer
    *str = NULL;//rest the value of the st
}
////////////////////////////////////////////////////////////////////////
void PrintfString(char **str, int size)//the function gets a text that include  words and the number of thim and prints the words
{
    for (int i = 0; i < size; i++)
        puts(str[i]);//printing the word
}
/////////////////////////////////////////////
BOOL Check(char **string, int index)//the function gets a text of words and checking if the word in place indext appears from text[0] until text[index] the function returns false if the are simmial word else return true
{
    int i;
    for (i = 0; i < index; i++)
    {
        if (strcmp(string[i], string[index]) == 0)//checking if the word is in the string 
            return FALSE;
    }

    return TRUE;
}