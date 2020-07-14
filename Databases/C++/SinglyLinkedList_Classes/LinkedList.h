/* Name: Kevin Vo
 * Date: 7/10/2020
 * Filename: LinkedList.h
 * Description: A singly linked list using a class.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "LinkedList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void clear();
    void insertFront(const T);
    void insertBack(const T);
    void popFront();
    void popBack();
    T peakFront();
    T peakBack();
    int count() const { return sz; };
    void displayLinkedList();

    
private: 
    int sz;
    
    struct Node
    {
        T val;
        Node *next;
    } *head, *tail, *access;
    

};



//constructor
//dyn allocates head and tail nodes
template <class T>
LinkedList<T>::LinkedList()
{
    head = new Node;
    tail = new Node;
    
    head->next = tail;
    tail->next = NULL;
    
    sz = 0;

}

//deletes entire linked list
template <class T>
LinkedList<T>::~LinkedList()
{
    clear();
    delete head;
    delete tail;
}


//Displays the entire linked list
template <class T>
void LinkedList<T>::displayLinkedList()
{
    Node *front = head->next;
    Node *back = tail;

    cout<<endl;
    
    if(front != tail)
    {

        while(front != tail)
        {
            cout<<front->val;
            if(front->next != tail)
                cout<<" -> ";
            
            front = front->next;
        }

        
    }
    else
    {
        cout<<"The List is empty.";
    }
    
    cout<<endl;
}

//Removes the (first) node after the head
template <class T>
void LinkedList<T>::popFront()
{
    if(head->next != tail)
    {
        Node *tempDelete = head->next;
        
        head->next = head->next->next;
        
        delete tempDelete;
        
        sz--;
    }
        
}

//removes the (last) node before the tail
template <class T>
void LinkedList<T>::popBack()
{
    if(head->next != tail)
    {
        Node *temp = head;

        while(temp->next->next != tail)
        {
            temp = temp->next;
        }
        
        if(temp != head)
        {
            Node *tempDelete = temp->next;
            temp->next = tail;
            delete tempDelete;
            sz--;
        }

    }
}

//displays the first value after the list
template <class T>
T LinkedList<T>::peakFront()
{
    if(head->next != tail)
    {
        
        return head->next->val;
    }
        
}

//shows the value of the (last) node on the list
template <class T>
T LinkedList<T>::peakBack()
{
    if(head->next != tail)
    {
        Node *temp = head->next;

        while(temp->next != tail)
        {
            temp = temp->next;
        }
        
        return temp->val;
    }
        
}

//inserts as the 1st node (after the head)
template <class T>
void LinkedList<T>::insertFront(const T val)
{
    Node *node = new Node;
    node->val = val;
   
    
    node->next = head->next;
    
    head->next = node;

    sz++;
  
}

//inserts as the last node (before the tail)
template <class T>
void LinkedList<T>::insertBack(const T val)
{
    Node *node = new Node;
    
    node->val = val;
    
    Node *temp = head->next;
    
    while(temp->next != tail)
    {
        temp = temp->next;
    }
    
    node->next = tail;
    
    temp->next = node;
    
    sz++;
   
}


//Clears the entire list, leaves head and tail node behind
template <class T>
void LinkedList<T>::clear()
{
    Node *tempHead = head->next;
    
    while(tempHead != tail)
    {
        Node *tempDelete = tempHead;
        tempHead = tempHead->next;
        delete tempDelete;
        sz--;

    }
    
    head->next = tail;

}
#endif /* LINKEDLIST_H */

