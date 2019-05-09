//********************************************************
// Name:        Joe Pickert
// KUID:        2798865
// Section:     MWF 10:00-10:50
// Instructor:  Scott Coston
// Assignment:  Lab 02
//********************************************************
// Program Summary
// ---------------
//
// --add some summary comments here--


# include <iostream>
using namespace std;

int main()
{
    double radius, surfaceArea, volume, cylinder;
    double pi=3.14159;
    double SA= 4.00;
    double V= 1.33333;
    cout << "Enter the radius of the sphere: ";
    cin >> radius;

    surfaceArea =(SA * pi * radius * radius);
    volume= (V * pi * radius * radius * radius);
    cylinder= pi * radius * radius * radius;
    if (radius>0){
    cout << "The surface area of the sphere is: " << surfaceArea << "\n";
    cout << "The volume of the sphere is: " <<volume << "\n" ;
    cout <<"The volume of the cylinder with height r is: " <<cylinder << "\n";
    }else {
        cout << "Error, invalid input. Please type a value greater than zero. \nInitiating self-destruct sequence." << "\n";
    }


}
