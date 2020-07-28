/* 
 * File:   Validate_BST_main.cpp
 * Author: Kevin Vo
 *
 * Created on July 28, 2020, 11:32 AM
 * 
 * Purpose: To be a Binary Search Tree (BST): 
 *      The lower and more left a node is, the larger its value must be.
 *      The lower and more right a node is, the smaller its value must be.
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//Node structure to construct the binary tree
struct Node
{
    int val;
    Node *left, *right, *prev;
};

//Creates the binary tree to be tested if it's a BST
Node* createTree()
{
    /*
    
           10
        2      13
      1   5  6

     */
    
    /*
    
            A
        B       C
      D   E  F

     */
    
    Node *A = new Node;
    Node *B = new Node;
    Node *C = new Node;
    Node *D = new Node;
    Node *E = new Node;
    Node *F = new Node;
    
    A->val = 10;
    B->val = 2;
    C->val = 13;
    D->val = 1;
    E->val = 5;
    F->val = 6;
    
    A->prev = NULL;
    A->left = B;
    A->right = C;
    B->prev = A;
    B->left = D;
    B->right = E;
    C->prev = A;
    C->left = F;
    C->right = NULL;
    D->prev = B;
    D->left = NULL;
    E->prev = B;
    E->left = NULL;
    F->prev = C;
    F->left = NULL;
    D->right = NULL;
    E->right = NULL;
    F->right = NULL;
    
    return A;
    
    
}

//Tests if a tree is a Binary Search Tree (BST)
void testBST(Node *root)
{
    if(root == NULL)
        return;
    
    
    cout<<root->val<<" ";
    
    if(root->prev != NULL)  //Checks checks the children nodes
    {
        //Checks if the current root node's LEFT node on same level is larger
        if(root->prev->left != NULL)
            if(root->val < root->prev->left->val)
            {
                cout<<"\nIs NOT a Binary Search Tree. Its LEFT-SIBLING is larger.\n";
                return;
            }
        
        //Checks if the node to the RIGHT of current root node is smaller 
        if(root->prev->right != NULL)
            if(root->val > root->prev->right->val)
            {
                cout<<"\nIs NOT a Binary Search Tree. Its RIGHT-CHILD is larger.\n";
                return;
            }
        
        //Checks if the node to the LEFT of the current root node is larger.
        if(root->left != NULL)
            if(root->val < root->left->val)
            {
                cout<<"\nIs NOT a Binary Search Tree. Its LEFT-CHILD is larger.\n";
                return;
            }
        
        //Checks if the node to the Right of the current root node is smaller.
        if(root->right != NULL)
            if(root->val > root->right->val)
            {
                cout<<"\nIs NOT a Binary Search Tree. Its RIGHT-CHILD is larger.\n";
                return;
            }
        
    }
    else    
    {
        //Checks if the root node is smaller
        if(root->left != NULL)
            if(root->left->val > root->val)
            {
                cout<<"\nIs NOT Binary Search Tree. The ROOT's LEFT-CHILD is larger.\n";
                return;
            }
    }

    testBST(root->left);   //Traverse binary tree until left returns NULL
    
    testBST(root->right);  //Traverses binary tree until right returns NULL
    
    
}


int main(int argc, char** argv) {
    Node *root;
    
    root = createTree();
    
    testBST(root);
    
    
    return 0;
}
