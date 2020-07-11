/* Name: Kevin Vo
 * Date: 7/10/2020
 * Filename: SinglyLinkedList_C_main.cpp
 * Description: Driver for a singly linked list using a class.
 */


#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

using namespace std;


int main(int argc, char** argv) {
    LinkedList<int> l;
    
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

    
    l.displayLinkedList();
    
    cout<<"Now enter item for back insertion: ";
    cin>>input;
    
    l.insertBack(input);

    l.displayLinkedList();
    
    cout<<"\nPopping the BACK\n";
    
    cout<<"\ncount = "<<l.count()<<endl;
    
    l.popBack();
    
    l.displayLinkedList();
    
    cout<<"\nPopping the FRONT\n";
    
    l.popFront();
    
    cout<<"\ncount = "<<l.count()<<endl;
    
    l.displayLinkedList();
    
    
    
    cout<<"\nNow clearing\n";
    
    l.clear();
    
    cout<<"\ncount = "<<l.count()<<endl;
    
    l.displayLinkedList();
    
    return 0;
}

