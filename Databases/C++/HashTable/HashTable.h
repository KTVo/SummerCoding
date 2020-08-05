/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HashTable.h
 * Author: Kevin
 *
 * Created on July 14, 2020, 12:06 PM
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstdlib>
#include <iostream>
#include <string>   //for stoi(string) for hashing
    
using namespace std;
    
struct PersonalData
{
    string word;
    string def;
    int age;
    unsigned long long int phone;
    string address;
};


class HashTable
{
        
private:
    
    const string empty = "n/a";
    
    struct Node
    {
        string word;
        string def;
        Node *ptr;
    };
    
    static const int sz = 100;
    Node* arr[sz];
    unsigned int hash_gen(const int);
    
public:
    HashTable();    //Constructor 
    HashTable(const int);
    ~HashTable();   //Destructor
    bool phoneStatus(const unsigned long long int);
    void add(const struct PersonalData);
    void view();
};



#endif /* HASHTABLE_H */

