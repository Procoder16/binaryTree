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

bool getPath(Node* root, int val, vector<int> &ans){
    if(root == NULL){
        return false;
    }
    ans.push_back(root -> data);
    if(root -> data == val){
        return true;
    }

    if(getPath(root -> left, val, ans) || getPath(root -> right, val, ans)){
        return true;
    }

    ans.pop_back();
    return false;
}

void rootToNode(Node* root, int val){
    vector<int> ans;
    if(root == NULL){
        cout<<"TREE EMPTY!";
    }
    getPath(root, val, ans);

    cout<<"THE PATH TO THE NODE IS:\n";
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}

int main(){

    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(4);

    root -> left -> right = new Node(5);
    root -> left -> right -> left = new Node(6);
    root -> left -> right -> right = new Node(7);

    root -> right = new Node(3);

    int n;
    cout<<"ENTER THE NODE VALUE:";
    cin>>n;

    rootToNode(root, n);

    return 0;
}