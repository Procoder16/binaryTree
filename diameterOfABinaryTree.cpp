#include<iostream>
using namespace std;

/*  The diameter of a binary tree may be defined as the longest distance between any two leaf nodes of the tree.
    The approach would be quite simple where we will do the following things:
        > call a recursive function to calculate the diameter and also the height for the left and repeat the same for the right side also.
        > find the max of the two and,
            -> if the diameter is through the root, add 1, else no need 
        
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

int calcDiameter(Node* root){

    
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