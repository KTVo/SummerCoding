/* 
 * File:   Array_of_Functions_main.cpp
 * Author: Kevin Vo
 *
 * Created on July 11, 2020, 7:56 AM
 * 
 * Description: The code below demonstrates that an array function pointers
 *              with he same amount of parameters can be constructed.
 */
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef int(*FunctionArrayOfInts)(int, int);

int sum(const int a, const int b)
{
    return a + b;
}

int substract(const int a, const int b)
{
    return a - b;
}

int cubed(const int a, const int b)
{
    return a*a*a;
}

string description()
{
    return "\nThis demonstrates that there can be an array of functions' pointers of different data types.\n";
}



int main(int argc, char** argv) {
    
    const int a = 5, b = 9;
    
    FunctionArrayOfInts arrayOfFns[] =
    {
        sum,
        substract,
        cubed
        
    };
    
    cout<<description();
           
    for(int i = 0; i < sizeof(arrayOfFns)/sizeof(PFI); i++)
        cout<<"\n"<<arrayOfFns[i](a, b);
    
    return 0;
}

