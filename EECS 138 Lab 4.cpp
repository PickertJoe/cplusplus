//********************************************************
// Name:        Joe Pickert
// KUID:        2798865
// Section:     MWF 10:00-10:50
// Instructor:  Scott Coston
// Assignment:  Lab 04 spring 2018
//********************************************************
// Program Summary
// ---------------
//
// --add some summary comments here--

#include <iostream>
using namespace std;

int main()
{
    /*
    adjust the menus by inserting escape characters into these 7 variables
    i will deduct heavily if you use spaces
    you will only have to directly cout a few tabs in the A and B menus
    all other output adjustments are made to these variables
    */
    string menuT="\n==== Menu Top ====\nA\tGoTo Menu A\nB\tGoTo Menu B\nE\tExit: ";
    string menuA="\n\t==== Menu A ====\n\tA\tDo Action A\n\tB\tDo Action B\n\tE\tExit: ";
    string menuB="\n\t==== Menu B ====\n\tA\tDo Action A\n\tB\tDo Action B\n\tE\tExit: ";
    string mexit="Exit Menu\n";
    string badi ="Bad Input\n";
    string dida ="\tDid A\n";
    string didb ="\tDid B\n";
    /*
    input and actions for Menu A and Menu B is as follows:
    a - cout dida
    b - cout didb
    e - exits the menu, cout mexit
    ? - anything else is invalid, cout badi
    */
    char c='\0';
    while(c!='e') // replace true with an appropriate boolean expression
    {   cout << menuT;
        cin >> c;
        switch(c)
            {case 'a':
               {char c='\0';
                while(c!='e')
                {cout << menuA;
                cin >> c;
                switch(c)
                {case 'a':
                    cout << dida;
                    break;
                case 'b':
                    cout << didb;
                    break;
                case 'e':
                    cout << "\t" << mexit;
                    break;
                default:
                    cout << "\t" <<badi;
                    break;;
                }}}
                break;

            case 'b':
               {char c='\0';
                while(c!='e')
                {cout << menuB;
                cin >> c;
                switch(c)
                {case 'a':
                    cout << dida;
                    break;
                case 'b':
                    cout << didb;
                    break;
                case 'e':
                    cout << "\t" << mexit;
                    break;
                default:
                    cout << "\t" <<badi;
                    break;
                }}}
                break;
            case 'e':
                cout << mexit;
                break;
            default: cout << badi;
                break;
            }
        //place switch statement for Menu Top next
    }
    return 0;
}
