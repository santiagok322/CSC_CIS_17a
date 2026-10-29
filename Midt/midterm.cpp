
/*
 * File:   midterm.cpp
 * Author: Kevin Santiago
 * Purpose: Display the solutions for the midterm problems
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Problem 1 Constants, Structures and Function Prototypes
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

void problem1();
void askCustomer(Customer *);
float *fill(int &, string);
float sum(const float *, int);
float calcBalance(const Customer *);
void show(const Customer *, float);
void clean(Customer *);

//Problem 2 Constants, Structures and Function Prototypes
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

void problem2();
bool askEmployee(Employee &);
float calcPay(float, float);
string hundreds(int);
string words(long);
void check(const Employee &);

//Problem 3 Constants and Function Prototypes
const int SHIFT = 3;
const int BASE = 8;

void problem3();
void encryption();
void decryption();
bool valid(int, int &, int &, int &, int &);

//Problem 4 Function Prototypes
void problem4();

//Problem 5 Structures and Function Prototypes
struct Prime
{
    unsigned char power;
    unsigned short prime;
};

struct Primes
{
    unsigned short n;
    unsigned char nPrimes;
    Prime *pStrAry;
};

void problem5();
Primes *factor(int);
void prtPrms(const Primes *);
void cleanUp(Primes *);


//Execution Begins Here
int main(int argc, char** argv)
{
    //Declare Variable Data Types
    int choice;

    //Process or map Inputs to Outputs
    do
    {
        //Display the menu
        cout << endl;
        cout << "MIDTERM MENU" << endl;
        cout << "1. Checking Account" << endl;
        cout << "2. Employee Paycheck" << endl;
        cout << "3. Data Encryption" << endl;
        cout << "4. Factorial and Data Types" << endl;
        cout << "5. Prime Factors" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;

        //Select the problem
        switch (choice)
        {
            case 1:
                problem1();
                break;
            case 2:
                problem2();
                break;
            case 3:
                problem3();
                break;
            case 4:
                problem4();
                break;
            case 5:
                problem5();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    //Exit stage right!
    return 0;
}

//Problem 1 functions
void problem1()
{
    //Declare Variable Data Types and Constants
    Customer *customer = new Customer;
    float newBal;

    //Initialize Variables
    cout << fixed << setprecision(2);

    //Process or map Inputs to Outputs
    askCustomer(customer);
    newBal = calcBalance(customer);

    //Display Outputs
    show(customer, newBal);

    //Recover allocated memory
    clean(customer);
}

//Asks the user for every fact of the customer
void askCustomer(Customer *cust)
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
float calcBalance(const Customer *cust)
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

//Problem 2 functions
void problem2()
{
    //Declare Variable Data Types and Constants
    Employee *staff;
    int numEmployees;
    int done;
    bool okay = true;

    //Initialize Variables
    cout << fixed << setprecision(2);

    //Process or map Inputs to Outputs and Display Outputs
    //The process starts over until hours or rate are not valid
    while (okay)
    {
        cout << "How many employees will you enter (0 to quit)?" << endl;
        cin >> numEmployees;
        if (!cin || numEmployees <= 0)
        {
            break;
        }
        staff = new Employee[numEmployees];
        done = 0;
        while (done < numEmployees && okay)
        {
            okay = askEmployee(staff[done]);
            if (okay)
            {
                staff[done].grossPay = calcPay(staff[done].hours, staff[done].rate);
                done++;
            }
        }
        for (int i = 0; i < done; i++)
        {
            check(staff[i]);
        }
        delete [] staff;
    }
}

//Asks for one employee, returns false if hours or rate are negative
bool askEmployee(Employee &emp)
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
float calcPay(float hours, float rate)
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

//Problem 3 functions
void problem3()
{
    //Declare Variable Data Types and Constants
    int choice;

    //Display the menu
    cout << endl;
    cout << "Data Encryption" << endl;
    cout << "1. Encryption" << endl;
    cout << "2. Decryption" << endl;
    cout << "0. Exit" << endl;
    cin >> choice;

    //Select the option
    switch (choice)
    {
        case 1:
            encryption();
            break;
        case 2:
            decryption();
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
    }
}

//Encrypts a four-digit number made of the digits 0 to 7
void encryption()
{
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
        return;
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
}

//Decrypts a four-digit number made of the digits 0 to 7
void decryption()
{
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
        return;
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

//Problem 4 functions
void problem4()
{
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
}

//Problem 5 functions
void problem5()
{
    //Declare Variable Data Types and Constants
    int num;
    Primes *result;

    //Initialize Variables
    cout << "Enter a number between 2 and 65000:" << endl;
    cin >> num;

    //Process or map Inputs to Outputs
    if (num < 2 || num > 65000)
    {
        cout << "Invalid number." << endl;
        return;
    }

    result = factor(num);

    //Display Outputs
    prtPrms(result);

    //Recover allocated memory
    cleanUp(result);
}

//Factors the number into its prime numbers
Primes *factor(int num)
{
    Primes *result = new Primes;

    result->n = num;
    result->nPrimes = 0;
    result->pStrAry = new Prime[16];

    int count = 0;

    for (int i = 2; i <= num / i; i++)
    {
        if (num % i == 0)
        {
            int power = 0;

            while (num % i == 0)
            {
                num /= i;
                power++;
            }

            result->pStrAry[count].prime = i;
            result->pStrAry[count].power = power;
            count++;
        }
    }

    if (num > 1)
    {
        result->pStrAry[count].prime = num;
        result->pStrAry[count].power = 1;
        count++;
    }

    result->nPrimes = count;

    return result;
}

//Prints the prime factors
void prtPrms(const Primes *p)
{
    cout << p->n << " = ";

    for (int i = 0; i < p->nPrimes; i++)
    {
        cout << p->pStrAry[i].prime
             << "^" << static_cast<int>(p->pStrAry[i].power);

        if (i < p->nPrimes - 1)
        {
            cout << " * ";
        }
    }

    cout << endl;
}

//Gives back the memory
void cleanUp(Primes *p)
{
    delete [] p->pStrAry;
    delete p;
}
