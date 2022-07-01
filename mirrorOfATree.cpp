#include<iostream>
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

void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root -> left);
    cout<<root -> data<<" ";
    printInorder(root -> right);
}

void mirrorTree(Node* root){
    if(root == NULL){
        return;
    }
    if(root -> left == NULL && root -> right == NULL){
        return;
    }

    Node* l = root -> left;
    Node* r = root -> right;

    root -> left = r;
    root -> right = l;

    mirrorTree(root -> left);
    mirrorTree(root -> right);
}

int main(){

    struct Node* root = new Node(5);
    root -> left = new Node(3);
    root -> right = new Node(6);

    root -> left -> left = new Node(2);
    root -> left -> right = new Node(4);

    cout<<"INORDER TRAVERSAL BEFORE MIRROR EFFECT:\n";
    printInorder(root);

    mirrorTree(root);

    cout<<"\nINORDER TRAVERSAL AFTER MIRROR EFFECT:\n";
    printInorder(root);

    return 0;
}