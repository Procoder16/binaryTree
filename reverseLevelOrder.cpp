#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
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

    Node* temp;

    while(!q.empty()){
        temp = q.front();
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

void reverseLevelOrder(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    stack<Node*> s;

    q.push(root);
    q.push(NULL);
    
    Node* temp;

    while(!q.empty()){
        temp = q.front();
        q.pop();
        s.push(temp);

        if(temp != NULL){
            if(temp -> right){
                q.push(temp -> right);
            }
            if(temp -> left){
                q.push(temp -> left);
            }
        }
        else{
            if(!q.empty()){
                q.push(NULL);
            }            
        }       
    }

    while(!s.empty()){
        Node* tempVal = s.top();
        if(tempVal == NULL){
            cout<<endl;
            s.pop();
        }
        else{
            cout<<tempVal -> data<<" ";
            s.pop();
        }        
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

    cout<<"THE TREE LOOKS SOMETHING LIKE THIS:"<<endl;
    bfs(root);

    cout<<"THE LEVEL ORDER TRAVERSAL IN REVERSE ORDER WOULD BE:";
    reverseLevelOrder(root);

    return 0;
}