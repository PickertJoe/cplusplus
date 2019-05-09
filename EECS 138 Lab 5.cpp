//********************************************************
// Name:        Joe Pickert
// KUID:        2798865
// Section:     MWF 10:00-10:50
// Instructor:  Scott Coston
// Assignment:  Lab 05 2018 spring
//********************************************************
// Program Summary
// ---------------
//
// ---------------

#include <iostream>
using namespace std;

int main()
{
    for(int i=0; i<=3; i+=1)
        {for(int j=0; j<=3; j+=1)
            {cout << "X";}
        cout <<"\n";}
    cout <<"\n";

    for(int i=0; i<=3; i+=1)
        {for(int j=3; j>=i; j-=1)
            {cout <<"*";}
        cout <<"\n";}
    cout <<"\n";

    for(int i=1; i<=4; i+=1)
        {for(int g=0; g<i; g+=1)
            {cout <<"0";}
        for(int j=4; j>=i; j-=1)
            {cout <<"1";}
        cout <<"\n";}
    cout <<"\n";

for(int i=0; i<=3; i+=1)
    {for(int j=0; j<=3 && i%2!=0; j+=1)
        {cout <<"=";}
    for(int g=0; g<=3 && i%2==0; g+=1)
        {cout <<"-";}
    cout << "\n";}
    return 0;
}
