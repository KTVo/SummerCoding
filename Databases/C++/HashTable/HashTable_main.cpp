/* 
 * File:   HashTable_main.cpp
 * Author: Kevin
 *
 * Created on July 1, 2020, 10:36 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>   //for stoi(string) for hashing
#include "HashTable.h"

using namespace std;


int main(int argc, char** argv) {
    PersonalData p;
    HashTable h;
    
    for(int i = 0; i < 3; i++)
    {
        cout<<"Name: ";
        cin.ignore();
        getline(cin, p.name);

        
        cout<<"Age: ";
        cin>>p.age;   

        cout<<"Address: ";
        cin.ignore();
        getline(cin, p.address);

        
        do
        {
            cout<<"Phone: ";
            cin>>p.phone;
        }while(!h.phoneStatus(p.phone));

        
        
        h.add(p);
    }
    
    h.view();
    
    return 0;
}

