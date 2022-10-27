class Solution {
public:
    
    TreeNode* buildTreeHelper(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mp){
        if(postStart > postEnd || inStart > inEnd){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int posOfRoot = mp[postorder[postEnd]];
        int numsLeft = posOfRoot - inStart;
        
        root -> left = buildTreeHelper(postorder, postStart, postStart + numsLeft - 1, inorder, inStart, posOfRoot - 1, mp);
        
        root -> right = buildTreeHelper(postorder, postStart + numsLeft, postEnd - 1, inorder, posOfRoot + 1, inEnd, mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        
        TreeNode* root = buildTreeHelper(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
        
        return root;
    }
};