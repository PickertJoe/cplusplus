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

struct book{
    string name;
    string genre;
    string year;
    string author;
    bool available;
};

book newbook(int);
void printbook(book [], int);
void read(book [], int&);
void comb(book [], int);
void modify(book [], int);
void destroy(book [], int&);
void write(book [], int);

int main(){
    int bookcount=0;
    book database[100];
    char c='\0';
    string Menu="\nPlease select a choice from the options below.\na. Add a book to the database\nb. Search the database for a book\nc. Modify an existing book entry\nd. Delete an entry from the databse\ne. Print contents of the database\nf. Save changes and exit the database\n";
    read(database, bookcount);
    while(c!='f')
    {cout<<"\nWelcome to the Joe Pickert Library Database!\n";
    cout<<Menu;
    cin>>c;
    switch(c)
        {case 'a':
            cin.ignore();
            database[bookcount]=newbook(bookcount);
            bookcount++;
            break;
        case 'b':
            cin.ignore();
            comb(database, bookcount);
            break;
        case 'c':
            cin.ignore();
            modify(database, bookcount);
            break;
        case 'd':
            cin.ignore();
            destroy(database, bookcount);
            break;
        case 'e':
            printbook(database, bookcount);
            break;
        case 'f':
            cout<<"Saving changes...\n";
            write(database, bookcount);
            break;
        default:
            cout<<"Invalid input. Please try again.\n";
            break;
        }

    }
    return 0;
}

void read(book database [], int& bookcount)
{   ifstream fin("ProjectIII_Pickert.txt");
    if(!fin.is_open()){cout<<"Database does not yet contain entries.\n"; return;}
    else{
        fin >> bookcount;
        if(bookcount>100){
        bookcount=100;
        for(int i=0; i<bookcount; i++)
           {getline(fin, database[i].name, '\t');
            getline(fin, database[i].genre,'\t');
            getline(fin, database[i].year,'\t');
            getline(fin, database[i].author,'\t');
            fin>>database[i].available;}}
        else{
            for(int i=0; i<bookcount; i++)
           {getline(fin, database[i].name, '\t');
            getline(fin, database[i].genre,'\t');
            getline(fin, database[i].year,'\t');
            getline(fin, database[i].author,'\t');
            fin>>database[i].available;}}
            fin.close();
}}

book newbook(int bookcount){
    if(bookcount>=100){cout<<"\nBook database is full. Please delete entries before adding new ones.\n";}
    else{book rec;
    char a='\0';
    cout<<"\nPlease enter the title of your book: ";
    getline(cin, rec.name);
    cout<<"\nPlease enter the genre of your book: ";
    getline(cin, rec.genre);
    cout<<"\nPlease enter the year of publication for your book: ";
    getline(cin, rec.year);
    cout<<"\nPlease enter the author of your book: ";
    getline(cin, rec.author);
    while(a!='y' && a!='n'){
    cout<<"\nIs your book available for checkout? Y/N: ";
    cin>>a;
    if(a=='y'){rec.available=true;}
    else if(a=='n'){rec.available=false;}
    else{cout<<"Invalid input. Please enter 'y' or 'n'.";}}
    return rec;}}

