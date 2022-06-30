#include<iostream>
using namespace std;

/*
    Approach:
        > We will call two recursive function, one  for the left tree and one for the right tree
        > Then we will add 1 so that the root is also added
        
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

int calcHeight(Node* root){

    if(root == NULL){
        return 0;
    }
    
    return (max(calcHeight(root -> left), calcHeight(root -> right)) + 1);

}

int main(){

    struct Node* root = new Node(1);

    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    root -> left -> left -> left = new Node(8);    
    /*
                1
              /   \
             2     3
            / \   / \
           4   5 6   7
          /
         8  
    */

    cout<<calcHeight(root);

    return 0;
}

#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
	Node(int data){
		this->data = data;
		left = right = NULL;
	}
};

bool ifNodeExists(struct Node* node, int key){
	if (node == NULL)
		return false;

	if (node->data == key)
		return true;

	bool res1 = ifNodeExists(node->left, key);
	if(res1) return true;

	bool res2 = ifNodeExists(node->right, key);

	return res2;
}

int main(){
	struct Node* root = new Node(0);
	root->left = new Node(1);
	root->left->left = new Node(3);
	root->left->left->left = new Node(7);
	root->left->right = new Node(4);
	root->left->right->left = new Node(8);
	root->left->right->right = new Node(9);
	root->right = new Node(2);
	root->right->left = new Node(5);
	root->right->right = new Node(6);

	int key = 4;

	if (ifNodeExists(root, key))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
