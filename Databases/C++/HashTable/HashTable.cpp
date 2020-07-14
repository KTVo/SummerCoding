#include <cstdlib>
#include <iostream>
#include <string>   //for stoi(string) for hashing
#include "HashTable.h"

using namespace std;

bool HashTable::phoneStatus(const unsigned long long int phoneNum)
{
    if(phoneNum >= 1000000000 && phoneNum <= 9999999999)
        return true;

    return false;
}

HashTable::HashTable()
{
    for(int i = 0; i < sz; i++)
    {
        arr[i] = new Node;
        arr[i]->name = empty;
        arr[i]->phone = 0;
        arr[i]->age = 0;
        arr[i]->address = empty;
        arr[i]->ptr = NULL;
    }
}

HashTable::~HashTable()
{    
    for(int i = 0; i < sz; i++)
    {
        Node *temp = arr[i]->ptr;
        
        while(temp != NULL)
        {
            
            Node *tempDelete = temp;
            
            temp = temp->ptr;
                
            delete tempDelete->ptr;

        }
        
    }
    
}

void HashTable::add(const struct PersonalData p)
{   
    unsigned int hashVal = hash_gen(p.phone);

    Node* tempPtr = arr[hashVal];
    
    if(tempPtr->name == empty)
    {
        tempPtr->name = p.name;
        tempPtr->address = p.address;
        tempPtr->age = p.age;
        tempPtr->phone = p.phone;
        tempPtr->ptr = NULL;
    }
    else
    {
        Node* newNode = new Node;
    
        newNode->name = p.name;
        newNode->address = p.address;
        newNode->age = p.age;
        newNode->phone = p.phone;
        newNode->ptr = NULL;
    
        while(tempPtr->ptr != NULL)
        {
            tempPtr = tempPtr->ptr;

            cout<<endl<<5<<endl;
        }
        
        tempPtr->ptr = newNode;
    }
    
}



unsigned int HashTable::hash_gen(const int inVal)
{
    return inVal%sz;
}

void HashTable::view()
{
    for(int i = 0; i < sz; i++)
    {
        if(arr[i]->age != 0)
        {
            cout<<"arr[ "<<i<<" ]->";
            Node *temp = arr[i];
            
            while(temp != NULL)
            {
                cout<<"\t"<<temp->name<<"\n\t\t-> "<<temp->address<<"\n\t\t-> "
                    <<temp->age<<"\n\t\t-> "<<temp->phone<<endl<<endl;
                
                temp = temp->ptr; 
            }
        }
    }
}