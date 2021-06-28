#include<iostream>
#include<queue>
using namespace std;

/*
    The approach to be followed here is very naive:
        > Since we have to build a balanced tree, we would find the mid element of the array;
        > Create a node out of it.
        > Then for its left subtree, call the recursive function with the start element as the start, and end to be mid - 1
        > Similarly for the right subtree, call the recursive function with start as mid + 1 and end as end itself
        > the base case would be if start becomes greater than end 
*/
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

Node* buildTreeFromArray(int arr[], int start, int end){
    if(start > end){
        return NULL;
    }
    int mid = (start + end)/2;
    Node* root = new Node(arr[mid]);
    root -> left = buildTreeFromArray(arr, start, mid - 1);
    root -> right = buildTreeFromArray(arr, mid+1, end);

    return root;
}

void modifiedBFS(Node* root){
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

int main(){

    int arr[] = {2,1,6,4,3,7,8,10};
    modifiedBFS(buildTreeFromArray(arr, 0, 7));
    return 0;
}