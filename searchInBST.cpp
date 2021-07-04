#include<iostream>
#include<queue>
using namespace std;

/*
    The approach is very simple:
        > Check if the root is NULL, is yes, that means we have reached the end of the tree without getting the NODE, so return false.
        > If the root -> data == the number given, return true;
        > else recursively search for the element in the tree's left if the node to be searched is less than the root.
        > else, search in the right part of the tree. 
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

bool searchInBST(Node* root, int t){
    if(root == NULL){
        return false;
    }
    if(root -> data == t){
        return true;
    }

    if(t <= root -> data){
        return searchInBST(root -> left, t);
    }
    else{
        return searchInBST(root -> right, t);
    }
}

int main(){
    Node* root = build();
    cout<<"THE TREE LOOKS LIKE THIS:"<<endl;
    bfs(root);
    cout<<endl;
    int t;
    cout<<"ENTER THE NODE TO SEARCH:";
    cin>>t;
    cout<<endl;
    if(searchInBST(root, t)){
        cout<<"NODE FOUND!!!";
    }
    else{
        cout<<"NODE NOT PRESENT!!!";
    }

    return 0;
}