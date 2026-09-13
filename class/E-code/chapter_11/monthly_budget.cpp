/* 
 * File:   monthly_budget.cpp
 * Author: Kevin Santiago
 * Created on October 18, 2026
 * Purpose:  Compare the money spent in a month with the budget of a student using a structure and functions
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

struct mbud
{
    float hous, util, hhold, trans, food;
    float med, ins, ent, cloth, misc;
};

//Function Prototypes
void ask(mbud &);
void line(string, float, float);
void show(mbud, mbud);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    mbud plan = {500, 150, 65, 50, 250, 30, 100, 150, 75, 50}, spent;

    //Initialize Variables
    cout << fixed << setprecision(2);

    //Process or map Inputs to Outputs
    ask(spent);

    //Display Outputs
    show(plan, spent);

    //Exit stage right!
    return 0;
}

//Asks the user for the amount spent in each category
void ask(mbud &s)
{
    cout << "Enter housing cost for the month:$" << endl;
    cin >> s.hous;
    cout << "Enter utilities cost for the month:$" << endl;
    cin >> s.util;
    cout << "Enter household expenses cost for the month:$" << endl;
    cin >> s.hhold;
    cout << "Enter transportation cost for the month:$" << endl;
    cin >> s.trans;
    cout << "Enter food cost for the month:$" << endl;
    cin >> s.food;
    cout << "Enter medical cost for the month:$" << endl;
    cin >> s.med;
    cout << "Enter insurance cost for the month:$" << endl;
    cin >> s.ins;
    cout << "Enter entertainment cost for the month:$" << endl;
    cin >> s.ent;
    cout << "Enter clothing cost for the month:$" << endl;
    cin >> s.cloth;
    cout << "Enter miscellaneous cost for the month:$" << endl;
    cin >> s.misc;
}

//Shows if one category is over, under or even with the budget
void line(string n, float p, float s)
{
    if (s > p)
    {
        cout << n << " Over" << endl;
    }
    if (s < p)
    {
        cout << n << " Under" << endl;
    }
    if (s == p)
    {
        cout << n << " Even" << endl;
    }
}

//Shows the report of every category and of the whole budget
void show(mbud p, mbud s)
{
    float tp, ts, diff;

    line("Housing", p.hous, s.hous);
    line("Utilities", p.util, s.util);
    line("Household Expenses", p.hhold, s.hhold);
    line("Transportation", p.trans, s.trans);
    line("Food", p.food, s.food);
    line("Medical", p.med, s.med);
    line("Insurance", p.ins, s.ins);
    line("Entertainment", p.ent, s.ent);
    line("Clothing", p.cloth, s.cloth);
    line("Miscellaneous", p.misc, s.misc);

    tp = p.hous + p.util + p.hhold + p.trans + p.food + p.med + p.ins + p.ent + p.cloth + p.misc;
    ts = s.hous + s.util + s.hhold + s.trans + s.food + s.med + s.ins + s.ent + s.cloth + s.misc;
    diff = ts - tp;

    //The last line does not get a line break, like the expected output
    if (diff > 0)
    {
        cout << "You were $" << diff << " over budget";
    }
    if (diff < 0)
    {
        cout << "You were $" << -diff << " under budget";
    }
    if (diff == 0)
    {
        cout << "You were right on budget";
    }
}