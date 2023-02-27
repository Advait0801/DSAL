/*
Create an inordered threaded binary search tree. Perform inorder, preorder 
traversals without recursion and deletion of a node. Analyze time and space 
complexity of the algorithm.

Name : Advait Naik
Roll No : 21354
*/

#include <iostream>
using namespace std;

class Node{
    int data;
    Node *left , *right;
    bool rightThread;

public:
    friend class TBT;
};

class TBT{
    Node *root;

public:
    TBT(){
        this -> root = nullptr;
    }

    
};