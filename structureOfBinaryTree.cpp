#include<iostream>
using namespace std;

/*
    For Pre-Order Traversal:
        1. Print the value of the root.
        2. Traverse the left side of the tree.
        3. Return back and traverse the right side of the tree.

    For In-Order Traversal:
        1. First Traverse the entire left side.
        2. On reaching the last element, print and return.
        3. Traverse the right side of the binary tree.

    For Post-Order Traversal:
        1. First Traverse the entire left and on reaching last print.
        2. Then go the right side and the at the end print the value.
        3. In the end, print the root value.        
*/

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preOrder(struct Node* root){

    if(root == NULL){
        return;
    }

    cout<<root -> data<<" ";
    preOrder(root -> left);
    preOrder(root -> right);
}

void inOrder(struct Node* root){

    if(root == NULL){
        return;
    }

    inOrder(root -> left);
    cout<<root-> data<<" ";
    inOrder(root -> right);
}

void postOrder(struct Node* root){

    if(root == NULL){
        return;
    }

    postOrder(root -> left);
    postOrder(root -> right);
    cout<<root -> data<<" ";
}

int main(){

    struct Node* root = new Node(1);

    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    /*
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
    */

    //preOrder(root);
    //inOrder(root);
    postOrder(root);

    return 0;
}