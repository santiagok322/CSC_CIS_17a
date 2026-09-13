/* 
 * File:   movie_data.cpp
 * Author: Kevin Santiago
 * Created on October 18, 2026
 * Purpose:  Store and show the information of some movies using a structure and functions
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

struct mdata
{
    string title, dir;
    int year, len;
};

//Function Prototypes
void show(mdata);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    int num;
    mdata *mov;

    //Initialize Variables
    cout << "This program reviews structures" << endl;
    cout << "Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)." << endl;

    //Process or map Inputs to Outputs
    cin >> num;
    cin.ignore();
    mov = new mdata[num];

    for (int i = 0; i < num; i++)
    {
        getline(cin, mov[i].title);
        getline(cin, mov[i].dir);
        cin >> mov[i].year;
        cin >> mov[i].len;
        cin.ignore();
    }

    //Display Outputs
    for (int i = 0; i < num; i++)
    {
        show(mov[i]);
    }

    //I free the memory I asked for
    delete [] mov;

    //Exit stage right!
    return 0;
}

//Shows the information of one movie, with a blank line before it
void show(mdata m)
{
    cout << endl;
    cout << left << setw(11) << "Title:" << m.title << endl;
    cout << left << setw(11) << "Director:" << m.dir << endl;
    cout << left << setw(11) << "Year:" << m.year << endl;
    cout << left << setw(11) << "Length:" << m.len << endl;
}