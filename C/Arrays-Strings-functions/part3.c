/* Assignment : 3
    Campus Beer Sheva 
    Author : Rezeq Abo  madeghem , ID 211606801
*/
typedef enum {FALSE,TRUE} BOOL ;
#include <stdio.h>
#define SIZE 20           //the size of the first string
#define SIZE_2 100        //the size of the second string
#define FIFTEEN 15        //the size of a one word in string 2
#define VALUE ('a' - 'A') // the diff between the ASCI code for the capital letter ans the small letter

int CheckBrackets(char[]);                             //checking if the all the elemints in the string are brackets
BOOL StringChecker(char[]);                             //checking if the string brackets is vaild or not the function returns true if yes else returns false
int CheckTheNumOFbBrackets(char[]);                    //checking if the number of the open brackest are equal to the number of the closed brackets
int ClosedBracketsCheck(char[]);                       //checking if the the first brackest is closed and if the last brackets is open because in this situation the string is invaild
int StrLen(char str[]);                                //function that calculate the length of the string
void Input(char str[]);                                //function that takes a chars to the string
int CountWords(char str[]);                            // the function count how many words they are in the string
void CleanStr(char str[]);                             //function that clean the string after we used it to stay away from the problems that will be if we donts clean the string
void SetWord(char str[], char newstr[], int wordsnum); //set the word by the requested number in a new string
int GetStartingIndex(char str[], int wordnum);         //the function returns the first index of the the requested number of word
int Are_Simillars(char str1[], char str2[]);           //the function takes a 2 words and check if the the 2 words are simillar,if the all of the letters of the first word are in the second word
void SimillarWords(char line[]);                       //function that takes a string and prints the simillar word ,words that all of her letters in the second word with no difference between the capital letters and the small letter and how much the letter appears
void ConvertToSmall(char str[], char newstr[]);        //the function takes a string and convert  all of the letters that in the string to small letters in a new string

int main()
{
    char line[SIZE_2], line2[SIZE];
    printf("Enter a line from a brackets to check it \n");
    Input(line2);             // absorping a string of brackets
    if (StringChecker(line2)) //checking if the string is vaild string brackets
        printf("Valid string brackets\n");
    else
        printf("Invalid string brackets\n");
    printf("Enter a line from a words to check if they are a simallar words \n");
    Input(line);         // absorping a string of words
    SimillarWords(line); //prints the simillar words the are in the string
    return 0;
}
//---------------------------------------
void Input(char str[]) //function that takes a chars to the string
{
    int len;
    printf("please enter a words\n");

    fgets(str, SIZE_2, stdin); //absorping a string of brackets by the function fgets

    len = StrLen(str); //give the variable len the lenght of the string

    str[len - 1] = '\0'; // remover the \n because the function fgets take the \n like a char
}
//------------------------------------
int StrLen(char str[]) //function that calculate the length of the string
{
    int i;
    for (i = 0; str[i] != '\0'; i++) // scan the string until we arrive to the end of the string by the char \0
        ;

    return i; //return the length of the string
}
//-------------------------------
int CountWords(char str[]) // the function count how many words they are in the string
{
    int i = 0;
    int count = 0;
    for (i; str[i] != '\0'; i++) //scan the string until we arrive to the end of the string
        if (str[i] == ' ')       //count the spacings
            count++;
    return count + 1; //returns the num of the spacings  and 1 more
}
//----------------------------------------------
void SetWord(char str[], char newstr[], int wordnum) //set the word by the requested number in a new string
{
    int len, i, j = 0;
    CleanStr(newstr);// clean the string after we used it to stay away from the problems that will be if we donts clean the string

    for (i = GetStartingIndex(str, wordnum); str[i] != ' ' && str[i] != '\0'; i++)//scaning the string from the first index of the word at the end index
        newstr[j++] = str[i];//set the requested word in the a new string 
    newstr[j] = '\0';//put the char \0 , to put the end of the string
}
//-----------------------------------------------
void CleanStr(char str[])// the function clean the string after we used it to stay away from the problems that will be if we donts clean the string
{
    int len, i;
    len = StrLen(str);//give to the variable len the length of the stirng
    for (i = 0; i < len; i++)
        str[i] = '\0';//set in every place in the string the chat \0,remover the letters
}
//----------------------------------------------------
int GetStartingIndex(char str[], int wordnum)//the function returns the first index of the the requested number of word
{
    int count = 0;
    int i;

    if (wordnum == 1)//checking if the requested word is the first word
        return 0;
    for (i = 0; str[i] != '\0'; i++)//scaning the string until to arrive to end of the string
    {
        if (str[i] == ' ')//count the words
            count++;
        if (count == wordnum - 1)//checking if the requsted number of word equal to the count of the words
            return i + 1;
    }
}
//----------------------------------------------------

