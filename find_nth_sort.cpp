//********************************************************
// Name:        Joe Pickert
// KUID:        2798865
// Section:     MWF 10:00-10:50
// Instructor:  Scott Ccoston
// Assignment:  Lab 09
//********************************************************


#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


int  findNth(int[], int, int);
bool fill_rnd(int[], int);
void printarr(int[], int);
bool here2there(int[], int[], int);

// use srand() to seed the random number generator
// this is important for testing
// you don't want a new series every time while debugging
// fill the a array with random integers from 100 to 999
// print the a array
// just for fun, if you want you can:
// change items from 10 to something else
// change Nth   from  4 to something else
int main(){
    int items=10;
    int Nth  = 4;
    int a[items];

    srand(1);
    fill_rnd(a, items);
    printarr(a, items);
    cout<<"Sorting for the "<<Nth<<"th largest integer\n"<< "Nth:"<<findNth(a, items, Nth)<<"\n";
    return 0;
}

// create receiver arrays (left,right) and size variables
// then while you don't know the Nth item look for it
// use the a[0] item as the pivot
// start your pile sorting at a[1]
// i suggest placing the a array into left and right
// until both left and right are empty and the pivot
// then must be the Nth item
//
int findNth(int a[], int items, int nth){
    int pivot;
    int smaller[items];
    int larger[items];
    int smallersize;
    int largersize;
    while(1){
    pivot=a[0];
    smallersize=0;
    largersize=0;
    for(int i=1; i<items; i++)
       if(pivot<a[i]){larger[largersize]=a[i];largersize++;}
       else{smaller[smallersize]=a[i];smallersize++;}
    if(largersize==(nth-1)){return pivot;}
    else if(smallersize>(nth-1)){here2there(smaller,a,smallersize);items=smallersize;nth=nth-(largersize+1);}
    else{here2there(larger,a,largersize);items=largersize;}
}}


bool here2there(int here[],int there[], int lmt){
    for(int i=0; i<lmt; i++){there[i]=here[i];}
    return true;
}

// you'll return random numbers between 100 and 999
// using rand() as part of a small function using % and +
bool fill_rnd(int a[], int lmt){
    for(int i=0; i<lmt; i++){a[i]= 100+ rand()%899;}
    return true;
}

// you can change the modulo value to change the
// arrangement of the output
void printarr(int a[], int lmt){
    for(int i=0;i<lmt;i=i+(lmt/lmt)){
        cout << a[i] <<" ";if ((i+1)%10==0) cout << "\n";}
    cout <<"\n\n";
    return;
}
