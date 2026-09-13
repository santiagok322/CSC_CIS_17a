/* 
 * File:MTOF.cpp
 * Author:Kevin santiago 
 * Date:09/12/26
 * Purpose: A2: More Test Output Format
 * Version:1.0
 */

//System Libraries - Post Here
#include <iostream>
//Library for our functions utilized in this question.
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    int a, b, c, d;
    int num;
    //7 characters or less
    
    //Initialize or input data here;
    a=1,b=2,c=3,d=4;
    int nums[4] = {a,b,c,d};
    //Display initial conditions, headings here
    for(int i = 0; i < 4; i++) {
       num=nums[i];
        
    cout << setw(9) << num
             << setw(10) << fixed << setprecision(1) << (double)num
             << setw(10) << fixed << setprecision(2) << (double)num;
             if (i<3) cout << endl;
    }
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}