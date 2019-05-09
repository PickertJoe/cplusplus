//********************************************************
// Name:        Joe Pickert
// KUID:        2798865
// Section:     MWF 10:00-10:50
// Instructor:  Scott Coston
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
    int b=2;
    int c=3;
    int d=4;
    show(a,b,c,d);
    cout<<a;

    // run some test cases by calling sort4 several
    // times with different values for a,b,c and d
    // nothing crazy but be systematic with the cases

    return 0;
}

void show(int a, int b, int c, int d){
    cout <<a<<b<<c<<d<<"\n";
}

void swap (int&, int&){
}

void sort4(int&, int&, int&, int&){
}

