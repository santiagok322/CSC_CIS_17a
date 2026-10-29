
/* 
 * File:   sizes.cpp
 * Author: Kevin Santiago
 * Created on October 28, 2026
 * Purpose:  Show the bytes and how many different values fit in each integer data type
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
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
    cout << fixed << setprecision(0);

    //Process or map Inputs to Outputs and Display Outputs
    cout << "Data type   Bytes   Different values" << endl;
    cout << "unsigned char:       " << sizeof(unsigned char) << "       " << pow(2, 8 * sizeof(unsigned char)) << endl;
    cout << "unsigned short:      " << sizeof(unsigned short) << "       " << pow(2, 8 * sizeof(unsigned short)) << endl;
    cout << "unsigned int:        " << sizeof(unsigned int) << "       " << pow(2, 8 * sizeof(unsigned int)) << endl;
    cout << "unsigned long:       " << sizeof(unsigned long) << "       " << pow(2, 8 * sizeof(unsigned long)) << endl;
    cout << "unsigned long long:  " << sizeof(unsigned long long) << "       " << pow(2, 8 * sizeof(unsigned long long)) << endl;
    cout << "float:               " << sizeof(float) << "       " << -pow(2, 8 * sizeof(float)) / 2 << "   to   " << pow(2, 8 * sizeof(float)) / 2 - 1 << endl;
    cout << "double:              " << sizeof(double) << "       " << -pow(2, 8 * sizeof(double)) / 2 << "   to   " << pow(2, 8 * sizeof(double)) / 2 - 1 << endl;
    cout << "long double:         " << sizeof(long double) << "       " << -pow(2, 8 * sizeof(long double)) / 2 << "   to   " << pow(2, 8 * sizeof(long double)) / 2 - 1 << endl;
    cout << "signed char:         " << sizeof(signed char) << "       " << pow(2, 8 * sizeof(signed char) - 1) << endl;
    cout << "signed short:        " << sizeof(signed short) << "       " << pow(2, 8 * sizeof(signed short) - 1) << endl;
    cout << "signed int:          " << sizeof(signed int) << "       " << pow(2, 8 * sizeof(signed int) - 1) << endl;
    cout << "signed long:         " << sizeof(signed long) << "       " << pow(2, 8 * sizeof(signed long) - 1) << endl;
    cout << "signed long long:    " << sizeof(signed long long) << "       " << pow(2, 8 * sizeof(signed long long) - 1) << endl;
    //Exit stage right!

    return 0;
}
