#include<bits/stdc++.h>
using namespace std;

/*
    The approach is pretty similar to bfs printing only but with a little variation:
        >> Here, we will be using a queue as we did in the BFS printing, also we would be using a stack since the reverse is required.
        >> While adding the nodes, in case of BFS, we added first the left child and then the right child. But, here we would push the
           right child and then the left child to the queue.
        >> And for each node we would be pushing it to the stack also even before checking for the children. We would add the stack part
           when the top element of the queue is deleted.[This is just fir remembrance and not the exact logic]     
*/

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