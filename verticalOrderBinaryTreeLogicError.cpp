#include<iostream>
#include<vector>
#include<map>

/*
    Docs: Diary
*/

using namespace std;

struct node{

    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void verticalOrderPrint(node* root, int d, map<int,vector<int>> &m){
    if(root == NULL){ //base case
        return;
    }
    // otherwise
    m[d].push_back(root -> data);
    verticalOrderPrint(root -> left, d - 1, m);
    verticalOrderPrint(root -> right, d + 1, m);
    return;
}

int main(){

    node* root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);
    root -> left -> left = new node(4);
    root -> left -> right = new node(5);
    root -> right -> left = new node(6);
    root -> right -> right = new node(7);
    root -> left -> right -> right = new node(8);
    root -> right -> right -> right = new node(9);

    /*
                    1
                   / \
                  2   3
                 / \ / \
                4  56   7
                    \    \
                     8    9
    */    
    int d = 0;
    map<int, vector<int>> m;
    verticalOrderPrint(root, d, m);

    for(auto idx : m){
        for(auto val : idx.second){
            cout<<val<<" ";
        }
        cout<<endl;
    }

    return 0;
}