int Are_Simillars(char str1[], char str2[])//the function takes a 2 words and check if the the 2 words are simillar,if the all of the letters of the first word are in the second word
{
    int len1, len2;
    int i, j;
    int flag = 0;

    len1 = StrLen(str1); //give to the variable len1 the length of the first word
    len2 = StrLen(str2); //give to the variable len2 the length of the second word

    for (i = 0; i < len1; i++)
    {
        for (j = 0; j < len2; j++)
        {
            if (str1[i] == str2[j])//checking if the letter in place i int both of the words are same
                flag = 1;//a helping variable to know if the letters are same
        }
        if (flag == 0)//if the letters are differnet the function returns the value 0
            return 0;
        flag = 0;
    }
    return 1;
}
//---------------------------------------------------------

void SimillarWords(char line[])//function that takes a string and prints the simillar word ,words that all of her letters in the second word with no difference between the capital letters and the small letter and how much the letter appears
{
    int i, j;
    char word1[FIFTEEN], word2[FIFTEEN];
    int flag = 0;
    char small1[FIFTEEN]; 
    char small2[FIFTEEN];

    int numwords = CountWords(line);//give the variable numwords the count of the words of the string 

    for (i = 1; i < numwords; i++)//scaning the words that  in the string 
    {
        SetWord(line, word1, i); //set the word number i from the string to a new string with name word 1
        ConvertToSmall(word1, small1);//convert  all of the letters that in the string to small letters

        for (j = i + 1; j <= numwords; j++)
        {
            SetWord(line, word2, j);//set the word number j from the string to a new string with name word 2
            ConvertToSmall(word2, small2);

            if (Are_Simillars(small1, small2) == 1 || Are_Simillars(small2, small1) == 1)//checking if the two words are simillar 
            {
                flag = 1;//checking if they are simillar words in the string
                printf("%s %s\n", word1, word2);
            }
        }
    }

    if (flag == 0)
        printf("No simllar words!!\n");
}
//-----------------------------------------------
void ConvertToSmall(char str[], char newstr[])//the function takes a string and convert  all of the letters that in the string to small letters in a new string
{
    int i;
    CleanStr(newstr);//clean the string after we used it to stay away from the problems that will be if we donts clean the string
    for (i = 0; str[i] != '\0'; i++)//scaning the string until to arrive to the char \0
    {
        if (str[i] >= 'A' && str[i] <= 'Z')//checking if the letter in place i in the string is capital letter

            newstr[i] = str[i] + VALUE;//convert the letter to be a small letter and set the letter in the new str
        else
            newstr[i] = str[i];
    }
    newstr[i] = '\0';//put the char \0 to show the end of the string
}
//-------------------------------------
int CheckBrackets(char string[])//checking if  all the elemints in the string are brackets
{
    int count = 0, longstring;
    longstring = StrLen(string);//give to the variable longstring the length of the string
    for (int i = 0; i <= longstring; i++)
        if (string[i] == '(' || string[i] == ')')//checking if the all the elemints in the string are brackets
            count++;//count the brackets

    if (count == longstring)
        return 1;
    else
        return 0;
}

//--------------------------------------------

int CheckTheNumOFBrackets(char string[])//checking if the number of the open brackest are equal to the number of the closed brackets
{
    int i, count1 = 0, count2 = 0;
    int longstring = StrLen(string);//give to the variable longstring the length of the string
    if (CheckBrackets(string) == 1)//checking if all the elemints in the string are brackets 
    {
        for (i = 0; i < longstring; i++)
        {
            if (string[i] == '(')//count the open brackets
                count1++;
            else
                count2++; //count the closed brackets
        }
        if (count1 == count2)//checking if the count of the opened brackets equal to the closed bracktes
            return 1;
        else
            return 0;
    }
    else
        return 0;
}
//----------------------------------------
BOOL StringChecker(char string[])//checking if the string brackets is vaild or not the function returns true if yes else returns false
{
    int i, j;

    if (CheckTheNumOFBrackets(string) == 1)//checking if the number of the open brackest are equal to the number of the closed brackets 
    {
        if (string[0] != ')' && string[StrLen(string) - 1] != '(')
        {
            for (int i = 0; i < StrLen(string); i++)//scaning the string until to arrive to the end of the string
            {
                if (string[i] == '(' || string[i] == '0' || string[i] == '1')
                {
                    if (string[i] == '(')//checking if the string in place i is opened brackets
                    {
                        string[i] = '1';//convert the opened brackets in place i in the string to the char 1
                        for (j = 0; string[j] != ')'; j++)
                            ;
                        string[j] = '0';//convert the closed brackets in place j in the string to the char 0
                    }
                }
                else
                    return FALSE;//that mean that the brackets string is invaild
            }
            if (ClosedBracketsCheck(string) == 1)
                return TRUE;//that mean that the brackets string is vaild
            else
                return FALSE;//that mean that the brackets string is invaild
        }
        else
            return FALSE;//that mean that the brackets string is invaild
    }
    else
    {
        return FALSE;//that mean that the brackets string is invaild
    }
}
//----------------------------------

int ClosedBracketsCheck(char string[]) //checking if the the first brackest is closed and if the last brackets is open because in this situation the string is invaild
{
    int i;
    for (i = 0; i < StrLen(string); i++)
    {
        if (string[i] == ')' || string[i] == '(')//checking if the the first brackest is closed and if the last brackets is open
            return 0;
        else
            return 1;
    }
}
//--------------------------------------------
