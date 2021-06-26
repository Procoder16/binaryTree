#include<iostream>
#include<queue>

/*
    THIS CAN BE CONSIDERED AS A FOLLOW UP FOR THE LEVEL ORDER BFS TRAVERSAL AND PRINTING
        !?! HERE WE WOULD BE PRINTING THE ELEMENTS OF THE TREE LEVEL WISE IN A SEPARATE LINE

    APPROACH:
        > We would again be taking help of the queue to achieve this.
        > We will push the root element of the tree and then a NULL.
        > We would run a while loop until the queue is empty.
        > If the front element is not NULL, 
            -> print the data of the node.
            -> chech if it has the left part, if yes, push it to the queue.
            -> check the same for the right part as well.
        > If the front element is NULL, it signifies a level has ended
            -> and if the queue is not empty, push another NULL signifying the end of the last level
            -> add endline so that the next level is on the next line         
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
        else if(!q.empty()){
            q.push(NULL);
            cout<<endl;
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

   modifiedBFS(root);

   return 0;
}
