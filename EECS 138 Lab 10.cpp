//********************************************************
// Name:        Joe Pickert
// KUID:        2798865
// Section:     MWF 10:00-10:50
// Instructor:  Scott Ccoston
// Assignment:  Lab 10
//********************************************************


#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;


bool fill_rnd(int[], int);
void printarr(int[], int);
void sortarray(int[], int);
void median(int[], int);
void kmin(int[], int);
void UpperC(char[], int);
void printarr(char[], int);


int main(){
    int items=20;
    int a[items];
    int nameitems=40;
    char name[nameitems];



    srand(1);
    fill_rnd(a, items);
    cout<<"Original array: ";
    printarr(a, items);
    sortarray(a, items);
    cout<<"Sorted array: ";
    printarr(a, items);
    median(a, items);
    kmin(a, items);
    cout<<"\nType your name in lower case, include spaces: ";
    cin.ignore();
    cin.getline(name, 40);
    UpperC(name, nameitems);
    cout<<"Capitalized name: ";
    printarr(name,40);
    return 0;
}
bool fill_rnd(int a[], int lmt){
    for(int i=0; i<lmt; i++){a[i]= 100+ rand()%900;}
    return true;
}

void sortarray(int a[], int lmt)
    {for(int i=0; i<lmt; i++)
        {for(int j=0; j<lmt; j++)
            {if (a[j]>a[i])
                {int flip= a[i];
                 a[i]=a[j];
                 a[j]=flip;}}}}

void median(int a[], int lmt)
{   int mid; double median;
    mid=lmt/2;
    if(lmt%2==0)
        {median=(a[mid]+a[mid-1])/2.0;
        cout<<"Array median is: "<<median<<"\n\n";}
    else
        {median=a[mid];
        cout<<"Array median is: "<<median<<"\n\n";}}

void kmin(int a[], int lmt)
{   int k=1;
    while(k!=0)
    {cout<<"Input number between 1 and "<<lmt<<" or, type 0 to escape: ";
    cin>>k;
    int r[k];
    for(int i=0; i<k; i++)
    {r[i]=a[i];}
    printarr(r, k);}}

void UpperC(char a[], int lmt){
    for(int i=0; i<lmt; i++)
    {if (a[i]==000)
        {break;}
    else if (i==0)
        {(a[i]=a[i]-32);}
    else if (a[i]==040)
        {(a[i+1]=a[i+1]-32);}}}

void printarr(int a[], int lmt){
    for(int i=0;i<lmt;i=i+(lmt/lmt)){
        cout << a[i] <<" ";}
    cout <<"\n\n";
    return;
}

void printarr(char a[], int lmt){
    for(int i=0;i<lmt;i=i+(lmt/lmt)){
        if(a[i]==000)
        {break;}
        else
        cout << a[i];}
    cout <<"\n\n";
    return;
}
