#include<bits/stdc++.h>

/*
    The naive approach could be the top down approach:
        > we will start with the root element
        > we will calculate the left height of the tree and the right height of the tree
        > if the difference is lesser than or equals to zero, continue to the next, else return false there only  
    The optimal approach would be the bottom up approach where we follow the postorder traversal.
        > Here, we are making a self defined pair with a class and the two data members are height and balance
        > The base case, when the root is NULL, we can make the pair's height = 0 and balance = true.
        > Coming to the recursive part:
            -> Traverse upto the last leaf node
            -> Now move up returning values gradually 
            -> If both the height of the children nodes are obeying the condition and both the nodes are returning true from the last level
            -> Then the balance for this node would also be true.          
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

// int heightOfBinaryTree(Node* root){

//     if(root == NULL){
//         return 0;
//     }

//     return (max(heightOfBinaryTree(root -> left), heightOfBinaryTree(root -> right)) + 1);
// }

// bool heightBalanced(Node* root){

//     if (root == NULL){                                 NAIVE APPROACH WITH A COMPLEXITY OF O(n^2)
//         return true;
//     }

//     int h1 = heightOfBinaryTree(root -> left);
//     int h2 = heightOfBinaryTree(root -> right);

//     if(abs(h1 - h2) <= 1){
//         heightBalanced(root -> left);
//         heightBalanced(root -> right);
//     }

//     else{
//         return false;
//     }
// }

class HBPair{
    public:
    int height;
    bool balance;
};

HBPair isHeightBalanced(Node* root){           // O(n) approach
    HBPair p;
    if(root == NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }

    //Recursive case

    HBPair left = isHeightBalanced(root -> left);
    HBPair right = isHeightBalanced(root -> right);

    p.height = max(left.height, right.height) + 1;

    if(abs(left.height - right.height) <= 1 && left.balance && right.balance){
        p.balance = true;
    }
    else{
        p.balance = false;
    }
    return p;
}

int main(){

    Node* root = new Node(1);

    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> left -> left -> left = new Node(8);
    root -> left -> left -> left -> left = new Node(9);
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

   //cout<<heightBalanced(root);
    if(isHeightBalanced(root).balance){
        cout<<"Balanced Tree";
    }
    else{
        cout<<"Not a Balanced Tree";
    }
   return 0;
}