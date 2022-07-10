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

void topView(Node* root){

    queue<pair<Node*, int>> q;
    map<int, Node*> m;

    q.push({root, 0});

    while(!q.empty()){
        auto c = q.front();
        q.pop();
        int d = c.second;

        if(m.count(d) == 0){
            m.insert({d, c.first});
        }
        
        if(c.first -> left){
            q.push({c.first -> left, d - 1});
        }
        if(c.first -> right){
            q.push({c.first -> right, d + 1});
        }
    }

    for(auto n : m){
        cout<<n.second -> data<<" ";
    }
}   

int main(){

    struct Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(10);
    root -> right -> left = new Node(9);
    root -> right -> right = new Node(10);

    root -> left -> left -> right = new Node(5);
    root -> left -> left -> right -> right = new Node(6);

    topView(root);

    return 0;
}