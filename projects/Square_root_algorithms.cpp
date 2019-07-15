//********************************************************
// Name:        Joe Pickert
// KUID:        2798865
// Section:     MWF 10:00-10:50
// Instructor:  Scott Coston
// Assignment:  2018 spring Project 1
//********************************************************
// Program Summary
// ---------------
//
//
//

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;



double sqrt1(double value, bool diag)
{   double g1=2; double g2=1;
    while((abs(g2-g1))>(1.00e-14))
        {g2=value/g1;
        g1=(g2+g1)/2;
        if(diag==1)
            {cout <<"g1="<<g1 <<" g2="<< g2<<"\n";}}
        cout<<"\t"<<g1<<"\n\n";}


double sqrt2(double value, bool diag)
{double g=0;
double p=1.00;
    for(int i=0; i<15; i=i+1)
    {for(int j=0; j<11; j=j+1)
            {if(g>sqrt(value))
            {g=g-p;
                if(diag==1)
                {cout << "g="<<g<<"\n";}
                break;}
            else
            {{g=g+p;}
                if(diag==1)
                {cout<<"g="<<g<<"\n";}}}
        p=p*0.1;
    }
cout<<"\t"<<g<<"\n";
}

double sqrt3(double value, bool diag)
{double g=0; double p=1.00; int n=1;
    while (abs(g-sqrt(value))>(1.00e-14))
        {if(n%2!=0)
            {for(;g<sqrt(value);)
            {g=g+p;
            if(diag==1)
            {cout<<"g="<<g<<"\n";}}}
        else
            {for(;g>sqrt(value);)
            {g=g-p;
            if(diag==1)
            {cout<<"g="<<g<<"\n";}}}
            p=p*0.1;
            n=n+1;}
}


double getnewnum(double& n)
{   cout <<"enter new num (0<n<100):";
    cin >>n;
    while(1>n || n>=100)
    {cout <<"\nBad input, try again\n\n";
    cin>>n;}
return n;
}

int main()
{
double n=5;

bool diag=true;
char c='\0';
string menuT= "\n\na\tenter a new number \nb\tdo guess improvement \nc\tdo double for loop \nd\tdo while zig zag \ne\tquit program \no\ttoggle diagnostic input\n";
string badi= "Bad input, try again";
cout << fixed;
cout << setprecision(14);
while(c!='e')
    {cout <<"Square roots\n";
    cout <<"\tTest number is " <<"\n\t"<< n <<"\n";
    cout <<"\tcmath root is " <<"\n\t" <<sqrt(n)<<"\n";
    cout <<"\tDiagnostics "<< diag;
    cout <<menuT;
    cin >> c;
    switch(c)
    {case 'a':
        getnewnum(n);
        break;
    case 'b':
         cout<<"\n";
        sqrt1(n,diag);
        break;
    case 'c':
        sqrt2(n,diag);
        break;
    case 'd':
        sqrt3(n,diag);
        break;
    case 'e':
        cout <<"Quitting";
        break;
    case 'o':
        diag= !diag;
        break;
    default:
        cout << badi;
        break;
    }}
return 0;
}
