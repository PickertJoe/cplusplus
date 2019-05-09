//********************************************************
// Name:        Joe Pickert
// KUID:        2798865
// Section:     MWF 10:00-10:50
// Instructor:  Scott Ccoston
// Assignment:  Project III
//********************************************************


#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>


using namespace std;


void printarr(int[][4]);


void printarr(char[][40]);

const int no_of_books=100;
int bookcount=0;


struct book{
    string name;
    string genre;
    string year;
    string author;
    string available;
    };

book newbook();
book database[no_of_books];


int main(){
    char c='\0';
    string Menu="\nPlease select a choice from the options below.\na. Add a book to the database\nb. Search the database for a book\nc. Modify an existing book entry\nd. Delete an entry from the databse\ne. Save changes and exit the databse\n";


    while(c!='e')
    {cout<<"\nWelcome to the EECS 138 Library Database!\n";
    cout<<Menu;
    cin>>c;
    switch(c)
        {case 'a':
            cin.ignore();
            database[bookcount]=newbook();
            break;
        case 'b':
            break;
        case 'c':
            break;
        case 'd':
            break;
        case 'e':
            cout<<"Saving changes...\n";
            break;
        }

    }
    return 0;
}

book newbook(){
    book rec;
    cout<<"Please enter the title of your book\n";
    getline(cin, rec.name);
    cout<<"\nPlease enter the genre of your book\n";
    getline(cin, rec.genre);
    cout<<"\nPlease enter the year of publication for your book\n";
    getline(cin, rec.year);
    cout<<"\nPlease enter the author of your book\n";
    getline(cin, rec.author);
    cout<<"\nIs your book available for checkout? Y/N\n";
    getline(cin, rec.available);
    return rec;}


void enter(char a[][40], int number, int names)
{   cin.ignore();
    for(int i=0; i<names; i++)
        {cout<<"Enter student "<<i+1<<"'s name: ";
        cin.getline(a[i], number);}}





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

