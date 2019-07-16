
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <iomanip>


void fibonacci_input();
void fibonacci(int n);
void prime_factorization();
void next_prime();
void palindrome();
void change_calculator();
void binary_calculator();
void reverse_string();
void distance_main();
void distance_input( double&, double&, double&, double&,std::string&, std::string&);
double toRadians(double&, double&, double&, double&);
double distance_calc(double, double, double, double);
void sudoku();
void infix();

int main(){
    //Main menu that allows user to choose puzzle/problem they'd like to solve
    int c;
    const char *welcome="~~~Welcome to Joe's C++ Puzzle Solving Program!~~~";
    while(c!=11){
        std::cout<<std::endl<<std::endl<<welcome<<std::endl<<std::endl;
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
            fibonacci_input();
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
        case 11:
            std::cout<<"Closing program..."<<std::endl;
            return 0;
        default:
            std::cout<<"Invalid input. Please try again."<<std::endl;

        }
    }
}

void fibonacci_input(){
    //Collects user input for number of desired iterations
    //Controls for invalid input
    bool valid = true;
    int iterations;
    std::cout<<"~~~Welcome to the Fibonacci Sequence Generator!~~~"<<std::endl<<std::endl;
    while(valid){
        std::cout<<"Please enter the number of iterations of the sequence you'd like to generate (<100): ";
        std::cin>>iterations;
        if( iterations > 0 && iterations <101){
            valid = false;
        }
        if ( iterations > 100 ){
            std::cout<<"Program cannot handle that many iterations. Please enter a number between 1 and 100."<<std::endl;
        }
        else{
            std::cout<<"Invalid input. Please enter a number between 1 and 100."<<std::endl;
        }
    }
    fibonacci(iterations);
}

void fibonacci(int iterations){
    //Takes the user-provided number of iterations and produces a fibonacci sequence dynamically
    int fib[iterations + 1];
    int counter;

    //Storing first and second numbers in the sequence by default
    fib[0] = 0;
    fib[1] = 1;

    for(int i=2; i<=iterations; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    std::cout<<"The Fibonacci Sequence for "<<iterations<<" iterations is:"<<std::endl<<"[";
    for(int i=0; i<=iterations; i++){
        if(i==0){
            std::cout<<fib[i];
        }
        else{
            std::cout<<", "<<fib[i];
        }
    }
    std::cout<<"]";
}


void distance_main(){
    //Initializes appropriate variables and orchestrates distance calculation functions
    std::string city1, city2;
    double lat1,long1,lat2,long2, distance;

    //Conversion factor from km to mi
    double conversion = 0.62137119;

    char unit_choice = '\0';
    bool valid = true;

    std::cout<<std::endl<<"~~~Welcome to the Geographic Distance Calculator!~~~"<<std::endl<<std::endl;
    distance_input(lat1,long1,lat2,long2, city1, city2);
    std::cout<<"The coordinates of "<<city1<<" are: ("<<lat1<<", "<<long1<<")\n";
    std::cout<<"The coordinates of "<<city2<<" are: ("<<lat2<<", "<<long2<<")\n";

    //Setting decimal precision for final distance report
    std::cout << std::fixed;
    std::cout << std::setprecision(3);

    //Converts coordinates from degrees into radians
    toRadians(lat1,long1,lat2,long2);
    distance = distance_calc(lat1,long1,lat2,long2);

    while(valid){
        //Loop to catch bad input
        std::cout<<std::endl<<"Select a unit standard for your answer: "<<std::endl<<"a) Imperial "<<std::endl<<"b) Metric "<<std::endl;
        std::cin>>unit_choice;

        //makes choice variable case-agnostic
        unit_choice = toupper(unit_choice);
        if( unit_choice == 'A'){
            distance = distance * conversion;
            std::cout<<std::endl<<"The distance between "<<city1<<" and "<<city2<<" is: "<<distance<<" miles."<<std::endl;
            valid = false;
        }
        if( unit_choice == 'B'){
            std::cout<<std::endl<<"The distance between "<<city1<<" and "<<city2<<" is: "<<distance<<" kilometers."<<std::endl;
            valid = false;
        }
        else{
            std::cout<<"Invalid input. Please select one of the unit options.";
        }
    }
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

double toRadians(double &lat1, double &long1, double &lat2, double &long2){
    //Converts the coordinates from degree to radians
    double degree = (M_PI) / 180;
    lat1 = (lat1 * degree);
    lat2 = (lat2 * degree);
    long1 = (long1 * degree);
    long2 = (long2 * degree);
}

double distance_calc(double lat1, double long1, double lat2, double long2){
    //Solves for the distance between two points on Earth's surface using the Haversine formula
    //This equation solves in terms of kilometers by default
    //Units are converted to Imperial if desired by user's request

    double diff_long = long2 - long1;
    double diff_lat = lat2 - lat1;

    double distance = pow(sin(diff_lat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(diff_long / 2 ), 2);
    distance = 2 * asin(sqrt(distance));

    //Using kilometers for radius of the Earth R = 6371
    double R = 6371;
    distance = R * distance;

    return distance;
}

void prime_factorization(){};
void next_prime(){};
void palindrome(){};
void change_calculator(){};
void binary_calculator(){};
void reverse_string(){};
void sudoku(){};
void infix(){};
