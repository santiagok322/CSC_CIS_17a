/* 
 * File:   encrypt.cpp
 * Author: Kevin Santiago
 * Created on October 28, 2026
 * Purpose:  Encrypt a four-digit number that only uses the digits 0 to 7
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const int SHIFT = 3;
const int BASE = 8;

//Function Prototypes
bool valid(int, int &, int &, int &, int &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    int number;
    int d1, d2, d3, d4;
    int temp;

    //Initialize Variables
    cout << "Enter a four-digit number using only the digits 0 to 7:" << endl;
    cin >> number;

    //Process or map Inputs to Outputs
    if (!valid(number, d1, d2, d3, d4))
    {
        cout << "Error: the number must have four digits and only 0 to 7 are allowed" << endl;
        return 0;
    }
    //Replace each digit by the digit plus 3 modulus 8
    d1 = (d1 + SHIFT) % BASE;
    d2 = (d2 + SHIFT) % BASE;
    d3 = (d3 + SHIFT) % BASE;
    d4 = (d4 + SHIFT) % BASE;
    //Swap the first digit with the third
    temp = d1;
    d1 = d3;
    d3 = temp;
    //Swap the second digit with the fourth
    temp = d2;
    d2 = d4;
    d4 = temp;

    //Display Outputs
    cout << "Encrypted number:" << d1 << d2 << d3 << d4 << endl;

    //Exit stage right!
    return 0;
}

//Splits the number into four digits, returns false if it is not valid
bool valid(int number, int &d1, int &d2, int &d3, int &d4)
{
    if (!cin || number < 0 || number > 9999)
    {
        return false;
    }
    d1 = number / 1000;
    d2 = number / 100 % 10;
    d3 = number / 10 % 10;
    d4 = number % 10;
    if (d1 > 7 || d2 > 7 || d3 > 7 || d4 > 7)
    {
        return false;
    }
    return true;
}