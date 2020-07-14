/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph_Creator_main.cpp
 * Author: Kevin
 *
 * Created on July 13, 2020, 11:58 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;


class Graph
{
private:
    int numNode;
    Link *findNode(const int);
    struct Link 
    {
        Node *node; 
        
        struct Node
        {
            int val;
            Link *ptr;
        } *tempO, *tempD;
        
        
    } *root;
    
    
    Link::Node* findNode(const int val, Link *ptr)
    {
        if(root->node == NULL)
            return NULL;
        
        if(root->node->val == val)
            return root->node;
        
        findNode(root->ptr);
        
    }
    
public:
    void add_edge(const int, const int);
    Graph(const int);
    create_node(const int);
    
};


Graph::Graph(const int val)
{
    root->node = new Link::Node;
    root->node->val = val;
    root->ptr = NULL;
    
}

void Graph::create_node(const int val)
{
    Link::Node newNode = new Link::Node;
    
    newNode->val = val;
    
    
}

void Graph::add_edge(const int origin, const int dest)
{
    Link::tempO = findNode(origin);
    Link::tempD = findNode(dest);
    
    if(findNode(Link::tempO->val) != NULL && findNode(Link::tempD->val) != NULL)
    {
        Link *newLink = new Link;
        newLink->node = Link::tempO;
        newLink->ptr = Link::tempD;
    }
    else
    {
        if(Link::tempO == NULL)
            cout<<"\nNo such Origin Node.\n";

        if(Link::tempD == NULL)
            cout<<"\nNo such Destination Node.\n";
    }
    
}

int main(int argc, char** argv) {

    return 0;
}

