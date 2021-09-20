#include<bits/stdc++.h>
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

int maxWidthBinaryTree(Node* root){
    if(root == NULL){
        return 0;
    }

    int ans = 0;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        int size = q.size();
        int mmin = q.front().second;
        int first, last;
        for(int i = 0; i < size; i++){
            int curId = q.front().second - mmin;
            Node* temp = q.front().first;
            q.pop();
            if(i == 0){
                first = curId;
            }
            if(i == size - 1){
                last = curId;
            }
            if(temp -> left){
                q.push({temp -> left, curId * 2 + 1});
            }
            if(temp -> right){
                q.push({temp -> right, curId * 2 + 2});
            }
        }
        ans = max(ans, last - first + 1);
    }

    return ans;
}

int main(){

    Node* root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(4);

    root -> left -> right = new Node(5);
    root -> left -> right -> left = new Node(6);
    root -> left -> right -> right = new Node(7);

    root -> right = new Node(3);

    cout<<"WIDTH OF THE BINARY TREE:"<<maxWidthBinaryTree(root);

    return 0;
}