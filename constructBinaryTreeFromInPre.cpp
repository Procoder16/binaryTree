class Solution {
public:
    
    TreeNode* buildTreeHelper(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mp){
        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int posOfRoot = mp[preorder[preStart]];
        int numsLeft = posOfRoot - inStart;
        
        root -> left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, posOfRoot - 1, mp);
        
        root -> right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd, inorder, posOfRoot + 1, inEnd, mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        
        TreeNode* root = buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
        
        return root;
    }
};