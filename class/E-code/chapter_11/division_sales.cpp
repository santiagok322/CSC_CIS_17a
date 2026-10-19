/* 
 * File:   division_sales.cpp
 * Author: Kevin Santiago
 * Created on October 18, 2026
 * Purpose:  Store and display the sales of four company divisions using a structure and functions
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

struct Div
{
    string name;
    double q1, q2, q3, q4;
    double total, avg;
};

//Function Prototypes
void ask(Div &, string);
bool bad(Div);
void calc(Div &);
void show(Div);
bool run(Div &, string);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Div north, west, east, south;

    //Initialize Variables
    cout << fixed << setprecision(2);

    //Process or map Inputs to Outputs and Display Outputs
    //If one division has a negative sale the program stops
    if (!run(north, "North") || !run(west, "West") || !run(east, "East") || !run(south, "South"))
    {
        cout << "You can not enter a negative sale!" << endl;
            return 0;
    }
    //Exit stage right!
    return 0;
}

//Does everything for one division, returns false if a sale is negative
bool run(Div &d, string n)
{
    ask(d, n);
    if (bad(d))
    {
        return false;
    }
    calc(d);
    show(d);
    return true;
}

//Asks the user for the sales of one division
void ask(Div &d, string n)
{
    d.name = n;

    cout << d.name << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> d.q1;
    cout << "Enter second-quarter sales:" << endl;
    cin >> d.q2;
    cout << "Enter third-quarter sales:" << endl;
    cin >> d.q3;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> d.q4;
}

//Returns true if any sale of the division is negative
bool bad(Div d)
{
    if (d.q1 < 0 || d.q2 < 0 || d.q3 < 0 || d.q4 < 0)
    {
        return true;
    }
    return false;
}

//Calculates the total and the average of one division
void calc(Div &d)
{
    d.total = d.q1 + d.q2 + d.q3 + d.q4;
    d.avg = d.total / 4;
}

//Shows the total and the average of one division
void show(Div d)
{
    cout << "Total Annual sales:$" << d.total << endl;
    cout << "Average Quarterly Sales:$" << d.avg;
    if (d.name != "South")
    {
        cout << endl;
    }
}