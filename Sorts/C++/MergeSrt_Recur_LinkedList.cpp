/* 
 * File:   MergeSort_LinkedList_main.cpp
 * Author: Kevin Vo
 *
 * Created on July 30, 2020, 7:03 PM
 * Purpose:  Performs Merge Sort on a Linked List
 */

#include <iostream>
#include <cstdlib>

using namespace std;

class SinglyLinkedList
{
private:
    int cntNode;
    struct Node
    {
        int val;
        Node *next;
    } *head, *tail;
    
public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    void clear();
    void push(const int);
    int peek() const;
    void pop();
    void viewAll();
    int countNode() const { return cntNode; }
    Node *getHead() const { return head; }
    Node *getTail() const { return tail; }
    Node *getAddr(const int indx) const
    {
        if(indx > cntNode && indx < 0)
            cout<<"\nInvalid. Chosen Index is greater than the number of nodes.\n";

        else if(indx < 0)
            cout<<"\nInvalid. Chosen Index is a negative value.\n";
        else
        {
            Node *temp = head->next;
            int cnt = 0;

            while(temp != tail && cnt <= indx)
            {
                temp = temp->next;
                cnt++;
            }

            return temp;

        }

        return NULL;
    }

};




void SinglyLinkedList::viewAll()
{
    Node *tempHead = head->next;
    
    cout<<endl;
    
    while(tempHead != tail)
    {
        cout<<tempHead->val;
        
        if(tempHead->next != tail)
            cout<<", ";
        
        tempHead = tempHead->next;
    }
    
    cout<<endl;
}

int SinglyLinkedList::peek() const
{
    if(head->next != NULL)
        return head->next->val;

}

void SinglyLinkedList::push(const int val)
{
    Node *temp = new Node;
    temp->val = val;
    
    temp->next = head->next;
    head->next = temp;
    
    cntNode++;
    
}

void SinglyLinkedList::pop()
{
    
    if(head->next != tail)
    {
        Node *temp = head->next;
        head->next = head->next->next;
        delete temp;
        cntNode--;
    }
}

SinglyLinkedList::SinglyLinkedList()
{
    head = new Node;
    tail = new Node;
    
    head->next = tail;
    tail->next = NULL;
    
    cntNode = 0;
}

SinglyLinkedList::~SinglyLinkedList()
{
    clear();
    delete head;
    delete tail;
}

void SinglyLinkedList::clear()
{
    Node *tHead = head->next;
    
    while(tHead != tail)
    {
        Node *temp = tHead;
        tHead = tHead->next;
        delete temp;
        cntNode--;
    }
}

class MergeSort
{
private:
    int sz;
    int *array;
    void runMergeSort(int, int);
    void merge(int, int, int);
public:
    MergeSort(SinglyLinkedList);
    ~MergeSort();
    
    
    
    
};

void MergeSort::runMergeSort(int start, int end)
{
    if(start < end)
    {
        int mid = (start + end)/2;
        runMergeSort(start, mid);
        runMergeSort(mid + 1, end);
        merge(start, mid, end);
    }
}

void MergeSort::merge(SinglyLinkedList s, int start, int mid, int end)
{
    int L_sz = start + mid + 1;
    int R_sz  = end - mid;
    
    int L[L_sz];
    int R[R_sz];
    
    int A_sz = start;
    
    for(int i = 0; i < L_sz; i++)
        L[i] = array[start + i];
    
    for(int i = 0; )
}
MergeSort::MergeSort(SinglyLinkedList s)
{
    sz = s.countNode;
    array = new int[sz];
    
    for(int i = 0; i < sz; i++)
    {
        array[i] = s.peek();
        s.pop();
    }
    
    runMergeSort(0, sz-1);
}


MergeSort::~MergeSort()
{
    sz = 0;
    start = 0;
    end = 0;
    mid = 0;
    delete[] array;
}


int main(int argc, char** argv) {
    SinglyLinkedList s;
    
    const int numElem = 10;
    for(int i = 0; i < numElem; i++)
        s.push(i);
    
    cout<<"\nNode Count = "<<s.countNode()<<endl;
    
    cout<<"\nPeek = "<<s.peek()<<endl;
    
    s.viewAll();
    
    cout<<"\nPopping...\n";
    s.pop();
    
    cout<<"\nPeek = "<<s.peek()<<endl;
    
    s.viewAll();    

    cout<<"\nNode Count = "<<s.countNode()<<endl;    
    
    return 0;
}

