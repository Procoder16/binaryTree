#include<iostream>
#include<stack>
using namespace std;

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

Node* ternaryToTree(string s) {
    if (s.length() == 0)
        return NULL;

    Node* root = new Node(s[0]);
    stack<Node*> stack;
    stack.push(root);

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == '?') {
            Node* node = stack.top();
            node -> left = new Node(s[i + 1]);
            stack.push(node -> left);
        } else if (s[i] == ':') {
            stack.pop();
            Node* node = stack.top();
            stack.pop();
            node -> right = new Node(s[i + 1]);
            stack.push(node ->right);
        }
    }

    return root;
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root -> data;
    preOrder(root -> left);
    preOrder(root -> right);
}

int main(){

    string str = "a?b?c:d:e";

    Node* newTree = ternaryToTree(str);

    preOrder(newTree);

    return 0;
}