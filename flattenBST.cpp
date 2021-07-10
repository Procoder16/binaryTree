#include<iostream>
#include<queue>
using namespace std;

/*
    The approach we need to keep in mind is that we will be getting a linked list from the left and the right subtree and then combining
    all the three parts, the left subtree made linked list, the root and the linked list from the right subtree.

    Also remember we are not going to make an original linked list class, but just a pair class with the name of LinkedList as we are not 
    going to take any extra space, rather, we will be using the tree itself and just changing and playing around with the nodes.

    Now, keep in mind that in this question, there can be 4 cases:
    
        1. Only one node is there, the leaf node:
            >> For this node, since it has no children, the head and the tail of the linkedlist is the root itself and hence return the ll.
        2. The left subtree is not NULL:
            >> Create a variable of the type LinkedList and store the linkedlist coming from the left subtree using the recursive function.
            >> Now, the right of the tail of the linked list from the left part would be linked to the root.
            >> And the head of the resultant linked list would be the head of this linked list itself.
            >> Return the head.
        3. The right subtree is not NULL:
            >> Create a variable of the type LinkedList and store the linkedlist coming from the right subtree using the recursive function.
            >> Now, in this case the root would be the head of the resultant linked list, so the right of the root would be linked to 
            the head of the linked list coming from the right subtree.
            >> Return the root.
        4. Both the subtrees are not NULL:
            >> Create a variable of the type LinkedList and store the linkedlist coming from the left and the right subtree using the 
            recursive function.         
            >> The tail of the left linkedlist would be connected to the root and the root would be connected to the head of the
            right linked list.
            >> Return the head of the left linked list.
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
    while(temp != NULL){  // printing the linkedlist
        cout<<temp -> data<<"->";
        temp = temp -> right; // since the linked list has no next as we are dealing with the same tree nodes.
    }
    cout<<"NULL";
    return 0;
}

