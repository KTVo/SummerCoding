/* 
 * File:   SinglyLinkedList_main.cpp
 * Author: Kevin Vo
 *
 * Created on June 13, 2020, 4:16 PM
 */

#include "SinglyLinkedList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void *insertFront(int val)
{
    if(node.head == node.tail)
    {  
        node.head = new Node;
        node.tail = new Node;
        
        node.tail->next = NULL;
        
        Node *newNode = new Node;
        
        newNode->val = val;
        
        node.head->next = newNode;
        newNode->next = node.tail;
        
        node.sz++;
        
    }
    else 
    {
        Node *newNode = new Node;
        newNode->next = node.head->next;
       
        node.head->next = newNode;
       
        newNode->val = val;

        node.sz++;
        
    }
    
}

Node *insertBack(int val)
{

    if(node.head == node.tail)
    {
        node.head = new Node;
        node.tail = new Node;
        
        node.tail->next = NULL;
        
        Node *newNode = new Node;
        
        newNode->val = val;
        
        node.head->next = newNode;
        newNode->next = node.tail;
       
        node.sz++;
        
    }
    else 
    {
        Node *temp = node.head;
        
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        
        Node *newNode = new Node;
        newNode->next = node.tail;
       
        temp->next = newNode;
       
        newNode->val = val;
        
        node.sz++;
    }
    
}

void deleteNode()
{
    if(node.head->next != node.tail)
    {
        Node *temp = node.head;
        node.head = node.head->next;
        delete temp;
        
        node.sz--;
    }
}

int count()
{
    return node.sz;
}

void displayList()
{
    Node *ptr = node.head->next;

    while(ptr->next != NULL)
    {
        cout<<ptr->val;
        
        if(ptr->next->next != NULL)
            cout<<" -> ";
        
        ptr = ptr->next;
    }
    
    cout<<endl;
}

void clean()
{
    while(node.head->next != node.tail)
    {
        Node *temp = node.head;
        node.head = node.head->next;
        delete temp;
        
        node.sz--;
    }
    
    node.head = node.tail;
}

void replaceAll(const int old_val, const int new_val)
{
    if(old_val != new_val)
    {
        Node *temp = node.head;

        while(temp != node.tail)
        {
            if(temp->val == old_val)
            {
                temp->val = new_val;
            }
            
            temp = temp->next;
        }
    }
}

void replace(const int old_val, const int new_val)
{
    bool found = false;
    if(old_val != new_val)
    {
        Node *temp = node.head;
        while(temp != node.tail && !found)
        {    
            if(temp->val == old_val)
            {
                temp->val = new_val;
                
                found = true;
            }

            temp = temp->next;
            
        }
    }
}



