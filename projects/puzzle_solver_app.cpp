
#include <iostream>
#include <fstream>
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

//###################################
//BEGIN SECTION OF FIBONACCI SEQUENCE CODE
//###################################

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

//######################################
//BEGIN SECTION OF REVERSE STRING CODE
//#####################################

//A function that derives the reverse of a user-provided string by printing it backwards
void ReverseString(std::string str){

    for(int i=str.length()-1; i>=0; i--){
        std::cout<<str[i];
    }
}

//Presents welcome message and grabs user input for string
void ReverseMain(){

    std::string str;

    std::cout<<"~~~Welcome to the String Reversal Machine!~~~"<<std::endl<<std::endl;
    std::cout<<"For any phrase you provide, I can return it to you in reverse order!"<<std::endl;
    std::cout<<"Please type the phrase you'd like to reverse: ";
    std::cin.ignore();
    std::getline(std::cin,str);

    std::cout<<std::endl<<"Your original phrase was: "<<str<<std::endl;
    std::cout<<"Your reversed phrase is: ";ReverseString(str);

}


//###################################
//BEGIN SECTION OF DISTANCE CALCULATOR CODE
//###################################

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

//###################################
//BEGIN SECTION OF SUDOKU SOLVER CODE
//###################################

//Declaration for function that will search the puzzle for empty cells
bool FindEmptyCells(int grid[9][9], int &row, int &col);

//Declaration for funcion that will verify that attempted number satisfies puzzle rules
bool NumberWorks(int grid[9][9], int row, int col, int guess);

//Function that takes user-input for puzzle and uses backtracking and recursion to solve
bool SudokuSolver(int grid[9][9]){
        int row, col;

        //Puzzle if solved when all boxes are filled
        if(FindEmptyCells(grid,row,col) == false){
            return true;
        }

        //Looping through the possible solutions to each cell in the puzzle
        for(int i=1; i<=9; i++){
            //Testing number to see if it conflicts with row/col/cell
            if(NumberWorks(grid, row, col, i) == true){
                //If compatible, assign to cell
                grid[row][col] = i;

                //Call function recursively; if it passes as true, puzzle solved!
                if(SudokuSolver(grid) == true){
                    return true;
                }

                //If a conflict emerges, reset cell to zero and try next
                grid[row][col] = 0;
            }
        }
        //If all options are exhausted for cell, trigger backtracking
        return false;
}

/*This function searches the puzzle for empty cells. If an empty cell is encountered, the row
and column that have been called by reference are set to this cell and the function returns true
If no empty cells are found, the function is returned false and the puzzle is solved!*/

bool FindEmptyCells(int grid[9][9], int &row, int &col){
    for(row = 0; row<9; row++){
        for(col = 0; col<9; col++){
            if(grid[row][col] == 0){
                return true;
            }
        }
    }
    //If no empty cells are encountered:
    return false;
}

//Function determines if guess exists in current row
bool InRow(int grid[9][9], int row, int guess){
    for(int col=0; col<9; col++){
        if(grid[row][col] == guess){
            return true;
        }
    }
    //If number is not in current row:
    return false;
}

//Function determines if guess exists in current column
bool InCol(int grid[9][9], int col, int guess){
    for(int row=0; row<9; row++){
        if(grid[row][col] == guess){
            return true;
        }
    }
    //If number is not in current column:
    return false;
}

//Function determines if guess exists in current 3x3 box
bool InBox(int grid[9][9], int StartRow, int StartCol, int guess){
    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            if(grid[row+StartRow][col+StartCol] == guess){
                return true;
            }
        }
    }
    //If number is not in current 3x3 box:
    return false;
}

//Function calls all three previous tests to determine if guess fulfills puzzle rules
bool NumberWorks(int grid[9][9], int row, int col, int guess){
    return !InRow(grid, row, guess) &&
            !InCol(grid, col, guess) &&
            !InBox(grid, row - row % 3, col- col % 3, guess) &&
            grid[row][col] == 0;
}

//Function that prints the Sudoku grid
void SudokuPrint(int grid[9][9]){
    for(int row=0; row<9; row++){
        for(int col=0; col<9; col++){
            std::cout<<grid[row][col]<<" ";
        }
        std::cout<<std::endl;
    }
}

void sudoku_main(){
    //Driver function for sudoku solver app

    std::cout<<std::endl<<"~~~Welcome to the Sudoku Puzzle Solver!~~~"<<std::endl;
    std::cout<<"To solve your puzzle, enter the existing cell values one at a time."<<std::endl;
    std::cout<<"Move from left to right across rows and start in the upper left hand corner."<<std::endl;
    std::cout<<"For empty cells, enter 0."<<std::endl;

    int grid[9][9];
    //Loop that allows user to input their unsolved puzzle and review input before solving
    while(true){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                std::cin>>grid[i][j];
            }
        }
        //Printing user input for review
        std::cout<<std::endl<<"Your input was: "<<std::endl;
        SudokuPrint(grid);
        char correct = '\0';
        std::cout<<std::endl<<"Was your input correct?(Y/N): ";
        std::cin>>correct;

        //Makes choice variable case agnostic
        correct = toupper(correct);
        if(correct == 'Y'){
            break;
        }
        if(correct == 'N'){
            continue;
        }
        else{
            std::cout<<"Invalid input. Returning to main...";
            return;
        }
    }

    /*A sample puzzle if necessary
    int example[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    */

    if (SudokuSolver(grid) == true){
        std::cout<<"Your solved puzzle is: "<<std::endl;
        SudokuPrint(grid);
    }
    else{
        std::cout<<"Sorry, but your puzzle couldn't be solved. Please check input."<<std::endl;
    }

}

void prime_factorization(){};
void next_prime(){};
void palindrome(){};
void change_calculator(){};
void binary_calculator(){};
void reverse_string(){};
void sudoku(){};
void infix(){};

int main(){
    //Main menu that allows user to choose puzzle/problem they'd like to solve
    int c=0;
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
            ReverseMain();
            break;
        case 8:
            distance_main();
            break;
        case 9:
            sudoku_main();
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
    return 0;
}
