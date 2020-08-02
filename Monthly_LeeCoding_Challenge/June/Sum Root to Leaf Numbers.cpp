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
    int sumNumbers(TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
    
    void dfs(TreeNode* root, int par) {
        if(!root) return;
        
        if(!root->left and !root->right) {ans += (par*10 + root->val); return;}
        
        if(root->right) dfs(root->right, par*10 + root->val);
        
        if(root->left) dfs(root->left, par*10 + root->val);
        
        return;
    }
};