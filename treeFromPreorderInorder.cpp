#include<iostream>
using namespace std;

/*
    Approach:
        1. Pick an element from preorder and create a node.
        2. Increment preorder idx.
        3. Search for picked element's pos in inorder
        4. Call a build left subtree from inorder's 0 to pos-1
        5. Call a build right subtree from inorder's pos+1 to n
        6. Return the node
*/

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

int search(int inorder[], int start, int end, int curr){
    for(int i = start; i <= end; i++){
        if(inorder[i] == curr){
            return i;
        }
    }
    return -1;
}

void inorderPrint(Node* root){
    if(root == NULL){
        return;
    }
    inorderPrint(root -> left);
    cout<<root -> data<<" ";
    inorderPrint(root -> right);
}

Node* buildTree(int preorder[], int inorder[], int start, int end){

    static int idx = 0; // static is made so that when the recursion is called next time, the value is updated or else it would be 0 or 1 only
    if(start > end){
        return NULL;
    }

    int curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);

    if(start == end){
        return node;
    }

    int pos = search(inorder, start, end, curr);

    node -> left = buildTree(preorder, inorder, start, pos - 1);
    node -> right = buildTree(preorder, inorder, pos + 1, end);
    return node;
}

int main(){

    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3}; 

    Node* root = buildTree(preorder, inorder, 0, 4);

    inorderPrint(root);

    return 0;
}