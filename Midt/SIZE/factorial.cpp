
/*
 * File:   factorial.cpp
 * Author: Kevin Santiago
 * Created on October 28, 2026
 * Purpose: Show the largest n for n! that each data type can hold without overflow
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed

    //Declare Variable Data Types and Constants

    //Initialize Variables

    //Process or map Inputs to Outputs and Display Outputs
    //Each value was found by running n! until it overflowed and backing off by 1

    cout << "Largest n for n! without overflow" << endl;
    cout << left;

    cout << setw(22) << "Data Type:"
         << setw(10) << "Largest n"
         << "Factorial Value" << endl;

    cout << setw(22) << "signed char:"
         << setw(10) << 5 << 120 << endl;

    cout << setw(22) << "unsigned char:"
         << setw(10) << 5 << 120 << endl;

    cout << setw(22) << "short:"
         << setw(10) << 7 << 5040 << endl;

    cout << setw(22) << "unsigned short:"
         << setw(10) << 8 << 40320 << endl;

    cout << setw(22) << "int:"
         << setw(10) << 12 << 479001600 << endl;

    cout << setw(22) << "unsigned int:"
         << setw(10) << 12 << 479001600 << endl;

    cout << setw(22) << "long:"
         << setw(10) << 12 << 479001600 << endl;

    cout << setw(22) << "unsigned long:"
         << setw(10) << 12 << 479001600 << endl;

    cout << setw(22) << "long long:"
         << setw(10) << 20 << "2432902008176640000" << endl;

    cout << setw(22) << "unsigned long long:"
         << setw(10) << 20 << "2432902008176640000" << endl;

    cout << setw(22) << "float:"
         << setw(10) << 34 << "2.952328e+38 (approx.)" << endl;

    cout << setw(22) << "double:"
         << setw(10) << 170 << "7.257416e+306 (approx.)" << endl;

    cout << setw(22) << "long double:"
         << setw(10) << 1754 << "Value depends on precision" << endl;

    //Exit stage right!
    return 0;
}
