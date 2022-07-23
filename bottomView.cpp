//bottom view of a binary tree added
#include<iostream>
#include<queue>
#include<map>
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

void bottomView(Node* root){
    queue<pair<Node*, int>> q;
    map<int, Node*> m;

    q.push({root, 0});

    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        int d = temp.second;
        if(temp.first -> left){
            q.push({temp.first -> left, d-1});
        }
        if(temp.first -> right){
            q.push({temp.first -> right, d+1});
        }
        m[d] = temp.first;
    }

    for(auto n : m){
        cout<<n.second -> data<<" ";
    }
}

int main(){

    Node* root = new Node(1);

    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    root -> left -> right -> left = new Node(8);
    root -> left -> right -> right = new Node(9);

    bottomView(root);

    return 0;
}