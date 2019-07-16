
#include <iostream>
#include <cstdlib>
#include <string>


void fibonnaci();
void prime_factorization();
void next_prime();
void palindrome();
void change_calculator();
void binary_calculator();
void reverse_string();
void distance_main();
void distance_input( double&, double&, double&, double&,std::string&, std::string&);
void sudoku();
void infix();

int main(){
    int c;
    const char *welcome="~~~Welcome to Joe's C++ Puzzle Solving Program!~~~";
    do{
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
        std::cout<<"10) Prefix/Infix/Postfix Converter + Calculator \n";
        std::cout<<"11) Exit program \n";
        std::cin>>c;
        switch(c){
        case 1:
            fibonnaci();
            break;
        case 2:
            prime_factorization();
            break;
        case 3:
            next_prime();
            break;
        case 4:
            palindrome();
            break;
        case 5:
            change_calculator();
            break;
        case 6:
            binary_calculator();
            break;
        case 7:
            reverse_string();
            break;
        case 8:
            distance_main();
            break;
        case 9:
            sudoku();
            break;
        case 10:
            infix();
            break;
        default:
            std::cout<<"Invalid input. Please try again."<<std::endl;

        }

    }
    while(c!=11);



}



void distance_main(){
    std::string city1, city2;
    double lat1,long1,lat2,long2;
    std::cout<<std::endl<<"~~~Welcome to the Geographic Distance Calculator!~~~"<<std::endl<<std::endl;
    distance_input(lat1,long1,lat2,long2, city1, city2);
    std::cout<<"The coordinates of "<<city1<<" are: ("<<lat1<<", "<<long1<<")\n";
    std::cout<<"The coordinates of "<<city2<<" are: ("<<lat2<<", "<<long2<<")\n";
}

void distance_input(double &lat1, double &long1, double &lat2, double &long2,std::string &city1, std::string &city2){
    std::cout<<"Please enter the name of your first location (City, Country): ";
    std::cin.ignore();
    std::getline(std::cin,city1);
    std::cout<<"Please enter the latitude of "<<city1<<" (up to 15 decimal places): ";
    std::cin>>lat1;
    std::cout<<"Please enter the longitude of "<<city1<<" (up to 15 decimal places): ";
    std::cin>>long1;
    std::cout<<"Please enter the name of your second location (City, Country): ";
    std::cin.ignore();
    std::getline(std::cin,city2);
    std::cout<<"Please enter the latitude of "<<city2<<" (up to 15 decimal places): ";
    std::cin>>lat2;
    std::cout<<"Please enter the longitude of "<<city2<<" (up to 15 decimal places): ";
    std::cin>>long2;
}

void fibonnaci(){};
void prime_factorization(){};
void next_prime(){};
void palindrome(){};
void change_calculator(){};
void binary_calculator(){};
void reverse_string(){};
void sudoku(){};
void infix(){};
