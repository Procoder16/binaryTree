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

int isValidBSTHelper(Node* root, int min, int max){
    if(root == NULL){
        return 1;
    }
    if(root -> data < min || root -> data > max){
        return 0;
    }

    return isValidBSTHelper(root -> left, min, root -> data -1) && isValidBSTHelper(root -> right, root -> data + 1, max);
}

int isValidBST(Node* root){
    return isValidBSTHelper(root, INT_MIN, INT_MAX);
}

int main(){

    Node* root1 = new Node(10);
    root1 -> left = new Node(6);
    root1 -> left -> left = new Node(2);
    root1 -> left -> right = new Node(7);
    root1 -> right = new Node(13);
    root1 -> right -> left = new Node(11);
    root1 -> right -> right = new Node(16);

    Node* root2 = new Node(3);
    root2 -> left = new Node(2);
    root2 -> right = new Node(6);
    root2 -> left -> left = new Node(1);
    root2 -> left -> right = new Node(4);
    root2 -> right -> left = new Node(2);
    root2 -> right -> right = new Node(8);

    cout<<"VALIDITY OF THE BST-1 : "<<isValidBST(root1)<<endl;
    cout<<"VALIDITY OF THE BST-2 : "<<isValidBST(root2);

    return 0;
}