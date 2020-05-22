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
    
    //level can be traced by increasing level just before end of while looop
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, int> > q; //root, level, only t
        q.push({root,0});
        int par_x, par_y;
        int level_x, level_y;
        int flag=0;
        
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            if(t.first->left){
                q.push({t.first->left, t.second+1});
                
                if(t.first->left->val==x){
                    par_x=t.first->val;
                    level_x=t.second;
                    flag++;
                }
                if(t.first->left->val==y){
                    par_y=t.first->val;
                    level_y=t.second;
                    flag++;
                }
            }
            if(t.first->right){
                q.push({t.first->right, t.second+1});
                if(t.first->right->val==y){
                    par_y=t.first->val;
                    level_y=t.second;
                    flag++;
                }
                if(t.first->right->val==x){
                    par_x=t.first->val;
                    level_x=t.second;
                    flag++;
                }
            }
            if(flag==2) break;
                        
        }
        cout<<"p_x "<<par_x<<" p_y "<<par_y<<endl;
        
        return ((par_x!=par_y and level_x==level_y)?true:false);
    }
};