/* 
 * File:   decrypt.cpp
 * Author: Kevin Santiago
 * Created on October 28, 2026
 * Purpose:  Decrypt a four-digit number that was encrypted, flags the digits 8 and 9
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
    cout << "Enter an encrypted four-digit number:" << endl;
    cin >> number;

    //Process or map Inputs to Outputs
    if (!valid(number, d1, d2, d3, d4))
    {
        cout << "Error: the digits 8 and 9 can not appear in an encrypted number" << endl;
        return 0;
    }
    //Undo the swaps first, the last step of the encryption is the first to undo
    temp = d1;
    d1 = d3;
    d3 = temp;
    temp = d2;
    d2 = d4;
    d4 = temp;
    //Undo the shift, subtract 3 modulus 8
    d1 = (d1 + BASE - SHIFT) % BASE;
    d2 = (d2 + BASE - SHIFT) % BASE;
    d3 = (d3 + BASE - SHIFT) % BASE;
    d4 = (d4 + BASE - SHIFT) % BASE;

    //Display Outputs
    cout << "Decrypted number:" << d1 << d2 << d3 << d4 << endl;

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