/* 
 * File:   union_pay.cpp
 * Author: Kevin Santiago
 * Created on October 18, 2026
 * Purpose:  Calculate the gross pay of an employee using a union
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

union psrc
{
    int hours;      //Hours worked
    float sales;    //Amount of sales
};

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    psrc emp;
    char type;
    float rate, gross;

    //Initialize Variables
    cout << fixed << showpoint << setprecision(2);
    cout << "This program calculates either hourly wages or" << endl;
    cout << "sales commission." << endl;

    //Process or map Inputs to Outputs
    cout << "Enter H for hourly wages or C for commission: ";
    cin >> type;

    //Hourly paid employee
    if (type == 'H' || type == 'h')
    {
        cout << "What is the hourly pay rate? ";
        cin >> rate;
        cout << "How many hours were worked? ";
        cin >> emp.hours;

        gross = emp.hours * rate;
        cout << "Gross pay: $" << gross << endl;
    }

    //Commission paid employee
    if (type == 'C' || type == 'c')
    {
        cout << "What are the total sales for this employee? ";
        cin >> emp.sales;

        gross = emp.sales * 0.10;
        cout << "Gross pay: $" << gross << endl;
    }

    //Invalid selection
    if (type != 'H' && type != 'h' && type != 'C' && type != 'c')
    {
        cout << type << " is not a valid selection." << endl;
    }

    //Exit stage right!
    return 0;
}