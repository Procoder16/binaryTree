#include<iostream>
#include<queue>

/*
    This question can be solved in various methods, out of which we are gonna look into BFS and DFS approach
    So the BFS approach goes something like this:
        > We would follow the same algorithm that we followed for the level order traversal
        > We will use a queue and push the root and a NULL first.
        > Run a loop until the queue becomes empty
        > We will store the front node of the queue in a temp node and then we pop the front node.
        > If the front node is not NULL
            -> store the data of the node in a variable
            -> check for its left and right subtree respectively and if present, push them to the queue
        > If the front node is NULL
            -> we print the last value that was stored in the variable
            -> if the queue is still not empty, push another NULL to it             
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

void rightViewBFS(Node* root){

    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

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
            cout<<prevVal<<" ";
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }

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

   rightViewBFS(root);

   return 0;
}
