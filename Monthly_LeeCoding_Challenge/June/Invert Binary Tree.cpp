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
        // DFS solution
		// TreeNode* invertTree(TreeNode* root) {
		// if(!root) return root;
		// invertTree(root->left);
		// invertTree(root->right);
		// swap(root->left, root->right);
		// return root;
		// }
    
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto t = q.front();
                q.pop();
                
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
                
                //swapping left and right
                swap(t->left, t->right);
            }
        }
        
        return root;
    }
    
};