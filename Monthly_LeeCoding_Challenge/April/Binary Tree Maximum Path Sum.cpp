/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs(root);
        return ans;
    }
    
    int dfs( TreeNode *root) {
        if(root == NULL) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        ans = max({ans, left+right+root->val, root->val, left+root->val, right+root->val});
        
        return max({root->val, left+root->val, right+root->val});
    }
    
    
};