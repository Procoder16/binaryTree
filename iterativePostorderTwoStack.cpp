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

void iterativePostorder(Node* root){
    stack<Node*> st1;
    stack<Node*> st2;

    st1.push(root);
    while(!st1.empty()){
        st2.push(st1.top());
        st1.pop();
        if(st2.top() -> left != NULL){
            st1.push(st2.top() -> left);
        }
        if(st2.top() -> right != NULL){
            st1.push(st2.top() -> right);
        }
    }

    while(!st2.empty()){
        cout<<st2.top() -> data<<" ";
        st2.pop();
    }
}

int main(){

    Node* root = new Node(1);

    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right -> left = new Node(6);
    root -> right -> left -> right = new Node(7);

    root -> right -> left -> right -> right = new Node(8);

    iterativePostorder(root);

    return 0;
}