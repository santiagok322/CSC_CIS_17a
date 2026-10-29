/* 
 * File:   paychecks.cpp
 * Author: Kevin Santiago
 * Created on October 27, 2026
 * Purpose:  Find the gross pay of employees with a dynamic array of structures and print paychecks
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const float STRAIGHT = 40;
const float DOUBLE = 50;
const string COMPANY = "ACME Widgets, Inc.";
const string ADDRESS = "123 Main Street, Riverside, CA 92501";
const string ONES[] = {"zero", "one", "two", "three", "four", "five", "six",
    "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",
    "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const string TENS[] = {"", "", "twenty", "thirty", "forty", "fifty",
    "sixty", "seventy", "eighty", "ninety"};

struct Employee
{
    string name;
    float hours;
    float rate;
    float grossPay;
};

//Function Prototypes
bool ask(Employee &);
float calc(float, float);
string hundreds(int);
string words(long);
void check(const Employee &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Employee *staff;
    int numEmployees;
    int done;
    bool valid = true;

    //Initialize Variables
    cout << fixed << setprecision(2);

    //Process or map Inputs to Outputs and Display Outputs
    //The process starts over until hours or rate are not valid
    while (valid)
    {
        cout << "How many employees will you enter (0 to quit)?" << endl;
        cin >> numEmployees;
        if (!cin || numEmployees <= 0)
        {
            break;
        }
        staff = new Employee[numEmployees];
        done = 0;
        while (done < numEmployees && valid)
        {
            valid = ask(staff[done]);
            if (valid)
            {
                staff[done].grossPay = calc(staff[done].hours, staff[done].rate);
                done++;
            }
        }
        for (int i = 0; i < done; i++)
        {
            check(staff[i]);
        }
        delete [] staff;
    }

    //Exit stage right!
    return 0;
}

//Asks for one employee, returns false if hours or rate are negative
bool ask(Employee &emp)
{
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Enter employee name:" << endl;
    getline(cin, emp.name);
    cout << "Enter hours worked:" << endl;
    cin >> emp.hours;
    cout << "Enter rate of pay:$" << endl;
    cin >> emp.rate;
    if (!cin || emp.hours < 0 || emp.rate < 0)
    {
        cout << "Invalid hours or rate of pay!" << endl;
        return false;
    }
    return true;
}

//Calculates the gross pay, straight time, double time and triple time
float calc(float hours, float rate)
{
    float pay;

    if (hours <= STRAIGHT)
    {
        pay = hours * rate;
    }
    else if (hours <= DOUBLE)
    {
        pay = STRAIGHT * rate + (hours - STRAIGHT) * rate * 2;
    }
    else
    {
        pay = STRAIGHT * rate + (DOUBLE - STRAIGHT) * rate * 2 + (hours - DOUBLE) * rate * 3;
    }
    return pay;
}

//Converts a number from 1 to 999 into English words
string hundreds(int n)
{
    string text = "";

    if (n >= 100)
    {
        text += ONES[n / 100] + " hundred";
        n = n % 100;
        if (n > 0)
        {
            text += " ";
        }
    }
    if (n >= 20)
    {
        text += TENS[n / 10];
        if (n % 10 > 0)
        {
            text += "-" + ONES[n % 10];
        }
    }
    else if (n > 0)
    {
        text += ONES[n];
    }
    return text;
}

//Converts a number from 0 to 999,999,999 into English words
string words(long n)
{
    string text = "";

    if (n == 0)
    {
        return "zero";
    }
    if (n >= 1000000)
    {
        text += hundreds(n / 1000000) + " million";
        n = n % 1000000;
        if (n > 0)
        {
            text += " ";
        }
    }
    if (n >= 1000)
    {
        text += hundreds(n / 1000) + " thousand";
        n = n % 1000;
        if (n > 0)
        {
            text += " ";
        }
    }
    if (n > 0)
    {
        text += hundreds(n);
    }
    return text;
}

//Prints one employee as a paycheck
void check(const Employee &emp)
{
    long cents = static_cast<long>(emp.grossPay * 100 + 0.5);
    long dollars = cents / 100;
    int change = cents % 100;

    cout << endl;
    cout << "==========================================" << endl;
    cout << COMPANY << endl;
    cout << ADDRESS << endl;
    cout << "------------------------------------------" << endl;
    cout << "Name:" << emp.name << "   Amount:$" << emp.grossPay << endl;
    cout << "Amount:" << words(dollars) << " and " << setfill('0') << setw(2)
         << change << setfill(' ') << "/100 dollars" << endl;
    cout << endl;
    cout << "Signature:______________________" << endl;
    cout << "==========================================" << endl;
}