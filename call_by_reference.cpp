//********************************************************
// Name:        Joe Pickert
// KUID:        2798865
// Section:     MWF 10:00-10:50
// Instructor:  Coston
// Assignment:  Spring 2018 Lab 08
//********************************************************
//
//

#include <iostream>

using namespace std;

// function headers here
// declarations separately below main

// swap makes a=b and b=a
void swap  (int&, int&);
// sort4 takes in 4 ints and swaps their values
// precondition : 4 variables with sorted or unsorted values
// postcondition: variables values are sorted low to high such that
//                the final values result in a<=b<=c<=d
void sort4 (int&, int&, int&, int&);
// send to the screen the values for a,b,c,d
void show  (int,  int,  int,  int);

int main(){
    int a=1;
    int b=3;
    int c=5;
    int d=8;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=1;
     b=3;
     c=8;
     d=5;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=1;
     b=5;
     c=3;
     d=8;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=1;
     b=5;
     c=8;
     d=3;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=1;
     b=8;
     c=3;
     d=5;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=1;
     b=8;
     c=5;
     d=3;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=3;
     b=1;
     c=5;
     d=8;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=3;
     b=1;
     c=8;
     d=5;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=3;
     b=5;
     c=1;
     d=8;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=3;
     b=5;
     c=8;
     d=1;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=3;
     b=8;
     c=1;
     d=5;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=3;
     b=8;
     c=5;
     d=1;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=5;
     b=1;
     c=3;
     d=8;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=5;
     b=1;
     c=8;
     d=3;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=5;
     b=3;
     c=1;
     d=8;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=5;
     b=3;
     c=8;
     d=1;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=5;
     b=8;
     c=1;
     d=3;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=5;
     b=8;
     c=3;
     d=1;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=8;
     b=1;
     c=3;
     d=5;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=8;
     b=1;
     c=5;
     d=3;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=8;
     b=3;
     c=1;
     d=5;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=8;
     b=3;
     c=5;
     d=1;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=8;
     b=5;
    c=1;
     d=3;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";

     a=8;
     b=5;
     c=3;
     d=1;

    show(a,b,c,d);
    sort4(a,b,c,d);
    show(a,b,c,d);
    cout<<"\n";
    return 0;
}

void show(int a, int b, int c, int d){
    cout <<a<<b<<c<<d<<"\t";
}

void swap (int& a, int& b){
    int place;
    place=a;
    a=b;
    b=place;
}

void sort4 (int& a, int& b, int& c, int& d){
    if (a>b){swap(a,b);};
    if (a>c){swap(a,c);};
     if (a>d){swap(a,d);};
     if (b>c){swap(b,c);};
     if (b>d){swap(b,d);};
     if (c>d){swap(c,d);};
}
