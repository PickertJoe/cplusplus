//********************************************************
// Name:        Joe Pickert
// KUID:        2798865
// Section:     MWF 10:00-10:50
// Instructor:  Scott Coston
// Assignment:  Spring 2018 Project 2
//********************************************************
//
//

#include <iostream>
#include <fstream>

using namespace std;

void print (double exam[], int no_of_exams, double lab[], int no_of_labs, double project[], int no_of_projects, double weighted_mean, double best_of_project, double average_of_labs, double total_marks, char grade, string comments, string name)
{   cout<<"\nStudent name is: "<<name<<"\n";
    cout<<"Grade is "<<grade<<"\n\n";
    ofstream fout("Pickert_ProjectII.txt");
    fout<<"Sample file output starts next:\n\n";
    fout<<"Student name: "<<name<<"\n\n";
    for(int i=0; i<no_of_projects; i++)
        {fout<<"Project "<<i+1<<" mark: "<<project[i]<<"\n";}
    fout<<"The best project mark is: "<<best_of_project<<"\n\n";
    for(int i=0; i<no_of_exams; i++)
        {fout<<"Exam "<<i+1<<" mark: "<<exam[i]<<"\n";}
    fout<<"The weighted mean of the exam marks is: "<<weighted_mean<<"\n\n";
    for(int i=0; i<no_of_labs; i++)
        {fout<<"Lab "<<i+1<<" mark: "<<lab[i]<<"\n";}
    fout<<"The average of the lab marks is: "<<average_of_labs<<"\n\n";
    fout<<"Overall mark obtained is: "<<total_marks<<"\n\n";
    fout<<comments;
    fout.close();}

double computeV(string s, double a[])
{   if(s=="project")
        {double temp=0;
        for(int i=0; i<3; i++)
            {if(a[i]>temp){temp=a[i];}}
        return temp;}
    else if(s=="lab")
        {double sum=0; double average;
        for(int i=0; i<5; i++){sum=sum+a[i];}
         average=sum/5.00;
         return average;}
    else
        {double top=0; double bottom=101; double weighted;
        for(int i=0; i<2; i++)
            {if (a[i]>top){top=a[i];}}
        for(int i=0; i<2; i++)
            {if (a[i]<bottom){bottom=a[i];}}
        weighted=(top*2.00+bottom)/3.00;
        return weighted;}}

void fillA(double a[], int almt, string txt, double& compV, bool D)
{   if (D==true){cout<<"That menu choice was already selected.\n";}
    else
    {for(int i=0; i<almt; i++)
        {while(true)
        {cout<<"Enter "<<txt<<" "<<i+1<<" mark> ";
        cin>>a[i];
        if(a[i]>=0 && a[i]<=100){break;}
        else{cout<<"The mark entered is invalid. Please enter a value between 0 and 100 inclusive.\n";}}}
        compV=computeV(txt, a);
        cout<<"The "<<txt<<" mark considered for grading is: "<<compV<<"\n";}}

void getname(string& name)
{   cout<<"Enter the name of the student: ";
    cin>> name;}

void badinput(char a, char b){
    if (a=='m'){cout<<b<<" is not a valid menu option\n";}
    else if (a=='g'){cout<<"The mark entered is invalid. Values must be between 0 and 100 inclusive.\n";}
    else if(a=='d'){cout<<"Please select all other choices before selecting option d\n";}}

char done(double total, string& comments)
{   if (total>=90){comments="Outstanding"; return 'a';}
    else if (total>=80 && total<90){comments="Good"; return 'b';}
    else if (total>=70 && total<80){comments="Needs to improve"; return 'c';}
    else if (total>=60 && total<70){comments="Warning of probation"; return 'd';}
    else{comments="Failed"; return 'f';}}

void menu(){
    char c='\0';
    char grade;
    bool l=false;
    bool e=false;
    bool p=false;
    double lab[10];
    double exam[10];
    double project[10];
    double average_of_labs;
    double weighted_mean;
    double best_of_projects;
    double total_marks=0;
    int no_of_labs=5;
    int no_of_exams=2;
    int no_of_projects=3;
    string pro="project";
    string lb="lab";
    string ex="exam";
    string name;
    string comments;
    string menuT="\nSelect a menu choice from the following options.\na. Project Marks\nb. Lab Marks\nc. Exam Marks\nd. Calculate total marks\n";
    getname(name);
    while((l==false || e==false || p==false) || (c!='d'))
    {char m='m';
    cout<<menuT;
    cin>>c;
    switch(c)
        {case 'a':
            fillA(project,no_of_projects, pro, best_of_projects, p);
            if(p==false){p=!p;}
            break;
         case 'b':
             fillA(lab, no_of_labs, lb, average_of_labs, l);
             if(l==false){l=!l;}
             break;
         case 'c':
             fillA(exam, no_of_exams, ex, weighted_mean, e);
             if(e==false){e=!e;}
             break;
         case 'd':
             if(l==false || e==false || p==false){m='d'; badinput(m, c);}
             else
                {total_marks=((average_of_labs*.25)+(weighted_mean*.5)+(best_of_projects*.25));
                grade=done(total_marks, comments);
                print(exam, no_of_exams, lab, no_of_labs, project, no_of_projects, weighted_mean, best_of_projects, average_of_labs, total_marks, grade, comments, name);}
             break;
         default:
            badinput(m, c);
            break;}}}

int main(){
    menu();
return 0;
}
