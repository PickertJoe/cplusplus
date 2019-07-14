//********************************************************
// Name:        Joe Pickert
// KUID:        2798865
// Section:     MWF 10:00-10:50
// Instructor:  Scott Coston
// Assignment:  Lab 03 spring 2018
//********************************************************
// Program Summary
// ---------------
//
// --add some summary comments here--

#include <iostream>
using namespace std;

int main()
{
    int black;
    bool blue= true;

    cout << "=====PRIME TESTER=====\n";
    while (true)
        {
        cout << "input integer for testing: ";
        cin >> black;
        if (1 < black){
                if(black > 2)
                {for(int red=2; red<black; red++)
                {   if(black%red==0)
                    {blue=false;break;}}}

            if(blue){
                cout << black << " is prime \n";
            }
            else{
                cout << black << " is not prime \n";};
        }
        else
            if (black < 1) {cout << "====ALL DONE=====\n";break;}
            else          {cout << "====TRY AGAIN====\n";      }
        }
    return 0;
}
