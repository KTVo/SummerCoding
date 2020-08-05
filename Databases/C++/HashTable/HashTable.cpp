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
        arr[i]->word = "";
        arr[i]->def = "";
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
    unsigned int hashVal = hash_gen(p.word);

    Node* tempPtr = arr[hashVal];
    
    if(tempPtr->word == "")
    {
        tempPtr->word = p.word;
        tempPtr->def = p.def;
        tempPtr->ptr = NULL;
    }
    else
    {
        Node* newNode = new Node;
    
        newNode->word = p.word;
        newNode->def = p.def;
        newNode->ptr = NULL;
    
        while(tempPtr->ptr != NULL)
        {
            tempPtr = tempPtr->ptr;
        }
        
        tempPtr->ptr = newNode;
    }
    
}



unsigned int HashTable::hash_gen(const string inVal)
{
    return inVal%sz;
}

void HashTable::view()
{
    for(int i = 0; i < sz; i++)
    {
        if(arr[i]->word != "")
        {
            cout<<"arr[ "<<i<<" ]->";
            Node *temp = arr[i];
            
            while(temp != NULL)
            {
                cout<<"\t"<<temp->word<<"\n\t\t-> "<<temp->temp->def<<endl<<endl;
                
                temp = temp->ptr; 
            }
        }
    }
}