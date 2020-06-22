#include "HashTable.h"
#include <iostream>
#include <cstdlib>

HashTable::HashTable(const int size)
{
    arr = new Node[size];
    this->size = size;
    int cnt = 0;
    
}
HashTable::~HashTable()
{
    delete[] arr;
}

unsigned int HashTable::hashGen(const int input)
{
    unsigned int key = input%size;
    
    return key;
}

void HashTable::insert(const int val)
{
    unsigned int key = hashGen(val);
 
    Node *tempHead = &arr[key];
    if(tempHead->next == tempHead->tail)
    {
        Node *newNode = new Node;
        newNode->val = val;
        newNode->next = tempHead->tail;
        tempHead->next = newNode;
        
        
        
    }
    else
    {
        Node *temp = &arr[key];
        
        while(temp != temp->next->tail)
        {
            temp = temp->next;
        }
        
        Node *newNode = new Node;
        newNode->next = temp->tail;
        newNode->val = val;

        temp->next = newNode;
        
       
        
        
    }
     
}