/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HashTable.h
 * Author: Kevin Vo
 *
 * Created on June 19, 2020, 1:32 PM
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable
{
private:
    struct Node
    {
        int val;
        Node *next, *tail, *head = tail;
        int sz = 1;
    
    
    };
    
    Node *arr;
    int size;
    int cnt;
    
    
    
public:
    HashTable(const int);
    ~HashTable();
    void insert(const int val);
    unsigned int hashGen(const int);
    
    
    
};


#endif /* HASHTABLE_H */

