#include<iostream>
using namespace std;

/*
    Approach:
        1. Start from the end of PostOrder and select an element to create the node
        2. Decrement the postorder idx 
        3. Search for picked element's pos in inorder
        4. Call to build the right subtree of the inorder's pos + 1 to end.
        5. Call to build the left subtree of the inorder's start to pos - 1;
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

void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root -> left);
    cout<<root -> data<<" ";
    printInorder(root -> right);    
}

Node* buildTree(int postorder[], int inorder[], int start, int end){

    static int idx = 4;

    if(start > end){
        return NULL;
    }

    int curr = postorder[idx];
    idx--;

    Node* node = new Node(curr);
    if(start == end){
        return node; 
    }
    int pos = search(inorder, start, end, curr);

    node -> right = buildTree(postorder, inorder, pos + 1, end);
    node -> left = buildTree(postorder, inorder, start, pos -1);

    return node;
}

int main(){

    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3}; 

    Node* root = buildTree(postorder, inorder, 0, 4);

    printInorder(root);
    cout<<endl;

    return 0;
}