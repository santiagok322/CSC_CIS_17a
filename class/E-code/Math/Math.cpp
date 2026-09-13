/* 
 * File:Math.cpp
 * Author:Kevin santiago 
 * Date:09/12/26
 * Purpose:math operations
 * Version:1.0
 */

//System Libraries - Post Here
#include <iostream>
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
    //3 integers a b c  
    int a=3,b=2,c=1,rlt;
    /*
    a + b
    b + a - c
    (a+b)*c
    (a/b)*c
    (a*c)/b
    */
    

    //Initialize or input data here
    
    //Display initial conditions, headings here
   
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
     rlt= a + b;
    cout <<"A + B is: "<<rlt<<endl;
     rlt= b + a - c;
    cout <<"B + A - C is: "<<rlt<<endl;
     rlt= (a + b) * c ;
    cout <<"(A + B) * C is: "<<rlt<<endl;
    rlt= (a / b) * c ;
    cout<<"(A / B) * C is: "<<rlt<<endl; 
    rlt= (a * c) / b ;
     cout<<"(A * C) / B is: "<<rlt<<endl; 
     rlt= (a % b);
     cout<<"A % B is: "<<rlt<<endl; 
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}