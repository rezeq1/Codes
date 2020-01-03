

#ifndef UNTITLED_WORDLADDER_H
#define UNTITLED_WORDLADDER_H

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <fstream>
#include<iterator>
#include<list>

using namespace std;

class WordLadder {
    int Differnet(string word1, string word2);
    string help1(string, list<string>, list<string>);
    string return_word(list<string>, int);
    bool word_exist(list<string>, string);

public:

    void main_func(string, string, string);


};

#endif //UNTITLED_WORDLADDER_H
