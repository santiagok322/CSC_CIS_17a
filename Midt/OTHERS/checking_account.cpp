/* 
 * File:   checking_account.cpp
 * Author: Kevin Santiago
 * Created on October 27, 2026
 * Purpose:  Find the new balance of a checking account using a dynamic structure and dynamic arrays
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const float FEE = 20.00;

struct Customer
{
    int acctNum;
    string name;
    string address;
    float begBal;
    int numChecks;
    float *checks;
    int numDeposits;
    float *deposits;
};

//Function Prototypes
void ask(Customer *);
float *fill(int &, string);
float sum(const float *, int);
float calc(const Customer *);
void show(const Customer *, float);
void clean(Customer *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Customer *customer = new Customer;
    float newBal;

    //Initialize Variables
    cout << fixed << setprecision(2);

    //Process or map Inputs to Outputs
    ask(customer);
    newBal = calc(customer);

    //Display Outputs
    show(customer, newBal);

    //Recover allocated memory
    clean(customer);

    //Exit stage right!
    return 0;
}

//Asks the user for every fact of the customer
void ask(Customer *cust)
{
    do
    {
        cout << "Enter account number (5 digits only):" << endl;
        cin >> cust->acctNum;
        if (!cin)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cust->acctNum = 0;
        }
    } while (cust->acctNum < 10000 || cust->acctNum > 99999);
    cin.ignore(1000, '\n');

    cout << "Enter name:" << endl;
    getline(cin, cust->name);
    cout << "Enter address:" << endl;
    getline(cin, cust->address);
    cout << "Enter balance at the beginning of the month:$" << endl;
    cin >> cust->begBal;

    cust->checks = fill(cust->numChecks, "check");
    cust->deposits = fill(cust->numDeposits, "deposit");
}

//Fills a dynamic array until the user enters 0, the array doubles when it is full
float *fill(int &count, string label)
{
    int capacity = 2;
    float *list = new float[capacity];
    float amount;

    count = 0;
    while (true)
    {
        cout << "Enter " << label << " #" << count + 1 << " (0 when done):$" << endl;
        cin >> amount;
        if (!cin || amount <= 0)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }
        if (count == capacity)
        {
            float *bigger = new float[capacity * 2];
            for (int i = 0; i < count; i++)
            {
                bigger[i] = list[i];
            }
            delete [] list;
            list = bigger;
            capacity *= 2;
        }
        list[count] = amount;
        count++;
    }
    return list;
}

//Adds up all the values of an array
float sum(const float *list, int count)
{
    float total = 0;

    for (int i = 0; i < count; i++)
    {
        total += list[i];
    }
    return total;
}

//Calculates the new balance
float calc(const Customer *cust)
{
    return cust->begBal - sum(cust->checks, cust->numChecks) + sum(cust->deposits, cust->numDeposits);
}

//Shows the contents of the structure, the new balance and the fee if overdrawn
void show(const Customer *cust, float newBal)
{
    cout << endl;
    cout << "Account Number:" << cust->acctNum << endl;
    cout << "Name:" << cust->name << endl;
    cout << "Address:" << cust->address << endl;
    cout << "Beginning Balance:$" << cust->begBal << endl;
    cout << "Checks:";
    for (int i = 0; i < cust->numChecks; i++)
    {
        cout << " $" << cust->checks[i];
    }
    cout << endl;
    cout << "Deposits:";
    for (int i = 0; i < cust->numDeposits; i++)
    {
        cout << " $" << cust->deposits[i];
    }
    cout << endl;
    cout << "New Balance:$" << newBal << endl;
    if (newBal < 0)
    {
        cout << "Your account is overdrawn!" << endl;
        cout << "An additional $" << FEE << " fee has been assessed" << endl;
        cout << "Balance with the fee:$" << newBal - FEE << endl;
    }
}

//Gives back the memory of the arrays and of the structure
void clean(Customer *cust)
{
    delete [] cust->checks;
    delete [] cust->deposits;
    delete cust;
}