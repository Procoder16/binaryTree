#include<iostream>
#include<queue>

/*
             
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

// assuming both a and b are present in the tree and all keys are unique
Node* lca(Node* root, int a, int b){
    if(root == NULL){
        return NULL;
    }

    if(root -> data == a || root -> data == b){
        return root;
    }

    // now searching in the subtrees

    Node* leftans = lca(root -> left, a, b);
    Node* rightans = lca(root -> right, a, b);

    if(leftans != NULL && right != NULL){
        return root;
    }

    if(leftans!= NULL){
        return leftans;
    }
    return rightans;
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
    
    int a = 8, b = 7;

    cout<<lca(root, a, b) -> data;


   return 0;
}
