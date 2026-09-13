/* 
 * File:   soft_drink.cpp
 * Author: Kevin Santiago
 * Created on October 18, 2026
 * Purpose:  Simulate a soft drink machine using an array of structures and functions
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const int SIZE = 5;

struct drink
{
    string name;
    int cost, num;
};

//Function Prototypes
void show(drink[]);
int look(drink[], string);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    drink mach[SIZE] = {{"Cola", 75, 20}, {"Root Beer", 75, 20}, {"Lemon-Lime", 75, 20},
                        {"Grape Soda", 80, 20}, {"Cream Soda", 80, 20}};
    string pick;
    int mon, earn = 0, at;
    bool go = true;

    //Process or map Inputs to Outputs
    while (go == true)
    {
        show(mach);
        getline(cin, pick);
        at = look(mach, pick);

        if (pick == "Quit")
        {
            go = false;
        }
        if (at >= 0 && mach[at].num == 0)
        {
            cout << "Sold out" << endl;
        }
        if (at >= 0 && mach[at].num > 0)
        {
            cin >> mon;
            while (mon < 0 || mon > 100)
            {
                cout << "Enter an amount between 0 and 100" << endl;
                cin >> mon;
            }
            cin.ignore();

            if (mon < mach[at].cost)
            {
                cout << "Not enough money" << endl;
            }
            if (mon >= mach[at].cost)
            {
                //I show the change, take one drink out and keep the money
                cout << mon - mach[at].cost << endl;
                mach[at].num--;
                earn = earn + mach[at].cost;
            }
        }
    }

    //Display Outputs
    cout << earn << endl;

    //Exit stage right!
    return 0;
}

//Shows the list of drinks and the quit option
void show(drink d[])
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << left << setw(11) << d[i].name << d[i].cost << "  " << d[i].num << endl;
    }
    cout << "Quit" << endl;
}

//Returns the position of the drink, or -1 if it does not exist
int look(drink d[], string s)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (d[i].name == s)
        {
            return i;
        }
    }
    return -1;
}