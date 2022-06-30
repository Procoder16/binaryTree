#include<iostream>
#include<queue>
using namespace std;

/*
    For Pre-Order Traversal:
        1. Print the value of the root.
        2. Traverse the left side of the tree.
        3. Return back and traverse the right side of the tree.

    For In-Order Traversal:
        1. First Traverse the entire left side.
        2. On reaching the last element, print and return.
        3. Traverse the right side of the binary tree.

    For Post-Order Traversal:
        1. First Traverse the entire left and on reaching last print.
        2. Then go the right side and the at the end print the value.
        3. In the end, print the root value.   

    For Level-Order Traversal:
        !!! -> THE APPROACH I FOLLOWED HERE IS ALSO CALLED BREADTH-FIRST SEARCH(BFS) TRAVERSAL
        1. We will do with the help of queue.
        2. First we will push the root element to the queue.
        3. Then run a while loop until the queue is empty.
        4. We will print the front element.
        5. Now we will check if the left half of the node is present, then push the child to the queue
        6. Same with the right child and the proces will go on until the queue becomes empty.
*/

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

void preOrder(struct Node* root){

    if(root == NULL){
        return;
    }

    cout<<root -> data<<" ";
    preOrder(root -> left);
    preOrder(root -> right);
}

void inOrder(struct Node* root){

    if(root == NULL){
        return;
    }

    inOrder(root -> left);
    cout<<root-> data<<" ";
    inOrder(root -> right);
}

void postOrder(struct Node* root){

    if(root == NULL){
        return;
    }

    postOrder(root -> left);
    postOrder(root -> right);
    cout<<root -> data<<" ";
}

void levelOrder(Node* root){

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* f = q.front();
        q.pop();
        cout<<f -> data<<" ";

        if(f -> left){
            q.push(f -> left);
        }
        if(f -> right){
            q.push(f -> right);            
        }
    }
}

int main(){

    struct Node* root = new Node(12);

    root -> left = new Node(34);
    root -> right = new Node(45);

    root -> left -> left = new Node(78);
    root -> left -> right = new Node(89);

    root -> right -> left = new Node(65);
    root -> right -> right = new Node(77);

    /*
                12
              /   \
             34    45 
            / \   / \
           78 89 65 77
    */

    cout<<"PREORDER TRAVERSAL: ";
    preOrder(root);
    cout<<"\nINORDER TRAVERSAL: ";
    inOrder(root);
    cout<<"\nPOSTORDER TRAVERSAL: ";
    postOrder(root);
    cout<<"\nLEVEL ORDER TRAVERSAL: ";
    levelOrder(root);

    return 0;
}