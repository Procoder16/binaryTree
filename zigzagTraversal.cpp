#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void zigzagTraversal(Node* root){
    vector<vector<int>> traversal;
    int flag = 0;

    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    vector<int> temp;

    while(!q.empty()){
        if(q.front() != NULL){
            Node* t = q.front();
            temp.push_back(t -> data);
            if(t -> left){
                q.push(t -> left);
            }
            if(t -> right){
                q.push(t -> right);
            }
            q.pop();
        }
        else{
            if(flag == 0){
                traversal.push_back(temp);
                flag = 1;
                temp.clear();
                q.pop();
            }
            else{
                reverse(temp.begin(), temp.end());
                traversal.push_back(temp);
                flag = 0;
                temp.clear();
                q.pop();               
            }
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }

    for(int i = 0; i < traversal.size(); i++){
        for(int j = 0; j < traversal[i].size(); j++){
            cout<<traversal[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    struct Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);

    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    root -> right -> left = new Node(6);
    root -> right -> right = new Node(7);

    zigzagTraversal(root);

    return 0;
}