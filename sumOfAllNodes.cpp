#include<iostream>
using namespace std;

/*
    Approach:
        > We will call the recursive function for the left subtree and add it to the recursive function sum of right subtree.
        > Add the root value to the obtained sum.
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

int sumOfAllNodes(Node* root){

    if(root == NULL){
        return 0;
    }
    return sumOfAllNodes(root -> left) + sumOfAllNodes(root -> right) + root -> data;

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

    cout<<sumOfAllNodes(root);

    return 0;
}