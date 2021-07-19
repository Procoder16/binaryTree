#include<iostream>
#include<queue>

/*
    The approach is a top-down approach and would be implemented as follows:
        > First we will be checking whether the root is NULL, if yes, return NULL.
        > Then we will check whether the root data is equals to the value a or b, if yes, it would return the obtained value.
        > If not, we will call the recursive function for the left and right subsequently.
        > And then we will again check whether both the nodes are not equals to NULL or not, if true, that is the only answer.
        > If any one is not NULL, then return that.
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

    if(leftans == NULL && rightans == NULL){  // if both the recursive calls for that particular node is NULL
        return NULL;
    }

    if(leftans != NULL && rightans != NULL){  // if both are not NULL (this is the final answer)
        return root;
    }

    if(leftans!= NULL){ // if any of the two is not NULL, then return that particular node
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
    
    int a = 8, b = 5;

    cout<<lca(root, a, b) -> data;


   return 0;
}
