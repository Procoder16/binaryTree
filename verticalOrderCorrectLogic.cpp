//Vertical Order Print
#include<iostream>
#include<queue>
#include<map>
#include<set>
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

void verticalOrderPrint(Node* root){

    queue<pair<Node*,pair<int, int>>> q;
    map<int,map<int, multiset<int>>> ans;

    if(root == NULL){
        return;
    }
    
    q.push({root,{0,0}});

    while(!q.empty()){
        auto p = q.front();
        q.pop();

        int x = p.second.first;
        int y = p.second.second;

        ans[x][y].insert(p.first -> data);

        if(p.first -> left){
            q.push({p.first -> left, {x - 1, y + 1}});
        }
        if(p.first -> right){
            q.push({p.first -> right, {x + 1, y + 1}});
        }
    }

    vector<vector<int>> levelWiseNodes;    
    for(auto p : ans){
        vector<int> col;
        for(auto q : p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        levelWiseNodes.push_back(col);
    }

    for(int i = 0; i < levelWiseNodes.size(); i++){
        for(int j = 0; j < levelWiseNodes[i].size(); j++){
            cout<<levelWiseNodes[i][j]<<" ";
        }
        cout<<endl;
    }
}   

int main(){

    struct Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(10);
    root -> right -> left = new Node(9);
    root -> right -> right = new Node(10);

    root -> left -> left -> right = new Node(5);
    root -> left -> left -> right -> right = new Node(6);

    verticalOrderPrint(root);

    return 0;
}