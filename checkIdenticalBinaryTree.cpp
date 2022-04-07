#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool checkIdentical(Node* root1, Node* root2){
    if(root1 == NULL || root2 == NULL){
        return (root1 == root2);
    }
    return root1 -> data == root2 -> data && checkIdentical(root1 -> left, root2 -> left) && checkIdentical(root1 -> right, root2 -> right);
}

int main(){

    Node* root1 = new Node(-10);
    root1 -> left = new Node(9);
    root1 -> right = new Node(20);
     
    root1 -> right -> left = new Node(15);
    root1 -> right -> right = new Node(7);

    Node* root2 = new Node(-10);
    root2 -> left = new Node(9);
    root2 -> right = new Node(20);
     
    root2 -> right -> left = new Node(15);
    root2 -> right -> right = new Node(7);

    if(checkIdentical(root1, root2)){
        cout<<"THE GIVEN TWO BINARY TREES ARE IDENTICAL";
    }
    else{
        cout<<"THE GIVEN TWO BINARY TREES ARE NOT IDENTICAL";
    }    

    return 0;
}