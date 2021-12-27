#include<bits/stdc++.h>
using namespace std;

/*
    *One may think that for each node we would check whether the right child is greater and the left child is smaller or not.
    But the logic is not correct. According to the definition of BST, all the nodes in the left subtree should be smaller and
    vice versa for the right subtree. So, if we apply this logic, the binary tree - 2 below would also return true but that
    is not a valid BST.

    *So one of the correct approaches would be two first store the inorder traversal of the tree in an array and then check
    whether the tree is sorted in ascending order or not. If yes, then it is a BST or else, NO.
    This approach has a time complexity of O(n) and a space complexity of O(n) too.

    *So we can have a much better and space-optimal solution for the same:
        *) We will be using a helper function that takes the node, min variable and max variable as the parameters.
        *) At the validBST function we will be calling the helper function with the root, INT_MIN, INY_MAX passed as the arguments.
        *) At the helper function we will check whether the root is NULL or not as the base condition.
        *) Then we would check whether the root -> data is less than min or the more than max. If yes, return false.
        *) Else we would be calling the function recursively for the left and the right subtree with paratameters as follows:
            -> for left, min should be the min itself but the max should be root data - 1
            -> for right, min should be root -> data + 1 and the max would be max only
    The basic idea is we are setting a max and min value for each node and the subnodes respectively. Why??? Because the modes 
    in the left subtree can have a max value of root -> data -1 and the right subtree can have a min value of root -> data + 1           
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

int isValidBSTHelper(Node* root, int min, int max){
    if(root == NULL){
        return 1;
    }
    if(root -> data < min || root -> data > max){
        return 0;
    }

    return isValidBSTHelper(root -> left, min, root -> data -1) && isValidBSTHelper(root -> right, root -> data + 1, max);
}

int isValidBST(Node* root){
    return isValidBSTHelper(root, INT_MIN, INT_MAX);
}

int main(){

    Node* root1 = new Node(10);
    root1 -> left = new Node(6);
    root1 -> left -> left = new Node(2);
    root1 -> left -> right = new Node(7);
    root1 -> right = new Node(13);
    root1 -> right -> left = new Node(11);
    root1 -> right -> right = new Node(16);

    Node* root2 = new Node(3);
    root2 -> left = new Node(2);
    root2 -> right = new Node(6);
    root2 -> left -> left = new Node(1);
    root2 -> left -> right = new Node(4);
    root2 -> right -> left = new Node(2);
    root2 -> right -> right = new Node(8);

    cout<<"VALIDITY OF THE BST-1 : "<<isValidBST(root1)<<endl;
    cout<<"VALIDITY OF THE BST-2 : "<<isValidBST(root2);

    return 0;
}