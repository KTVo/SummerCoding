/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HashTable_main.cpp
 * Author: Kevin
 *
 * Created on July 1, 2020, 10:36 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>   //for stoi(string) for hashing

using namespace std;

struct PersonalData
{
    string name;
    int age;
    string phone;
    string address;
};

class HashTable
{
    
private:
    
    struct Node
    {
        string name;
        int age;
        string phone;
        string address;
        Node *ptr;
    };
    
    int sz;
    Node* arr;
    unsigned int hash_gen(const int);
    
public:
    HashTable();    //Constructor 
    HashTable(const int);
    ~HashTable();   //Destructor
    void add(const struct PersonalData);
    void view();
};

HashTable::HashTable()
{
    sz = 25;
    arr = new Node[sz];
    
    for(int i = 0; i < sz; i++)
    {
        arr[i].name = "";
        arr[i].phone = "";
        arr[i].age = 0;
        arr[i].address = "";
        arr[i].ptr = NULL;
    }
}

HashTable::HashTable(const int sz)
{
    this->sz = sz;
    arr = new Node[sz];
    
    for(int i = 0; i < sz; i++)
    {
        arr[i].name = "";
        arr[i].phone = "";
        arr[i].age = 0;
        arr[i].address = "";
        arr[i].ptr = NULL;
    }
}

HashTable::~HashTable()
{
    for(int i = 0; i < sz; i++)
    {
        cout<<arr+i<<endl;
        
        Node *p = (arr+i)->ptr;
        
        while(p != NULL)
        {
            cout<<"\t"<<p->age;

            p = p->ptr;
        }
    }
        
    cout<<endl;
    
    for(int i = 0; i < sz; i++)
    {
        Node *temp = arr[i].ptr;
        
        while(temp != NULL)
        {
            
            Node *tempDelete = temp;
            
            temp = temp->ptr;
                
            delete tempDelete->ptr;

        }
        
    }
    cout<<endl<<"second"<<endl<<endl;
    
    for(int i = 0; i < sz; i++)
    {
        cout<<arr+i<<endl;
        
        Node *p = (arr+i)->ptr;
        
        while(p != NULL)
        {
            cout<<"\t"<<p->age;

            p = p->ptr;
        }
    }
    
   delete []arr;
}

void HashTable::add(const struct PersonalData p)
{
    cout<<endl<<0<<endl;
    
    Node* newNode = new Node;
    
    newNode->name = p.name;
    newNode->address = p.address;
    newNode->age = p.age;
    newNode->phone = p.phone;
    newNode->ptr = NULL;
    
    cout<<endl<<1<<endl;
    
    string::size_type sz;
    
    unsigned int hashVal = hash_gen(newNode->age);
    
    cout<<endl<<2<<endl;
    
    Node* tempPtr = (arr + hashVal);
    
    cout<<endl<<3<<endl;
    
    while(tempPtr->ptr != NULL)
    {
        cout<<endl<<4<<endl;
        
        tempPtr = tempPtr->ptr;
        
        cout<<endl<<5<<endl;
    }
    tempPtr->ptr = newNode;
    cout<<endl<<6<<endl;
    
}



unsigned int HashTable::hash_gen(const int inVal)
{
    return inVal%sz;
}

void HashTable::view()
{
    for(int i = 0; i < sz; i++)
    {
        if(arr[i].age != 0)
        {
            cout<<"arr[ "<<i<<" ]->";
            Node *temp = (arr + i);
            
            while(temp != NULL)
            {
                cout<<"\t"<<temp->name<<"\n-> "<<temp->address<<"\n-> "<<temp->age
                        <<"\n-> "<<temp->phone<<endl<<endl;
                
                temp = temp->ptr; 
            }
        }
    }
}

int main(int argc, char** argv) {
    PersonalData p;
    HashTable h;
    
    for(int i = 0; i < 2; i++)
    {
        cout<<"Name: ";
        getline(cin, p.name);
        
        cout<<endl<<p.name<<endl;
        
        cout<<"Age: ";
        cin>>p.age;
        
        cout<<endl<<p.age<<endl;
        
        cin.ignore();

        cout<<"Address: ";
        getline(cin, p.address);

        cout<<endl<<p.address<<endl;
        
        cout<<"Phone: ";
        getline(cin, p.phone);
        
        cout<<endl<<p.phone<<endl;

        h.add(p);
    }
    
    //h.view();
    
    return 0;
}

