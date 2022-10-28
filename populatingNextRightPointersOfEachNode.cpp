/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    vector<Node*> createBFS(Node* root){
        
        queue<Node*> q;
        vector<Node*> vec;
        
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            vec.push_back(temp);
            
            if(temp != NULL){
                if(temp -> left){
                    q.push(temp -> left);
                }
                if(temp -> right){
                    q.push(temp -> right);
                }
            }else{
                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
        
        return vec;
    }
    
    Node* connect(Node* root) {
        if(root == NULL){
            return NULL;
        }
        
        vector<Node*> vec;
        
        vec = createBFS(root);
        
        for(int i = 0; i < vec.size() - 1; i++){
            if(vec[i] != NULL){
                vec[i] -> next = vec[i + 1];
            }
        }
        
        return root;
    }
};