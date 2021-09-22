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

void modifiedBFS(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();
        if(temp != NULL){
            cout<<temp -> data<<" ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
        else{
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
}

void childSumPropertyModification(Node* root){

    if(root == NULL){
        return;
    }

    int child = 0;
    if(root -> left){
        child += root -> left -> data;
    }
    if(root -> right){
        child += root -> right -> data;
    }

    if(child >= root -> data){
        root -> data = child;
    }

    else{
        if(root -> left){
            root -> left -> data = root -> data;
        }
        if(root -> right){
            root -> right -> data  = root -> data;
        }
    }

    childSumPropertyModification(root -> left);
    childSumPropertyModification(root -> right);

    int total = 0;
    if(root -> left){
        total += root -> left -> data;
    }
    if(root -> right){
        total += root -> right -> data;
    }

    if(root -> left || root -> right){
        root -> data = total;
    }
}

int main(){

    Node* root = new Node(7);

    root -> left = new Node(6);
    root -> right = new Node(5);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(3);
    root -> right -> left = new Node(2);
    root -> right -> right = new Node(1);

    cout<<"TREE WITHOUT MODIFICATION:\n";

    modifiedBFS(root);

    childSumPropertyModification(root);

    cout<<"TREE AFTER MODIFICATION:\n";

    modifiedBFS(root);

    return 0;
}