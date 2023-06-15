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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==NULL){
            return NULL;
        }
        root->val=0;
        q.push(root);
        while(!q.empty()){
            
            int n = q.size();
            vector<TreeNode*> vec;
            int sum = 0;
            
            // vec.push_back(ptr);
            for(int i=0;i<n;i++){
                TreeNode* ptr = q.front();
                q.pop();
                vec.push_back(ptr);
                if(ptr->left){
                    q.push(ptr->left);
                    sum+=ptr->left->val;
                }
                if(ptr->right){
                    q.push(ptr->right);
                    sum+=ptr->right->val;
                }
            }
            
            for(auto x : vec){
                int temp = sum;
                if(x->left){
                    temp-=x->left->val;
                }
                if(x->right){
                    temp-=x->right->val;
                }
                if(x->left){
                    x->left->val=temp;
                }
                if(x->right){
                    x->right->val=temp;
                }
                
            }
        }
        return root;
        
    }
};