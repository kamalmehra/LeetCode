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
    int diameterOfBinaryTree(TreeNode* root) {
        // at each parent the max distance b/w child will be the value at left+value at right, BUT the parent will contain value = max(left, righr) so that its parent can only go either left or right
        if(!root) return 0;
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
    
    int dfs(TreeNode* root, int &ans){
        if(!root) return 0;
        
        int left = dfs(root->left,ans);
        int right = dfs(root->right,ans);
        
        //max distance at current parent
        ans = max(ans, left+right);
        root->val = max(left, right)+1; //1 is added for the distance b/w two nodes
        
        return root->val;
        
    }
};