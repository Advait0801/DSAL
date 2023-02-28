/*
Create an inordered threaded binary search tree. Perform inorder, preorder
traversals without recursion and deletion of a node. Analyze time and
space complexity of the algorithm.

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
    Node(int i){
        this -> data = i;
        this -> left = nullptr;
        this -> right = nullptr;
        this -> rightThread = false;
    }

    friend class TBST;
};

class TBST{
    Node *root;

public:
    TBST(int i){
        this -> root = new Node(i);
    }

    void insert(int i){
        Node *current = root;
        Node *previous = nullptr;

        while(current!=nullptr){
            previous = current;
            if(i < current -> data){
                current = current -> left;
            }
            else{
                current = current -> right;
            }
        }

        if(i < previous -> data){
            Node *newnode = new Node(i);
            previous -> left = newnode;
            newnode -> right = previous;
            newnode -> rightThread = true;
        }
        else{
            Node *newnode = new Node(i);
            newnode -> right = previous -> right;
            newnode -> rightThread = previous -> rightThread;
            previous -> rightThread = false;
            previous -> right = newnode;
        }
    }


};