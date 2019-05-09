//********************************************************
// Name:        Joe Pickert
// KUID:        2798865
// Section:     MWF 10:00-10:50
// Instructor:  Scott Coston
// Assignment:  Lab 06 spring 2018
//********************************************************
#include <iostream>
using namespace std;

void callMenu(char c,string a, string b, string d, string f, string e)
{           while(c!='e')
                {cout << a;
                cin >> c;
                switch(c)
                {case 'a':
                    cout << b;
                    break;
                case 'b':
                    cout << d;
                    break;
                case 'e':
                    cout << "\t" << e;
                    break;
                default:
                    cout << "\t" <<f;
                    break;}
                }
}

int main()
{
    string menuT="\n==== Menu Top ====\nA\tGoTo Menu A\nB\tGoTo Menu B\nE\tExit: ";
    string menuA="\n\t==== Menu A ====\n\tA\tDo Action A\n\tB\tDo Action B\n\tE\tExit: ";
    string menuB="\n\t==== Menu B ====\n\tA\tDo Action A\n\tB\tDo Action B\n\tE\tExit: ";
    string mexit="Exit Menu\n";
    string badi ="Bad Input\n";
    string dida ="\tDid A\n";
    string didb ="\tDid B\n";

    char c='\0';
    while(c!='e')
    {   cout << menuT;
        cin >> c;
        switch(c)
            {case 'a':
               {callMenu(c, menuA, dida, didb, badi, mexit);}
                break;
            case 'b':
               {callMenu(c, menuB, dida, didb, badi, mexit);}
               break;
            case 'e':
                cout << mexit;
                break;
            default: cout << badi;
                break;
            }
    }
    return 0;
}
