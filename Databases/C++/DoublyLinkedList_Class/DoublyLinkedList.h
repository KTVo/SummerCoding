/* 
 * File:   DoubleLinkedList.h
 * Author: Kevin Vo
 *
 * Created on July 12, 2020, 10:18 AM
 */

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class DoublyLinkedList
{

private: 
    int sz;
    
    struct Node
    {
        T val;
        Node *next, *prev;
    } *head, *tail;
    
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void clear();
    void insertFront(const T);
    void insertBack(const T);
    void popFront();
    void popBack();
    T peakFront();
    T peakBack();
    int count() const { return sz; };
    void displayForwards();
    void displayBackwards();
    bool search(const T);

    

};

//Searches list from head to tail for a value
template <class T>
bool DoublyLinkedList<T>::search(const T val)
{
    Node *temp = head->next;
    while(temp != tail)
    {
        if(val == temp->val)
            return true;
        
        temp = temp->next;
    }
    
    return false;
}

//constructor
//dyn allocates head and tail nodes
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = new Node;
    tail = new Node;
    
    head->prev = NULL;
    head->next = tail;
    
    
    tail->prev = head;
    tail->next = NULL;
    
    
    sz = 0;

}

//deletes entire linked list
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
    delete head;
    delete tail;
}

//Displays the entire linked list 
template <class T>
void DoublyLinkedList<T>::displayForwards()
{
    Node *back = tail->prev;

    cout<<endl;
    
    if(back != head)
    {

        while(back != head)
        {
            cout<<back->val;
            if(back->prev != head)
                cout<<" -> ";
            
            back = back->prev;
        }

        
    }
    else
    {
        cout<<"The List is empty.";
    }
    
    cout<<endl;
}

//Displays the entire linked list
template <class T>
void DoublyLinkedList<T>::displayBackwards()
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
void DoublyLinkedList<T>::popFront()
{
    if(head->next != tail)
    {
        Node *tempDelete = head->next;
        
        head->next = head->next->next;
        head->next->next->prev = head;
        
        delete tempDelete;
        
        sz--;
    }
        
}

//removes the (last) node before the tail
template <class T>
void DoublyLinkedList<T>::popBack()
{
    if(head->next != tail)
    {
        
        if(tail->prev != head)
        {
            Node *tempDelete = tail->prev;
            
            tail->prev = tail->prev->prev;
            tail->prev->prev->next = tail;
            
            delete tempDelete;
            
            sz--;
        }

    }
}

//displays the first value after the list
template <class T>
T DoublyLinkedList<T>::peakFront()
{
    if(head->next != tail)
    {
        
        return head->next->val;
    }
        
}

//shows the value of the (last) node on the list
template <class T>
T DoublyLinkedList<T>::peakBack()
{
    if(head->next != tail)
    {
        return tail->prev->val;
    }
        
}

//inserts as the 1st node (after the head)
template <class T>
void DoublyLinkedList<T>::insertFront(const T val)
{
    Node *node = new Node;
    node->val = val;
   
    node->prev = head;
    node->next = head->next;
    
    head->next->prev = node;
    head->next = node;

    sz++;
  
}

//inserts as the last node (before the tail)
template <class T>
void DoublyLinkedList<T>::insertBack(const T val)
{
    Node *node = new Node;
    
    node->val = val;
    
    node->prev = tail->prev;
    node->next = tail;
    
    tail->prev->next = node;
    tail->prev = node;
    
    sz++;
   
}


//Clears the entire list, leaves head and tail node behind
template <class T>
void DoublyLinkedList<T>::clear()
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
    tail->prev = head;

}

#endif /* DOUBLELINKEDLIST_H */

