#include<iostream>
using namespace std;

/*
    Approach here is quite simple:
        1. We will call the recursive function for the left and the right separately assuming them to return the total sum.
        2. We will add 1 because we passed only left and right and the root was remaining. 
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

int countOfNodes(Node* root){
    if(root ==  NULL){
        return 0;
    }
    return countOfNodes(root -> left) + countOfNodes(root -> right) + 1;
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
             2     3        => 7
            / \   / \
           4   5 6   7
    */

    cout<<countOfNodes(root);

    return 0;
}