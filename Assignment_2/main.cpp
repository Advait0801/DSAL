#include <iostream>
#include "Queue.cpp"
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
    Queue <Node*> q;

public:
    BT(){
        this -> root = nullptr;
    }

    void insert(int item){
        if(root == nullptr){
            root = new Node(item);
            q.push(root);
        }

        else{
            Node *newnode = new Node(item);
            Node *current = q.getfront();

            while(true){
                if(current -> left!=nullptr && current -> right!=nullptr){
                    q.push(current -> left);
                    q.push(current -> right);
                    q.pop();
                    current = q.getfront();
                }

                else if(current -> left == nullptr){
                    current -> left = newnode;
                    break;
                }

                else{
                    current -> right = newnode;
                    break;
                }
            }
        }
    }

    Node *getroot(){
        return this -> root;
    }

    void displayPreorder(Node *node){
        if(node == nullptr){
            return;
        }

        cout<<node -> data<<" ";
        displayPreorder(node -> left);
        displayPreorder(node -> right);
    }

};

int main(){
    BT b;
    b.insert(45);
    b.insert(37);
    b.insert(67);
    b.insert(89);
    b.insert(56);
    b.insert(12);

    Node *root = b.getroot();
    b.displayPreorder(root);

    return 0;
}