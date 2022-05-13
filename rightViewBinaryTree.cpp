// Right view of a binary tree solution added

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

    Now, the DFS approach goes something like this:
        >  first of all the function itself accepts three values, the root node, current level and the max level
        > we pass the current level as 1 and max level as -1 bacause we know the root has to be printed in any case
        > now we check the base case, and then check whether the current level is greater than the max level
            -> if yes, print the data of the node and assign max level with the value of the level
        > now, since we need to print the right view, we call the recursive function first for the right view and then for the left view                       
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

void rightViewDFS(Node* root, int level, int &maxlevel){  
    // we are using reference so that we have the latest max level everytime

    if(root == NULL){
        return;
    }

    if(level > maxlevel){
        cout<<root -> data<<" ";
        maxlevel = level;
    }
    rightViewDFS(root -> right, level + 1, maxlevel);  // calling for the right first because we need the right view here
    rightViewDFS(root -> left, level + 1, maxlevel);
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

   //rightViewBFS(root);
   int maxlevel = -1;
   rightViewDFS(root, 0, maxlevel);

   return 0;
}
