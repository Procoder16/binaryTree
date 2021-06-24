#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        val = data;
        left = NULL;
        right = NULL;
    }
};



int main(){

    Node* root = new Node(1);

    root -> left = new Node(2);
    root -> right = new Node(3);

    /*
                1
              /   \
             2     3
            / \   / \
             N U L L
    */

   root -> left -> left = new Node(4);
   root -> left -> right = new Node(5);

    /*
                1
              /   \
             2     3
            / \   / \
           4   5  NULL
    */

    return 0;
}