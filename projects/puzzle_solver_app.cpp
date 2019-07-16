
#include <iostream>
#include <cstdlib>
#include <string>

void distance_main();
void distance_input( double&, double&, double&, double&,std::string&, std::string&);

int main(){
    int c;
    const char *welcome="~~~Welcome to Joe's C++ Puzzle Solving Program!~~~";

        std::cout<<welcome<<std::endl<<std::endl;
        std::cout<<"Please select an option from the menu below: \n";
        std::cout<<"1) Fibonacci Sequence Generator \n";
        std::cout<<"2) Prime Number Factorization \n";
        std::cout<<"3) Next Prime Number Generator \n";
        std::cout<<"4) Palindrome Analyzer \n";
        std::cout<<"5) Payment Change Calculator \n";
        std::cout<<"6) Binary/Decimal Conversion Calculator \n";
        std::cout<<"7) Reverse a String \n";
        std::cout<<"8) Geographic Distance Calculator \n";
        std::cout<<"9) Sudoku Puzzle Solver \n";
        std::cout<<"10) Prefix/Infix/Postfix Converter + Calculator";
        distance_main();
}



void distance_main(){
    std::string city1, city2;
    double lat1,long1,lat2,long2;
    std::cout<<std::endl<<"~~~Welcome to the Geographic Distance Calculator!~~~"<<std::endl<<std::endl;
    distance_input(lat1,long1,lat2,long2, city1, city2);
    std::cout<<"The coordinates of "<<city1<<" are: "<<lat1<<", "<<long1;
    std::cout<<"The coordinates of "<<city2<<" are: "<<lat2<<", "<<long2;
}

void distance_input(double &lat1, double &long1, double &lat2, double &long2,std::string &city1, std::string &city2){
    std::cout<<"Please enter the name of your first location (City, Country): ";
    std::getline(std::cin,city1);
    std::cout<<"Please enter the name of your second location (City, Country): ";
    std::getline(std::cin,city2);
    std::cout<<"Please enter the latitude of "<<city1<<" (up to 15 decimal places): ";
    std::cin>>lat1;
    std::cout<<"Please enter the longitude of "<<city1<<" (up to 15 decimal places): ";
    std::cin>>long1;
    std::cout<<"Please enter the latitude of "<<city2<<" (up to 15 decimal places): ";
    std::cin>>lat2;
    std::cout<<"Please enter the longitude of "<<city2<<" (up to 15 decimal places): ";
    std::cin>>long2;
}
