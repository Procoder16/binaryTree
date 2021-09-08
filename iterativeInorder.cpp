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

void iterativeInorder(Node* root){
    stack<Node*> st;
    Node* currNode = root;

    while(true){
        if(currNode != NULL){
            st.push(currNode);
            currNode = currNode -> left;
        }
        else{
            if(st.empty()){
                break;
            }
            currNode = st.top();
            cout<<st.top() -> data<<" ";
            st.pop();
            currNode = currNode -> right;
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

    iterativeInorder(root);

    return 0;
}