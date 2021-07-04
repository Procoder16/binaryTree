#include<iostream>
#include<queue>
using namespace std;


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