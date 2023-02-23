#include <iostream>
#include "Queue.cpp"
#include "Stack.cpp"
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

    Node *getroot(){
        return this -> root;
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

    void displayInorder(){
        Stack <Node *> s;
        Node *current = this -> root;

        while(!s.isEmpty() || current!=nullptr){
            //Reach the left most node of the current node
            //Push each left node into the stack
            while(current!=nullptr){
                s.push(current);
                current = current -> left;
            }

            //current is null so pop the stack and print the data
            current = s.gettop();
            s.pop();

            cout<<current -> data<<" ";

            //now check the right part
            current = current -> right;
        }
    }

    void displayPreorder(){
        Stack <Node *> s;
        s.push(this -> root);
        Node *current = nullptr;

        while(!s.isEmpty()){
            current = s.gettop();
            cout<<current -> data<<" ";
            s.pop();

            //now push right child first and then left so that pop time, left comes first 
            if(current -> right != nullptr){
                s.push(current -> right);
            }
            if(current -> left != nullptr){
                s.push(current -> left);
            }
        }
    }

    void displayPostorder(){
        Stack <Node *> s1,s2;
        s1.push(this -> root);
        Node *current = nullptr;

        while(!s1.isEmpty()){
            //pop the top element of first stack and push it into the second stack
            current = s1.gettop();
            s2.push(current);
            s1.pop();

            //now push left child first into s1 and then right so while pop it will go in postorder
            if(current -> left != nullptr){
                s1.push(current -> left);
            }
            if(current -> right != nullptr){
                s1.push(current -> right);
            }
        }

        //now all the nodes of the tree are traversed
        //now the stack s2 is in postorder reversed
        //so pop and display each element
        
        while(!s2.isEmpty()){
            current = s2.gettop();
            cout<<current -> data<<" ";
            s2.pop();
        }
    }

    void displayPostorder(Node *node){
        if(node == nullptr){
            return;
        }
        
        displayPostorder(node -> left);
        displayPostorder(node -> right);
        cout<<node -> data<<" ";
    }
    int height(Node* node){
        if(root == nullptr){
            return -1;
        }
        int left = height(node->left);
        int right = height(node->right);
        int count;

        if(left>=right){
            count = left + 1;
        }
        else{
            count = right + 1;
        }
        return count;
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
    b.displayPostorder(root);
    cout<<endl;
    b.displayPostorder();

    return 0;
}