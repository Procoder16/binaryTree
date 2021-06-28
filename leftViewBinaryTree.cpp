#include<iostream>
#include<queue>

/*
    This question can be solved in various methods, out of which we are gonna look into BFS and DFS approach
    So the BFS approach goes something like this:
        > We would follow the same algorithm that we followed for the level order traversal
        > We will use a queue and push the root and a NULL first.
        > Print the data of the root node.
        > Run a loop until the queue becomes empty
        > We will store the front node of the queue in a temp node and then we pop the front node.
        > If the front node is not NULL
            -> check for its left and right subtree respectively
            -> if present push them to the queue.
        > If the front node is NULL
            -> we print the data of the front node (which is now the next element after the NULL was popped)
            -> if the queue is still not empty, push another NULL to the queue             
*/

using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int data;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void leftViewBFS(Node* root){

    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    cout<<root -> data<<" ";
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        int prevVal;
        if(temp != NULL){
            prevVal = temp -> data;
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
        else{
            if(!q.empty()){
                cout<<q.front() -> data<<" ";
                q.push(NULL);
            }
        }
    }

}

void leftViewDFS(Node* root, int level, int &maxlevel){  
    // we are using reference so that we have the latest max level everytime

    if(root == NULL){
        return;
    }

    if(level > maxlevel){
        cout<<root -> data<<" ";
        maxlevel = level;
    }
    leftViewDFS(root -> left, level + 1, maxlevel);  
    // calling for the left first because we need the left view here
    leftViewDFS(root -> right, level + 1, maxlevel);
}

int main(){

    Node* root = new Node(1);

    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> left -> left -> left = new Node(8);

    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    /*
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
          /
         8  
    */

   //leftViewBFS(root);
   int maxlevel = -1;
   leftViewDFS(root, 0, maxlevel);

   return 0;
}
