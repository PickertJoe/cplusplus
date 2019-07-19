
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <iomanip>
#include <stack>
#include <deque>
#include <algorithm>


//###################################
//BEGIN SECTION OF FIBONACCI SEQUENCE CODE
//###################################

//Collects user input for iterations of Fibonacci sequence
void FibInput(int &iterations){
    //Controls for invalid input
    bool valid = true;
    while(valid){
        std::cout<<"Please enter the number of iterations of the sequence you'd like to generate (<100): ";
        std::cin>>iterations;
        if( iterations > 0 && iterations <101){
            valid = false;
            return;
        }
        else if ( iterations > 100 ){
            std::cout<<"Program cannot handle that many iterations. Please enter a number between 1 and 100."<<std::endl;
        }
        else{
            std::cout<<"Invalid input. Please enter a number between 1 and 100."<<std::endl;
        }
    }
}


//Takes the user-provided number of iterations and produces a fibonacci sequence dynamically
//Fibonacci driver function
void Fibonacci(){
    //Welcome message and attaining number of iterations
    int iterations;

    std::cout<<"~~~Welcome to the Fibonacci Sequence Generator!~~~"<<std::endl<<std::endl;

    FibInput(iterations);

    //Initializing array to hold sequence
    int fib[iterations + 1];

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

//#########################################
//BEGIN SECTION OF PRIME FACTORIZATION CODE
//#########################################

//Function to grab and control for user input
void PrimeInput(int &number){
    bool valid = true;
    while(valid){
        std::cout<<"Please enter a positive integer of your choosing: ";
        std::cin>>number;
        if( number < 0){
            std::cout<<"Input error. Number entered was less than 0. Please try again."<<std::endl;
        }
        else if ( std::cin.fail() ){
            std::cout<<"Input error. Value entered was not a number. Please try again."<<std::endl;
        }
        else{
            valid = false;
            return;
        }
    }
}

//Driver function for prime factorization
void PrimeFact(){
    std::cout<<std::endl<<"~~~Welcome to the C++ Prime Number Factorization Calculator!~~~"<<std::endl<<std::endl;
    std::cout<<"For any number you input, I can return of its prime factors."<<std::endl;
    int number;

    //Calls to user input function
    PrimeInput(number);

    std::cout<<"The prime factors of "<<number<<" are: "<<std::endl;

    //Reduce a composite number by dividing by 2 until it becomes odd
    while (number % 2 == 0){
        std::cout<<2<< " ";
        number = number/2;
    }

    //Once the number becomes odd, begin testing for prime factors
    for (int i =3; i<= sqrt(number); i=i+2){
        while (number % i==0){
            std::cout<<i<<" ";
            number = number/i;
        }
    }

    if(number>2){
        std::cout<<number<<" ";
    }
    return;
}

//#########################################
//BEGIN SECTION OF NEXT PRIME NUMBER  CODE
//#########################################

//Tests whether a number is prime
bool IsPrime(int i){
    for(int j=2; j<i; j++){
        if ( i % j == 0){
            return false;
        }
    }
    return true;
}


//Tests whether prime number is already in array
bool InArray(int primes[10000], int counter, int number){
    for(int k=0; k<=counter; k++){
        if (number == primes[k]){
            return false;
        }
    }
    return true;
}


//Function that generates the next prime number in sequence until the user wishes to stop
void NextPrimeNumber(){
    std::cout<<std::endl<<std::endl<<"~~~Welcome to the Next Prime Number Generator!~~~"<<std::endl<<std::endl;
    std::cout<<"I can generate new prime numbers for as long as you'd like."<<std::endl;

    int maxsize = 10000;
    int maxiterations = 1000 * maxsize;
    int primes[10000];
    bool valid = true;
    int counter = 2;

    //Loop to continually generate new prime numbers until user wishes to stop
    while(valid){
        //Prints out number zero if array is empty
        if (!primes[0]){
            std::cout<<1;
            primes[0] = 1;
        }

        //Prints out number 1
        else if (!primes[1]){
            std::cout<<2;
            primes[1]=2;
        }

        else{
            for (int i=3; i<maxiterations; i+=2){
                //Calls function to test if number i is prime
                if (!IsPrime(i)){
                    continue;
                }

                //If i is prime, calls function to test if already in array
                if (InArray(primes, counter, i)){
                    std::cout<<i;
                    primes[counter] = i;
                    counter ++;
                    break;
                }
            }
        }

        //Allows user to decide if they'd like to continue
        char c = '\0';
        std::cout<<std::endl<<std::endl<<"Would you like to continue?(Y/N): ";
        std::cin>>c;
        c= std::toupper(c);
        if (c=='Y'){
            continue;
        }
        else if (c=='N'){
            break;
        }
        else{
            std::cout<<"Invalid input, generating next number...";
        }

    }

}

//##################################
//BEGIN SECTION OF PALINDROME  CODE
//##################################

//Function to parse user input to remove spaces and neutralize capitalization
std::string PalindromeParse(std::string str){


    //Reads through input string, omitting spaces and adding characters to return string

    str.erase(remove(str.begin(), str.end(), ' '), str.end());


    //Converts string to all caps to make analyzer case-agnostic
    for (int i=0; i<=str.length(); i++){
        str[i] = toupper(str[i]);
    }
    return str;
}

//Function to asses a palindrome using the deque data structure
bool IsPalindrome(std::string clean){

    //Initializing assessment deque
    std::deque<char> holder;

    //Adding each character in the string to the deque
    for(int i=0; i<clean.length(); i++){
        holder.push_back(clean[i]);
    }

    //Popping elements of front and back end of deque and testing if the same
    while (holder.size() > 1){

        if (holder.front() != holder.back()){
            return false;
        }
        else{
            holder.pop_front();
            holder.pop_back();
        }
    }
    return true;
}


//Main driver function for palindrome analyzer
void PalindromeMain(){

    std::string str;
    std::cout<<std::endl<<"~~~Welcome to the C++ Palindrome Analyzer!~~~"<<std::endl<<std::endl;
    std::cout<<"Please enter the string you'd like to analyze: ";
    std::cin.ignore();
    std::getline(std::cin,str);

    //Calls function to clean input string (remove spaces, capitalize everything)
    std::string clean = PalindromeParse(str);

    //Analyzes whether the user's string is a palindrome
    if (IsPalindrome(clean)){
        std::cout<<std::endl<<"Your string '"<<str<<"' is a palindrome!";
    }
    else{
        std::cout<<std::endl<<"Your string '"<<str<<"' is not a palindrome!";
    }

}

//#########################################
//BEGIN SECTION OF CHANGE CALCULATOR  CODE
//#########################################


//Function to accept and control for user input
void ChangeInput(float &price, float &payment){

        //Loop to ensure proper input for price
        while(true){
            std::cout<<"Please enter the price of your purchase: ";
            std::cin>>price;
            //Catching non-numeric entries
            if (!std::cin ){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<<"Invalid input. Please enter a valid price."<<std::endl;
                continue;
            }
            else{
                break;
            }
        }

        //Loop to ensure proper input for payment
        while(true){
            std::cout<<"Please enter the payment tendered: ";
            std::cin>>payment;

            //Catching non-numeric entries
            if (!std::cin){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<<"Invalid input. Please enter a valid payment."<<std::endl;
                continue;
            }
            else if (payment < price){
                std::cout<<"You didn't pay the full price!"<<std::endl;
                continue;
            }
            else{
                break;
            }
        }

}

//Function to round input if necessary and calculate difference between price and payment
float DifferenceCalculator(float price, float payment){

    //Using typecast to reduce input values to 2 decimal places
    price = (int)(price * 100 + .5);
    price = (float)price/100;
    payment = (int)(payment * 100 + .5);
    payment = (float)payment/100;

    float difference = payment - price;

    return difference;
}

//Function to print results of change calculation
void PrintChange(float difference, int change_holder[9]){

    //Declaring array of denomincation names
    char names[9][15] = {"Hundreds", "Twenties", "Tens", "Fives", "Ones", "Quarters", "Dimes", "Nickels", "Pennies"};
    std::cout<<std::endl<<"To make change of "<<difference<<", you will need: "<<std::endl;
    for(int i=0; i<9; i++){
        std::cout<<change_holder[i]<<" "<<names[i]<<std::endl;
    }

}

//Calculates the least amount of change needed to make difference
//Returns an array with the numeric value of each denomination
void ChangeCalculator(float difference){

    //Duplicating original difference to pass to print function
    float original_difference = difference;
    //Declaring an array to hold values of each demonination of change
    float denom_values[9] = {100,20,10,5,1,.25,.1,.05,.01};
    static int change_holder[9];

    for(int i=0; i<9; i++){
        change_holder[i] = difference / denom_values[i];
        difference = difference - (change_holder[i] * denom_values[i] );
    }

    PrintChange(original_difference, change_holder);
}


//Main driver function for change calculator
void ChangeMain(){

    //Declaring variables
    float price;
    float payment;

    std::cout<<std::endl<<"~~~Welcome to the C++ Change Calculator!~~~"<<std::endl<<std::endl;
    std::cout<<"For a given price and payment, I can return the correct amount of change owed."<<std::endl;

    ChangeInput(price, payment);
    float difference = DifferenceCalculator(price, payment);
    ChangeCalculator(difference);

}

//#########################################
//BEGIN SECTION OF BINARY CALCULATOR  CODE
//#########################################



//######################################
//BEGIN SECTION OF REVERSE STRING CODE
//######################################

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

//Ensures that only numeric values are accepted for coordinates
void CoordinateControl(double &lat1, double &long1, std::string city){
    while(true){
            std::cout<<"Please enter the latitude of "<<city<<" (up to 15 decimal places): ";
            std::cin>>lat1;

            //Catching non-numeric entries
            if (!std::cin ){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout<<"Invalid input. Please enter a valid coordinate."<<std::endl;
                continue;
            }
            else{
                break;
            }
        }
    while(true){
        std::cout<<"Please enter the longitude of "<<city<<" (up to 15 decimal places): ";
        std::cin>>long1;

        //Catching non-numeric entries
        if (!std::cin ){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Invalid input. Please enter a valid coordinate."<<std::endl;
            continue;
        }
        else{
            break;
        }
    }
}


//Collects user input for names and coordinates of locations
void DistanceInput(double &lat1, double &long1, double &lat2, double &long2,std::string &city1, std::string &city2){
    //Grabbing entry information for first city
    std::cout<<"Please enter the name of your first location (City, Country): ";
    std::cin.ignore();
    std::getline(std::cin,city1);
    CoordinateControl(lat1, long1, city1);

    //Grabbing entry information for second city
    std::cout<<"Please enter the name of your second location (City, Country): ";
    std::cin.ignore();
    std::getline(std::cin,city2);
    CoordinateControl(lat2, long2, city2);
}

//Converts provided coordinates from degrees to radians
void toRadians(double &lat1, double &long1, double &lat2, double &long2){

    double degree = (M_PI) / 180;
    lat1 = (lat1 * degree);
    lat2 = (lat2 * degree);
    long1 = (long1 * degree);
    long2 = (long2 * degree);
}

//Solves for the distance between two points on Earth's surface using the Haversine formula
//This equation solves in terms of kilometers by default
//Units are converted to Imperial if desired by user's request
double distance_calc(double lat1, double long1, double lat2, double long2){

    double diff_long = long2 - long1;
    double diff_lat = lat2 - lat1;

    double distance = pow(sin(diff_lat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(diff_long / 2 ), 2);
    distance = 2 * asin(sqrt(distance));

    //Using kilometers for radius of the Earth R = 6371
    double R = 6371;
    distance = R * distance;

    return distance;
}

//Main driver function for the coordinate distance calculator
void DistanceMain(){
    //Initializes appropriate variables and orchestrates distance calculation functions
    std::string city1, city2;
    double lat1,long1,lat2,long2, distance;

    //Conversion factor from km to mi
    double conversion = 0.62137119;

    char unit_choice = '\0';
    bool valid = true;

    std::cout<<std::endl<<"~~~Welcome to the Geographic Distance Calculator!~~~"<<std::endl<<std::endl;
    DistanceInput(lat1,long1,lat2,long2, city1, city2);
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

//Main driver function for the Sudoku solver
void SudokuMain(){
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

//#####################################
//BEGIN SECTION OF INFIX CONVERSION CODE
//#####################################

//Fuction to test whether the read-in character is an operator or operand
bool Operator(char c){
    return(!std::isalpha(c) && !std::isdigit(c));
}

//Function to establish order of operations based on operator type
int SetPriority(char c){
    if (c=='-' || c=='+'){
        return 1;
    }
    else if (c=='*' || c=='/'){
        return 2;
    }
    else if (c=='^'){
        return 3;
    }
    return 0;
}


//Function that converts an infix to postfix using stack data structure
std::string PostfixConvert(std::string infix){

    //Surrounding expression with parantheses
    infix = '(' + infix + ')';
    int length = infix.size();
    std::stack<char> infix_stack;
    std::string result;

    //Loop to scan each character of the expression and manipulate the stack
    for (int i=0; i<length; i++){
        //Adding operands to output
        if (std::isalpha(infix[i]) || std::isdigit(infix[i])){
            result += infix[i];
        }

        //If '(' is encountered, push to stack
        else if (infix[i] == '('){
            infix_stack.push('(');
        }

        //If a ')' is enountered, pop the stack until '(' is found
        else if (infix[i] == ')'){

            while (infix_stack.top() != '('){
                    result += infix_stack.top();
                    infix_stack.pop();
            }
            //Pop '(' from the stack after looping
            infix_stack.pop();
        }

        //If operator is encountered, estabish primacy
        else{
            if (Operator(infix_stack.top())){
                while (SetPriority(infix[i]) <= SetPriority(infix_stack.top())){
                    result += infix_stack.top();
                    infix_stack.pop();
                }
                infix_stack.push(infix[i]);
            }
        }
    }
    return result;
}

//Function that converts an infix expression to prefix by reversing its postfix equivalent
std::string PrefixConvert(std::string infix){
    int length = infix.size();

    std::reverse(infix.begin(), infix.end());

    //Reverse the placements of opposite-facing parantheses
    for( int i=0; i<length; i++){
        if (infix[i] == '('){
            infix[i] = ')';
            i++;
            }
        else if (infix[i] == ')'){
            infix[i] = '(';
            i++;
        }
    }

    //Sending string to postfix converter to prepare for reversal
    std::string result = PostfixConvert(infix);

    //Reverse the converted string
    std::reverse(result.begin(), result.end());

    return result;
}


//Main driver function for Infix converter
void InfixMain(){

    std::string infix;
    int choice;

    std::cout<<std::endl<<"~~~Welcome to the Infix Expression Evaluator!~~~"<<std::endl<<std::endl;
    std::cout<<"I can convert any valid infix expression to its prefix or postfix equivalent."<<std::endl;
    std::cout<<"Letters or numbers may be used."<<std::endl;
    std::cout<<"Please enter your infix expression with no spaces: ";

    std::cin.ignore();
    std::getline(std::cin, infix);

    std::cout<<"Would you like to convert your expression to prefix or postfix notation?"<<std::endl;
    std::cout<<"1) Prefix"<<std::endl<<"2) Postfix :";
    std::cin>>choice;

    if(choice == 1){
        std::cout<<"Your original expression was: "<<infix<<std::endl;
        std::cout<<"It's prefix equivalent is: "<<PrefixConvert(infix)<<std::endl;
        return;
    }
    if(choice == 2){
        std::cout<<"Your original expression was: "<<infix<<std::endl;
        std::cout<<"It's postfix equivalent is: "<<PostfixConvert(infix)<<std::endl;
        return;
    }
    else{
        std::cout<<"Invalid input. Returning to main...";
    }
}

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
            Fibonacci();
            break;
        case 2:
            PrimeFact();
            break;
        case 3:
            NextPrimeNumber();
            break;
        case 4:
            PalindromeMain();
            break;
        case 5:
            ChangeMain();
            break;
        case 6:
//            BinaryMain();
            break;
        case 7:
            ReverseMain();
            break;
        case 8:
            DistanceMain();
            break;
        case 9:
            SudokuMain();
            break;
        case 10:
            InfixMain();
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
