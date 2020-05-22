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
    int curr;
    //since inorder of BST is sorted, so finding kth element in BST will work
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        int ans = INT_MAX;
        curr = 0;
        inorder(root, k, ans);
        return ans;
    }
    
    void inorder(TreeNode* root, int k, int& ans){
        if(!root) return;
        inorder(root->left, k, ans);
        curr++;
        if(curr == k) {
            ans = root->val;
            return;
        }
        inorder(root->right, k, ans);
        
        return;
    }
};