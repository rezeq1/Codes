
#include "WordLadder.h"





void WordLadder::main_func(string file_name, string word1, string word2)
{

    queue<stack<string> > myQueue;

    stack<string> wordladder, copy, ladder, myStack;

    string word, bdeka, token;

    myStack.push(word1);
    myQueue.push(myStack);
    int a = 0;
    ifstream dictionary(file_name);

    list<string> myDictionary, testedWords;

    testedWords.push_front(word1);

    if (dictionary.is_open()) {

        while (dictionary >> token)
            myDictionary.push_front(token);


        while (!(myQueue.empty())) {

            ladder = myQueue.front();
            myQueue.pop();
            word = ladder.top();

            if (word == word2) {
                a = 1;
                cout << "The ladder :" << endl;// " << word1 << " to " << word2 << " is \n";

                while (!ladder.empty()) {
                    wordladder.push(ladder.top());
                    ladder.pop();
                }
                cout << "lader size:" << wordladder.size() << endl;

                while (!wordladder.empty()) {
                    cout << wordladder.top() << endl;
                    wordladder.pop();
                }

            }
            else {

                bdeka = help1(word, myDictionary, testedWords);

                if (!(word_exist(testedWords, bdeka))) {
                    copy = ladder;
                    copy.push(bdeka);
                    myQueue.push(copy);
                    testedWords.push_front(bdeka);
                }
            }

        }
    }
    else
        cout << "error file dose not open" << endl;

    if (a == 0)
        cout << "NO word-ladder found" << endl;
}



int WordLadder::Differnet(string word1, string word2)
{
    int counter = 0;
    for (int i = 0; i < word1.length(); i++)
    {
        if (word1[i] != word2[i])
            counter++;
    }

    return counter;
}

string WordLadder::help1(string word, list<string> myDictionary, list<string> list2)
{
    string test;

    for (int k = 0; k < myDictionary.size(); k++) {
        test = return_word(myDictionary, k);

        if (Differnet(test, word) == 1)
        {
            if (word_exist(list2, test) == false)
                return test;
        }
    }
}

string WordLadder::return_word(list<string> g, int index)
{
    int index2 = 0;
    list<string>::iterator it;
    for (it = g.begin(); it != g.end(); it++) {
        if (index2 == index)
            return (*it);
        index2++;
    }
}

bool WordLadder::word_exist(list<string>g, string word)
{
    list<string>::iterator it;
    for (it = g.begin(); it != g.end(); it++)
        if ((*it) == word)
            return true;

    return false;
}
int main(int argc, char *argv[])
{
    WordLadder a;
    a.main_func(argv[1], argv[2], argv[3]);
    //system("pause");
    return 0;
}
