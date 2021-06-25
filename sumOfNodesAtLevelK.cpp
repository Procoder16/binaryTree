#include<iostream>
#include<queue>
using namespace std;

/*
    For Level-Order Traversal:
        1. We will do with the help of queue.
        2. First we will push the root element.
        3. Then push a null.
        4. Then we will loop until the queue becomes empty.
        5. Approach is: 
            a. For each level we will first print the value.
            b. analyse the left and right of the node and then add them to the queue from the back.
            c. Once completed add a null again and then repeat the same. 

    For calculating the sum, we will simply keep a variable to check the level we are in and when reached, calculate the sum.
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

int sumAtK(Node* root, int k){
    if(root == NULL){
        return -1;  // sum cannot be calculated
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    int level = 0;
    int sum = 0;

    while(!q.empty()){
        Node* node = q.front();
        q.pop();

        if(node != NULL){
            if(level == k){
                sum += node -> data;
            }
            if(node -> left){
                q.push(node -> left);
            }
            if(node -> right){
                q.push(node -> right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

int main(){

    struct Node* root = new Node(1);

    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    /*
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
    */

    //preOrder(root);
    //inOrder(root);
    //postOrder(root);
    //levelOrder(root);
    cout<<sumAtK(root, 2);

    return 0;
}