//********************************************************
// Name:        Joe Pickert
// KUID:        2798865
// Section:     MWF 10:00-10:50
// Instructor:  Scott Ccoston
// Assignment:  Lab 11
//********************************************************


#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>


using namespace std;


void fill_rnd(int a[][4], int, int);
void task1();
void task2();
void enter(char a[][40], int, int);
void printarr(int[][4]);
//void sortarray(int[], int);
void printarr(char[][40]);

int main(){
    int c;

    cout<<"Welcome to the student lab matrix program!\n\n";
    cout<<"Please enter 1 to write the lab scores of your students to file.\n\n";
    cout<<"Once complete, enter 2 to determine the student with the highest total lab score.\n\n";
    cin>>c;

    if (c==1){task1();}
    else if(c==2 ){task2();}
    else{cout<<"Invalid input. Program will now terminate.\n\n";}
    srand(1);


    return 0;
}

void task1()
{   const int nameitems=40;
    const int numberofnames=5;
    char name[numberofnames][nameitems];
    const int students=5;
    const int scores=4;
    int marks[students][scores];
    enter(name, nameitems, numberofnames);
    fill_rnd(marks, students, scores);
    printarr(name);
    printarr(marks);
    ofstream fout("Lab11_Pickert.txt");
    for(int i=0; i<5; i++)
        {for(int j=0; j<40; j++)
            {if(name[i][j]==000){break;}
            fout<<name[i][j]<<":";}
        fout<<" ";
        for(int j=0; j<4; j++)
            {fout<<marks[i][j]<<" ";}
        fout<<"\n";}
return;}

void task2()
{   ifstream inFile;
    const int nameitems=40;
    const int numberofnames=5;
    char name[numberofnames][nameitems];
    const int students=5;
    const int scores=4;
    int marks[students][scores];
    inFile.open("Lab11_Pickert.txt");
    if(!inFile.is_open()){cout<<"Error: Student lab score matrix does not exist. Program will now close\n";}
    else{
    for(int=0; i<5; i++)
        {

    }
    cout<<"Good to go!";
    }
}

void enter(char a[][40], int number, int names)
{   cin.ignore();
    for(int i=0; i<names; i++)
        {cout<<"Enter student "<<i+1<<"'s name: ";
        cin.getline(a[i], number);}}


void fill_rnd(int a[][4], int lmt1, int lmt2){
    for(int i=0; i<lmt1; i++)
        {for(int j=0; j<lmt2; j++)
            {a[i][j]=rand() % 10;}}
}

/*void sortarray(int a[], int lmt)
    {for(int i=0; i<lmt; i++)
        {for(int j=0; j<lmt; j++)
            {if (a[j]>a[i])
                {int flip= a[i];
                 a[i]=a[j];
                 a[j]=flip;}}}}*/

void printarr(int a[][4]){
    for(int i=0;i<5;i++){
        for(int j=0; j<4; j++)
        {cout << a[i][j] <<" ";}
    cout <<"\n\n";}
    return;
}

void printarr(char a[][40]){
    for(int i=0;i<5; i++){
        for(int j=0; j<40; j++)
        {{if(a[i][j]==000)
        {break;}
        else
        cout << a[i][j];}}
    cout <<"\n\n";}
    return;
}

