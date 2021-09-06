#include<bits/stdc++.h>
using namespace std;

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

void iterativePreorder(Node* root){
    stack<Node*> s;
    s.push(root);

    while(!s.empty()){
        Node* temp = s.top();
        s.pop();
        cout<<temp -> data<<" ";
        if(temp -> right != NULL){
            s.push(temp -> right);
        }
        if(temp -> left != NULL){
            s.push(temp -> left);
        }
    }
}

int main(){

    Node* root = new Node(1);

    root -> left = new Node(2);
    root -> right = new Node(7);

    root -> left -> left = new Node(3);
    root -> left -> right = new Node(4);

    root -> left -> right -> left = new Node(5);
    root -> left -> right -> right = new Node(6);

    iterativePreorder(root);

    return 0;
}