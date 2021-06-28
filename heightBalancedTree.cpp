#include<bits/stdc++.h>

/*
    The naive approach could be the top down approach:
        > we will start with the root element
        > we will calculate the left height of the tree and the right height of the tree
        > if the difference is lesser than or equals to zero, continue to the next, else return false there only        
*/

using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int data;

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

    return (max(heightOfBinaryTree(root -> left), heightOfBinaryTree(root -> right)) + 1);
}

bool heightBalanced(Node* root){

    if (root == NULL){
        return true;
    }

    int h1 = heightOfBinaryTree(root -> left);
    int h2 = heightOfBinaryTree(root -> right);

    if(abs(h1 - h2) <= 1){
        heightBalanced(root -> left);
        heightBalanced(root -> right);
    }

    else{
        return false;
    }
}

int main(){

    Node* root = new Node(1);

    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> left -> left -> left = new Node(8);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    /*
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
          /
         8  
    */

   cout<<heightBalanced(root);

   return 0;
}