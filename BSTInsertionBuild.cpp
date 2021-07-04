#include<iostream>
#include<queue>
using namespace std;

/*
    Here we will be writing two function for the build operation:
        1. The first function is build itself where we are going to build the tree:
            > We will first take an input of a number and create a NULL root.
            > And then run a loop until we encounter -1 which marks NULL here.
            > And then we will call the recursive function for the root with the value and store the returned value in the root.
            > Finally return the root.
        2. This is the recursive function of the build operation.
            > Remember the new node will always be created and assigned to a position of NULL.
            > we will check if the value from the function is less than or equal to the root val, then call the rec function for the left of root.
            > else call for the right of the root.
            > and if the root becomes NULL while traversing, that is the position where we are going to insert the new node. 
*/


struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void bfs(Node* root){
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

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root -> left);
    cout<<root -> data<<" ";
    inorder(root -> right);
}

Node* insertInBST(Node* root, int d){

    if(root == NULL){
        return new Node(d);
    }

    if(d <= root -> data){
        root -> left = insertInBST(root -> left, d);
    }
    else{
        root -> right = insertInBST(root -> right, d);
    }

    return root;
}

Node* build(){

    int d;
    cin>>d;

    Node* root = NULL;

    while(d!=-1){
        root = insertInBST(root, d);
        cin>>d;
    }
    return root;
}

int main(){

    Node* root = build();
    inorder(root);
    cout<<endl;
    bfs(root);
}