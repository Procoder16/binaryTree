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


class LinkedList{
    public:
    Node* head;
    Node* tail;
};

LinkedList flattenBST(Node* root){

    LinkedList ll;

    if(root == NULL){  // base case
        ll.head = ll.tail = NULL;
        return ll;
    }

    // 1. There is only one node(leaf node)
    if(root -> left == NULL && root -> right == NULL){
        ll.head = ll.tail = root;
        return ll;
    }
    
    // 2. Right subtree is NULL
    if(root -> left != NULL && root -> right == NULL){
        LinkedList leftLL = flattenBST(root -> left);
        leftLL.tail -> right = root;

        ll.head = leftLL.head;
        ll.tail = root;
        return ll;
    }

    // 3. Right subtree is NULL
    if(root -> right != NULL && root -> left == NULL){
        LinkedList rightLL = flattenBST(root -> right);
        root -> right = rightLL.head;

        ll.head = root;
        ll.tail = rightLL.tail;
        return ll;
    }

    // 4. Both the subtrees are present
    else{
        LinkedList leftLL = flattenBST(root -> left);
        LinkedList rightLL = flattenBST(root -> right);

        leftLL.tail -> right = root;
        root -> right = rightLL.head;

        ll.head = leftLL.head;
        ll.tail = rightLL.tail;
        return ll;
    }
}

int main(){
    Node* root = new Node(5);
    root -> left = new Node(3);
    root -> right = new Node(7);
    root -> left -> left = new Node(1);
    root -> right -> left = new Node(6);
    root -> right -> right = new Node(8);

    cout<<"THE TREE LOOKS SOMETHING LIKE THIS:"<<endl;
    bfs(root);
    cout<<endl;

    LinkedList l = flattenBST(root);
    Node* temp = l.head;

    cout<<"THE NEW LINKED LIST:"<<endl;
    while(temp != NULL){
        cout<<temp -> data<<"->";
        temp = temp -> right;
    }
    cout<<"NULL";
    return 0;
}

