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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> s;
        int n = preorder.size();
        TreeNode* root = NULL;
        if(n == 0) return NULL;
        
        for(auto i: preorder){
            TreeNode* temp = new TreeNode(i);
            TreeNode* prev = NULL;
            int l = 0, r = 0;
            if(root == NULL)
                root = temp;
            
            else{
                TreeNode* curr = root;
                cout<<endl<<endl<<"itr"<<endl;
                while(curr!=NULL){
                    l = 0, r = 0;
                    if(curr->val > i){
                        cout<<"curr > i   ";
                        cout<<curr->val<<" "<<endl;
                        prev = curr;
                        curr = curr->left;
                        l = 1;
                    }
                    else{
                        cout<<"curr < i   ";
                        cout<<curr->val<<" "<<endl;
                        prev = curr;
                        curr = curr->right;
                        r = 1;
                    }
                }
                if(l == 1){
                    prev->left = temp;
                    cout<<"left";
                }
                    
                else if(r==1){
                    prev->right = temp;
                    cout<<"right";
                }
                    
            }
        }
        
        return root;
    }
};