//Deletion of node in a BST

#include<iostream>
#include<queue>
using namespace std;

/*
    The approach goes something like this:
        > We will check whether the current node is a NULL, if yes, that means we have reached the end and hence the element is not found.
        > Then, we will check that whether the key is less than the root value, if yes, we will call the recusive function for the left subtree.
        > If found the node, there will be three cases, rather there can be three different types of nodes that can be deleted:
            -> A node with zero children:
                >> For this simply delete the node and return NULL
            -> A node with one child:
                >> First check which child is not NULL
                >> Then store the value in a temp Node
                >> delete the root(in this case)
                >> return the temp Node
            -> A  node with two children:
                >> Remember, if we directly delete this node, then there would be two different trees formed and which we do not want.
                >> So, we have to replace the value of the of a node with the root value.
                >> So now which node would be replaced, and the answer is the immediate "INORDER SUCCESSOR".
                >> So search for the immediate inorder successor in the right subtree by travering the left of the right subtree.
                >> Basically we are searching the smallest node in the right subtree.
                >> Replace the root value with that node's value.
                >> Now we have to delete that node.
                >> Now recursively call the delete node in a BST function for the right subtree(as the right subtree is going to change).
                >> The parameters to be passed are root -> right and the replace -> val        
*/

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void bfs(Node* root){
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

Node* insertInBST(Node* root, int d){
    if(root == NULL){
        return new Node(d);
    }

    if(d <= root -> data){
        root -> left = insertInBST(root -> left, d);
    }
    else{
        root -> right = insertInBST(root -> right, d);
    }

    return root;
}

Node* build(){
    int d;
    cin>>d;

    Node* root = NULL;

    while(d!=-1){
        root = insertInBST(root, d);
        cin>>d;
    }
    return root; 
}

Node* deletionInBST(Node* root, int t){
    if(root == NULL){  // base case
        return NULL;
    }

    else if(t == root -> data){
        // This is the place which states that we have found the root
        // So here we will be having 3 cases

        // Case 1:  The root has zero children
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }

        // Case 2: When the root has only one child
        if(root -> left != NULL && root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        if(root -> right != NULL && root -> left == NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        // Case 3: When the root has 2 children, here we have to replace the root with a nearest value
        // Here we will find the inorder successor of the current root.
        
        Node* replace = root -> right;
        while(replace -> left != NULL){
            replace = replace -> left;
        }
        root -> data = replace -> data;
        root -> right = deletionInBST(root -> right, replace -> data);
        return root;
                
    }
 
    else if(t < root -> data){   // is the given value is smaller than the root value
        root -> left = deletionInBST(root -> left, t);
        return root;
    }

    

    else{ // checking the right subtree
        root -> right = deletionInBST(root -> right, t);
        return root;
    }
}

Node* findLastRight(Node* root) {
    if (root->right == NULL) {
        return root;
    }
    return findLastRight(root->right);
}

Node* helper(Node* root) {
    if (root->left == NULL) {
        return root->right;
    } 
    else if (root->right == NULL){
        return root->left;
    } 
    Node* rightChild = root->right;
    Node* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == key) {
        return helper(root);
    }
    Node *dummy = root;
    while (root != NULL) {
        if (root->data > key) {
            if (root->left != NULL && root->left->data == key) {
                root->left = helper(root->left);
                break;
            } else {
                root = root->left;
            }
        } else {
            if (root->right != NULL && root->right->data == key) {
                root->right = helper(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }
    return dummy;
}

int main(){
    Node* root = build();
    cout<<"THE TREE LOOKS LIKE THIS:"<<endl;
    bfs(root);
    cout<<endl;
    int t;
    cout<<"ENTER THE NODE TO DELETE:";
    cin>>t;
    cout<<endl;
    cout<<"RESULTANT TREE:"<<endl;
    bfs(deleteNode(root, t));
    return 0;
}