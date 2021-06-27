#include<iostream>
#include<queue>

/*
    > The approach we would be following here is bottom-up approach(Postorder)
    > The tricky part here is
        -> when we are passing on the sum of a node to its parent, we also need to pass that particular node's data
        -> so, we will store that in a temporary variable and then change that node's value with right and left sum
        -> when you are returning, return the calculated sum plus the temp value
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
        else{
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
}

int sumReplacement(Node* &root){

    if(root == NULL){
        return 0;
    }

    if(root -> left == NULL && root -> right == NULL){
        return root -> data;
    }

    int leftSum = sumReplacement(root -> left);
    int rightSum = sumReplacement(root -> right);

    int temp = root -> data;
    root -> data = leftSum + rightSum;
    return root -> data + temp;
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
   cout<<endl;
   cout<<sumReplacement(root)<<endl;
   cout<<endl;
   modifiedBFS(root);

   return 0;
}