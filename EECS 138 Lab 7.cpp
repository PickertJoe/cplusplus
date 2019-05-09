//********************************************************
// Name:        Joe Pickert
// KUID:        2798865
// Section:     MWF 10:00-10:50
// Instructor:  Scott Coston
// Assignment:  Spring 2018 Lab 07
//********************************************************
//
// some general comments?

#include <iostream>
#include <cmath>
using namespace std;

double PI= 3.14159;
double area(int edge);
double area(int radius1, int radius2);
double area(int edge1, int angle, int edge2);
void print(char type, double area);
void elipse();
void square();
void triangle();

double radian(int angle)
{   return (PI/180.0)*double(angle);}

int main(){
    int shape;
    string menuT= "Calculate the area of a shape\n1 - Elipse\n2 - Square\n3 - Triangle\n4 - Exit\t>";
    while(shape!=4)
    {cout << menuT;
    cin >> shape;
    switch(shape)
       {case(1):
           {elipse();
            break;
           }
        case(2):
            {square();
            break;
            }
        case(3):
            {triangle();
            break;
            }
        case(4):
            {cout<<"exiting...\n";
            break;}
        default:
            {cout <<"Bad input, try again\n\n";
            break;}}}}

double area(int edge){
    return pow(edge,2);}

double area(int radius1, int radius2){
    return PI * radius2 * radius1;}

double area(int edge1, int angle, int edge2){
    return .5*edge1*edge2*sin(radian(angle));}

void elipse(){
    double radius1;
    double radius2;
    char type='e';
    cout<<"\nEnter the lengths of the major radius\n\tand the minor radius separated by a space: ";
    cin>> radius1>> radius2;
    print(type,area(radius1, radius2));
}

void square(){
    int edge;
    char type='s';
    cout<< "\nEnter the side of a square: ";
    cin>>edge;
    print(type,area(edge));
}

void triangle(){
    int edge1;
    int angle;
    int edge2;
    char type='t';
    cout<<"\nEnter the first side\n\tfollowed by the angle (deg)\n\t\tfollowed by the second side ";
    cin>>edge1>>angle>>edge2;
    print(type,area(edge1,angle,edge2));
}

void print(char type, double area){
    switch(type)
    {case('e'):
        {cout<< "The area of the ellipse is "<<area<<"\n\n";
        break;}
    case('s'):
        {cout<< "The area of the square is "<<area<<"\n\n";
        break;}
    case('t'):
        {cout<< "The area of the triangle is "<<area<<"\n\n";
        break;}}}
