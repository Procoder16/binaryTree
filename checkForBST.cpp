#include<iostream>
#include<queue>
#include<climits>
using namespace std;

/*
    This is an easy question but the approach shouldn't be as simple as we think.
    >> If we think of an approach something like this:
        >> Check the root value if it is greater than or equals to the left root and smaller than right root.
        >> And then check for the left subtree and the right subtree.
        >> THEN THIS WOULD BE WRONG, as there can be an element in the right subtree with a number smaller than the root and vice - versa.
    >> The approach we should follow here is:
        >> We would first start with a minV equals to negative infinity and maxV equals to maximum infinity.
        >> Then check for the root value if it is smaller than or equals to minV and greater than equals to maxV.
        >> Also check for the left subtree and right subtree with parameters minV - root data and root - maxV respectively.
        >> Else return false.     
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

bool checkBST(Node* root, int minV = INT_MIN, int maxV = INT_MAX){
    if(root == NULL){
        return true;
    }
    if(root -> data >= minV && root -> data <= maxV && checkBST(root -> left, minV, root -> data) && checkBST(root -> right, root -> data, maxV)){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    Node* root = new Node(5);
    root -> left = new Node(6);
    root -> right = new Node(7);
    root -> left -> left = new Node(1);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(8);
    cout<<"THE TREE LOOKS SOMETHING LIKE THIS:"<<endl;
    bfs(root);
    cout<<endl;
    if(checkBST(root)){
        cout<<"THE TREE IS A BINARY SEARCH TREE!";
    }
    else{
        cout<<"THE TREE IS NOT A BINARY SEARCH TREE!";
    }
    return 0;
}