void comb(book database [], int bookcount){
    if(bookcount==0){cout<<"\nNo records exist in the database. Please input data first.\n";return;}
    else{string M="\n\nPlease select a criterion for your book search:\na. Title\nb. Author Name\nc. Genre\n";
    char c='\0';
    bool hold=true;
    while(hold){
        string s;
        char d='\0';
        book filler [100];
        int counter=0;
        cout<<M;
        cin>>c;
        switch(c){
            case 'a':
                cout<<"\nPlease enter the title of the book: ";
                cin.ignore();
                getline(cin, s);
                for(int i=0; i<bookcount; i++)
                {if(s==database[i].name){
                filler[counter].name=database[i].name;
                filler[counter].genre=database[i].genre;
                filler[counter].year=database[i].year;
                filler[counter].author=database[i].author;
                filler[counter].available=database[i].available;
                counter++;}}
                if(counter>0){cout<<"The following book/books matched your search: \n";printbook(filler, counter);}
                else{cout<<"Book was not found.";}
                cout<<"\nWould you like to conduct another search(Y/N)? ";
                cin>>d;
                if(d=='y'||d=='Y'){break;}
                else if(d=='n'||d=='N'){hold=false;}
                else{cout<<"\nInvalid input. Returning to search menu.\n";}
                break;
            case 'b':
                cout<<"\nPlease enter the author's name: ";
                cin.ignore();
                getline(cin, s);
                for(int i=0; i<bookcount; i++)
                {if(s==database[i].author){
                filler[counter].name=database[i].name;
                filler[counter].genre=database[i].genre;
                filler[counter].year=database[i].year;
                filler[counter].author=database[i].author;
                filler[counter].available=database[i].available;
                counter++;}}
                if(counter>0){cout<<"The following book/books matched your search: \n";printbook(filler, counter);}
                else{cout<<"Book was not found.";}
                cout<<"\nWould you like to conduct another search(Y/N)? ";
                cin>>d;
                if(d=='y'||d=='Y'){break;}
                else if(d=='n'||d=='N'){hold=false;}
                else{cout<<"\nInvalid input. Returning to search menu.\n";}
                break;
            case 'c':
                cout<<"\nPlease enter the book's genre: ";
                cin.ignore();
                getline(cin, s);
                for(int i=0; i<bookcount; i++)
                {if(s==database[i].genre){
                filler[counter].name=database[i].name;
                filler[counter].genre=database[i].genre;
                filler[counter].year=database[i].year;
                filler[counter].author=database[i].author;
                filler[counter].available=database[i].available;
                counter++;}}
                if(counter>0){cout<<"The following book/books matched your search: \n";printbook(filler, counter);}
                else{cout<<"Book was not found.";}
                cout<<"\nWould you like to conduct another search(Y/N)? ";
                cin>>d;
                if(d=='y'||d=='Y'){break;}
                else if(d=='n'||d=='N'){hold=false;}
                else{cout<<"\nInvalid input. Returning to search menu.\n";}
                break;
            default:
                cout<<"Invalid input. Please try again.\n";
                break;
}}return;}}

