/* 
 * File:   weather.cpp
 * Author: Kevin Santiago
 * Created on October 18, 2026
 * Purpose:  Store the weather of a year using an array of structures and functions
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const int SIZE = 12;

struct wea
{
    string mon;
    float rain, low, high, avg;
};

//Function Prototypes
void ask(wea &);
float temp();

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    wea yr[SIZE];
    float rain = 0, sum = 0;
    int lo = 0, hi = 0;

    //Process or map Inputs to Outputs
    for (int i = 0; i < SIZE; i++)
    {
        ask(yr[i]);
        rain = rain + yr[i].rain;
        sum = sum + yr[i].avg;

        //I save the position of the lowest and the highest, the first one wins a tie
        if (yr[i].low < yr[lo].low)
        {
            lo = i;
        }
        if (yr[i].high > yr[hi].high)
        {
            hi = i;
        }
    }

    //Display Outputs
    cout << fixed << setprecision(1);
    cout << "Average Rainfall " << rain / SIZE << " inches/month" << endl;
    cout << setprecision(0);
    cout << "Lowest  Temperature " << yr[lo].mon << "  " << yr[lo].low << " Degrees Fahrenheit" << endl;
    cout << "Highest Temperature " << yr[hi].mon << "  " << yr[hi].high << " Degrees Fahrenheit" << endl;
    cout << "Average Temperature for the year " << sum / SIZE << " Degrees Fahrenheit" << endl;

    //Exit stage right!
    return 0;
}

//Asks the user for the data of one month and calculates its average
void ask(wea &w)
{
    cin >> w.mon >> w.rain;
    w.low = temp();
    w.high = temp();
    w.avg = (w.low + w.high) / 2;
}

//Reads a temperature and asks again if it is out of range
float temp()
{
    float t;

    cin >> t;
    while (t < -100 || t > 140)
    {
        cout << "Enter a temperature between -100 and 140" << endl;
        cin >> t;
    }
    return t;
}