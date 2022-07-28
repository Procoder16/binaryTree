#include<iostream>
#include<stack>
#include<vector>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isLeaf(Node* node){
    if(node -> left == NULL && node -> right == NULL){
        return true;
    }
    return false;
}

void leftBoundary(Node* root, vector<int> &traversal){
    Node* curr = root;
    while(curr){
        if(!isLeaf(curr)){
            traversal.push_back(curr -> data);
        }
        if(curr -> left){
            curr = curr -> left;
        }
        else{
            curr = curr -> right;
        }
    }
}

void leafNodes(Node* root, vector<int> &traversal){
    if(isLeaf(root)){
        traversal.push_back(root -> data);
    }
    if(root -> left){
        leafNodes(root -> left, traversal);
    }
    if(root -> right){
        leafNodes(root -> right, traversal);
    }
}

void rightBoundary(Node* root, vector<int> &traversal){
    stack<int> st;
    Node* curr = root;
    while(curr){
        if(!isLeaf(curr)){
            st.push(curr -> data);
        }
        if(curr -> right){
            curr = curr -> right; 
        }
        else{
            curr = curr -> left;
        }
    }
    while(!st.empty()){
        traversal.push_back(st.top());
        st.pop();
    }
}

void boundaryTraversal(Node* root){
    vector<int> boundaryTraversal;
    boundaryTraversal.push_back(root -> data);
    leftBoundary(root -> left, boundaryTraversal);
    leafNodes(root, boundaryTraversal);
    rightBoundary(root -> right, boundaryTraversal);

    cout<<"BOUNDARY TRAVERSAL:\n";
    for(int i = 0; i < boundaryTraversal.size(); i++){
        cout<<boundaryTraversal[i]<<" ";
    }
}

int main(){

    Node* root = new Node(1);

    root -> left = new Node(2);
    root -> right = new Node(7);

    root -> left -> left = new Node(3);
    root -> left -> right = new Node(4);

    root -> left -> right -> left = new Node(5);
    root -> left -> right -> right = new Node(6);

    boundaryTraversal(root);

    return 0;
}