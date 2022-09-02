class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        int eleCount = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        double levelSum = 0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp != NULL){
                levelSum+=temp -> val;
                eleCount++;
                if(temp -> left){
                    q.push(temp -> left);
                }
                if(temp -> right){
                    q.push(temp -> right);
                }
            }
            else{
                double avg = levelSum/(eleCount*1.0);
                ans.push_back(avg);
                eleCount = 0;
                levelSum = 0;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
        }
        return ans;
    }
};