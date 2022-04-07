#include<bits/stdc++.h>
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

int calculationPathSum(Node* root, int &maxSum){
    if(root == NULL){
        return 0;
    }

    int leftSum = max(0, calculationPathSum(root -> left, maxSum));
    int rightSum = max(0, calculationPathSum(root -> right, maxSum));

    maxSum = max(maxSum, leftSum + rightSum + root -> data);

    return (root -> data + max(leftSum, rightSum));
}

int maxPathSum(Node* root){
    int maxSum = INT_MIN;
    calculationPathSum(root, maxSum);
    return maxSum;
}

int main(){

    Node* root = new Node(-10);
    root -> left = new Node(9);
    root -> right = new Node(20);
     
    root -> right -> left = new Node(15);
    root -> right -> right = new Node(7);

    cout<<"MAXIMUM PATH SUM OF THE GIVEN BINARY TREE:"<<maxPathSum(root); 

    return 0;
}