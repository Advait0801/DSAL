#include <iostream>
using namespace std;

class Node{
    int data;
    Node *left , *right;

public:
    Node(int i){
        this -> data = i;
        this -> left = nullptr;
        this -> right = nullptr;
    }

    friend class BT;
};

class BT{
    Node *root;
    int height;

public:
    BT(){
        this -> root = nullptr;
        this -> height = 0;        
    }

    ~BT(){
        destroy(this -> root);
        this -> height = 0;
    }

    void destroy(Node *node){
        if(node != nullptr){
            destroy(node -> left);
            destroy(node -> right);
            delete node;
        }
    }

    Node *getroot(){
        return this -> root;
    }

    void insert(int item){
        if(root==nullptr){
            root = new Node(item);
        }

        else{
            Node *current = root;
            Node *previous = nullptr;
            Node *newnode = new Node(item);

            while(true){
                previous = current;
                current = current -> left;
                if(current==nullptr){
                    previous -> left = newnode;
                }
            }
        }
    }
};