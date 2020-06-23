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
    
    //O(n) time
//     int nodes;
//     int countNodes(TreeNode* root) {
//         nodes = 0;
//         dfs(root);
        
//         return nodes;
//     }
    
//     void dfs(TreeNode* root) {
//         if(root == NULL) return;
        
//         nodes += 1;
        
//         dfs(root->left);
//         dfs(root->right);
        
//         return;
//     }
    
    
    //O(log n * log n)
    int countNodes(TreeNode* root) {
        TreeNode *l = root, *r = root;
        int hl = 0, hr = 0;
        
        while(l) {hl++; l = l->left;}
        while(r) {hr++; r = r->right;}
        
        if(hl == hr) return pow(2, hl) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    
};