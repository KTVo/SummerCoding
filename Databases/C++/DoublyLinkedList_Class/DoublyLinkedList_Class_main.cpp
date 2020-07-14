/* 
 * File:   DoublyLinkedList_Class_main.cpp
 * Author: Kevin Vo
 *
 * Created on July 12, 2020, 10:16 AM
 */

#include <cstdlib>
#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    DoublyLinkedList<int> l;
    
    srand(time(NULL));
    int input;
    int sz = rand()%9 + 10;
    
    cout<<"\nWill insert "<<sz+1<<" random generated values.\n";
    
    
    for(int i = 0; i < sz; i++)
    {
        input = rand()%1000;
        
        cout<<"Entered item #"<<l.count()<<": "<<input<<endl;
    
        l.insertFront(input);
    }

    
    l.displayForwards();
    
    cout<<"Now enter item for back insertion: ";
    cin>>input;
    
    l.insertBack(input);

    l.displayBackwards();
    
    cout<<"\nPopping the BACK\n";
    
    cout<<"\ncount = "<<l.count()<<endl;
    
    l.popBack();
    
    l.displayForwards();
    
    cout<<"\nPopping the FRONT\n";
    
    l.popFront();
    
    cout<<"\ncount = "<<l.count()<<endl;
    
    l.displayBackwards();
    
    
    
    cout<<"\nNow clearing\n";
    
    l.clear();
    
    cout<<"\ncount = "<<l.count()<<endl;
    
    l.displayBackwards();

    return 0;
}