void modify(book database [], int bookcount){
    if(bookcount==0){cout<<"\nNo records exist in the database to modify. Please input data first.\n";return;}
    else{string s=""; book m [100]; book z [1]; bool hold; int smallcounter=0; string a="";
        char c; string t; int mark1=0; int mark2=0;
    cout<<"\nPlease enter the name of the book you would like to modify: ";
    getline(cin, s);
    for(int i=0; i<bookcount; i++)
    {if(s==database[i].name){
        m[smallcounter].name=database[i].name;
        m[smallcounter].genre=database[i].genre;
        m[smallcounter].year=database[i].year;
        m[smallcounter].author=database[i].author;
        m[smallcounter].available=database[i].available;
        smallcounter++;mark1=i;}}
    if(smallcounter==0){cout<<"\nBook was not found. Returning to main menu.\n";return;}
    else if(smallcounter>1){cout<<"\nMultiple entries found.\n";
        printbook(m ,smallcounter);
        smallcounter=0;
        cout<<"\nPlease narrow search by entering author's name: ";
        getline(cin, a);
        for(int i=0; i<bookcount; i++)
            {if(a==database[i].author && s==database[i].name){
                z[0].name=m[i].name;
                z[0].genre=m[i].genre;
                z[0].year=m[i].year;
                z[0].author=m[i].author;
                z[0].available=m[i].available;
                smallcounter++;mark2=i;}}
        cout<<smallcounter;
        if(smallcounter==0){cout<<"\nNo author match found. Returning to main menu."; return;}
        else{printbook(z, smallcounter);
        while(hold){
            char c='\0';
            cout<<"\nSelect the book attribute that you'd like to modify:\na. Name\nb. Genre\nc. Year\nd. Author\ne. Availability\nf. Exit modification menu\n";
            cin>>c;
            switch(c){
            case 'a':
                cout<<"\nEnter the new name of the book: ";
                cin.ignore();
                getline(cin, t);
                z[0].name=t;
                database[mark2]=z[0];
                cout<<"New record is: ";
                printbook(z, smallcounter);
                cout<<"\n Returning to modification menu...\n";
                break;
            case 'b':
                cout<<"\nEnter the new genre of the book: ";
                cin.ignore();
                getline(cin, t);
                z[0].genre=t;
                database[mark2]=z[0];
                cout<<"New record is: ";
                printbook(z, smallcounter);
                cout<<"\n Returning to modification menu...\n";
                break;
            case 'c':
                cout<<"\nEnter the new publication year of the book: ";
                cin.ignore();
                getline(cin, t);
                z[0].year=t;
                database[mark2]=z[0];
                cout<<"New record is: ";
                printbook(z, smallcounter);
                cout<<"\n Returning to modification menu...\n";
                break;
            case 'd':
                cout<<"\nEnter the new author of the book: ";
                cin.ignore();
                getline(cin, t);
                z[0].author=t;
                database[mark2]=z[0];
                cout<<"New record is: ";
                printbook(z, smallcounter);
                cout<<"\n Returning to modification menu...\n";
                break;
            case 'e':
                cout<<"\nChanging availability...\n ";
                z[0].available= !z[0].available;
                database[mark2]=z[0];
                cout<<"New record is: ";
                printbook(z, smallcounter);
                cout<<"\n Returning to modification menu...\n";
                break;
            case 'f':
                cout<<"\nExiting menu...\n";
                hold=false;
                break;
            default:
                cout<<"\nInvalid input. Please try again.\n";}}}}
    else{printbook(m, smallcounter);
        while(hold){
            char c='\0';
            cout<<"\nSelect the book attribute that you'd like to modify:\na. Name\nb. Genre\nc. Year\nd. Author\ne. Availability\nf. Exit modification menu\n";
            cin>>c;
            switch(c){
            case 'a':
                cout<<"\nEnter the new name of the book: ";
                cin.ignore();
                getline(cin, t);
                m[0].name=t;
                database[mark1]=m[0];
                cout<<"New record is: ";
                printbook(m, smallcounter);
                cout<<"\n Returning to modification menu...\n";
                break;
            case 'b':
                cout<<"\nEnter the new genre of the book: ";
                cin.ignore();
                getline(cin, t);
                m[0].genre=t;
                database[mark1]=m[0];
                cout<<"New record is: ";
                printbook(m, smallcounter);
                cout<<"\n Returning to modification menu...\n";
                break;
            case 'c':
                cout<<"\nEnter the new publication year of the book: ";
                cin.ignore();
                getline(cin, t);
                m[0].year=t;
                database[mark1]=m[0];
                cout<<"New record is: ";
                printbook(m, smallcounter);
                cout<<"\n Returning to modification menu...\n";
                break;
            case 'd':
                cout<<"\nEnter the new author of the book: ";
                cin.ignore();
                getline(cin, t);
                m[0].author=t;
                database[mark1]=m[0];
                cout<<"New record is: ";
                cout<<mark1;
                cout<<"\n"<<bookcount;
                printbook(m, smallcounter);
                cout<<"\n Returning to modification menu...\n";
                break;
            case 'e':
                cout<<"\nChanging availability...\n ";
                m[0].available= !m[0].available;
                database[mark1]=m[0];
                cout<<"New record is: ";
                printbook(m, smallcounter);
                cout<<"\n Returning to modification menu...\n";
                break;
            case 'f':
                cout<<"\nExiting menu...\n";
                hold=false;
                break;
            default:
                cout<<"\nInvalid input. Please try again.\n";}}}}return;}


void printbook(book database [], int counter){
    if(counter==0){
        cout<<"Library database is currently empty. Please add some records!\n\n";
        return;
        }
    else{
        for(int i=0; i<counter; i++)
           {cout<<"\nBook title: "<<database[i].name<<"\n";
            cout<<"Book genre: "<<database[i].genre<<"\n";
            cout<<"Year published: "<<database[i].year<<"\n";
            cout<<"Book author: "<<database[i].author<<"\n";
            cout<<"Available?: ";
            if(database[i].available==true){cout<<"Y\n";}
            else{
                cout<<"N\n";
                }
            }
    }
}

void destroy(book database [], int& bookcount){
    if(bookcount==0){cout<<"\nNo records exist in the database to delete. Please input data first.\n";return;}
    else{string d;
    cout<<"Please enter the name of the book you would like to delete from the database: ";
    getline(cin, d);
    for(int i=0; i<bookcount; i++)
    {if(d==database[i].name){
        database[i].name=database[bookcount-1].name;
        database[i].genre=database[bookcount-1].genre;
        database[i].year=database[bookcount-1].year;
        database[i].author=database[bookcount-1].author;
        database[i].available=database[bookcount-1].available;
        bookcount--;
        cout<<"\nBook was removed from database.\n";return;}}
    cout<<"Book was not found.";
}}


void write(book database[], int number)
{   ofstream fout("ProjectIII_Pickert.txt");
    fout<<number;
    for(int i=0; i<number; i++)
       {fout<<database[i].name<<"\t";
        fout<<database[i].genre<<"\t";
        fout<<database[i].year<<"\t";
        fout<<database[i].author<<"\t";
        fout<<database[i].available;}
        fout.close();}
