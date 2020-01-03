#include "Fraction.h"
int main()
{
    Fraction fr1(1,2),fr2(5,10),fr3;
    cout<<fr1<<endl<<fr2<<endl; // 1/2 1/2
    cout<<(fr1!=fr2?"not equals":"equals")<<endl; //equals
    cout<<fr1*fr2<<endl;  // 1/4
    cout<<++fr1<<endl; // 3/2
    cout<<fr2++<<endl; //1/2
    cout<<fr2<<endl;   // 3/2
	cout<<" enter your fraction (for example 3/4) :";
    cin>>fr2;           // for example input : 3/4
    cout<<(fr1>fr2? fr1: fr2)<<endl; // 3/2
    fr3=fr1; // 3/2
    cout<<(fr3+=fr2)<<endl; // 3/2 + 3/4 = 9/4
    int i=6;
    cout<<(i+fr1)<<endl;  //   6 + 3/2 = 15/2
    double d=4.5;
    //cout<<(d+fr1)<<endl; //Error ambiguity !
    cout<<(d+(int)fr1)<<endl;   // 4.5 + 1 = 5.5
    cout<<((double)(fr1)+d)<<endl; // 1.5 + 4.5 = 6
    fr3=fr1; // 3/2
    cout<<(fr3+=i)<<endl; // 3/2 + 6= 15/2

}