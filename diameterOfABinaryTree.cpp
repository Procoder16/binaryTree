#include<iostream>
using namespace std;

/*  The diameter of a binary tree may be defined as the longest distance between any two leaf nodes of the tree.
    The approach would be quite simple where we will do the following things:
        There could be three possibilities:
            -> The diameter passes through the root
                > For this recursively call find the height of the left and the right subtree, and then add them and store in op1
            -> The diameter lies in the left subtree
                > For this recursively call the diameter calculation function and store the value in op2
            ->The  diamater lies in the right subtree
                > For this do the same recursive calling for the diameter of right subtree and store the value in op3       

        After all these, we have to find the max of op1, op2, op3                
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

int heightOfBinaryTree(Node* root){
    if(root == NULL){
        return 0;
    }

    return max(heightOfBinaryTree(root -> left), heightOfBinaryTree(root -> right)) + 1;
}

int calcDiameter(Node* root){

    if(root == NULL){
        return 0;
    }

    int h1 = heightOfBinaryTree(root -> left);
    int h2 = heightOfBinaryTree(root -> right);

    int op1 = h1 + h2;

    int op2 = calcDiameter(root -> left);
    int op3 = calcDiameter(root -> right);

    return max(op1, max(op2, op3));
}

int main(){

    struct Node* root = new Node(1);

    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    root -> left -> left -> left = new Node(8);    
    /*
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
          /
         8  
    */

    cout<<calcDiameter(root);

    return 0;
}