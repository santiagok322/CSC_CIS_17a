
/*
 * File:   prime.cpp
 * Author: Kevin Santiago
 * Created on October 28, 2026
 * Purpose: Factor a number into its prime numbers
 */

//System Libraries
#include <iostream>

using namespace std;

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

//Function Prototypes
Primes *factor(int);
void prtPrms(const Primes *);
void cleanUp(Primes *);

//Execution Begins Here
int main(int argc, char** argv)
{
    //Declare Variable Data Types
    int num;
    Primes *result;

    //Initialize Variables
    cout << "Enter a number between 2 and 65000:" << endl;
    cin >> num;

    //Process or map Inputs to Outputs
    if (num < 2 || num > 65000)
    {
        cout << "Invalid number." << endl;
        return 1;
    }

    result = factor(num);

    //Display Outputs
    prtPrms(result);

    //Recover allocated memory
    cleanUp(result);

    //Exit stage right!
    return 0;
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
