#include<iostream>
#include<queue>
using namespace std;

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
 
    else if(t < root -> data){   // is the given value is smaller than the root value
        root -> left = deletionInBST(root -> left, t);
        return root;
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
        else{
            Node* replace = root -> right;
            while(replace -> left != NULL){
                replace = replace -> left;
            }
            root -> data = replace -> data;
            root -> right = deletionInBST(root -> right, replace -> data);
            return root;
        }        
    }

    else{ // checking the right subtree
        root -> right = deletionInBST(root, t);
        return root;
    }
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
    bfs(deletionInBST(root, t));
    return 0;
}