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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = 0;
        dfs(root,ans,targetSum);
        return ans;
    }
    
    void dfs(TreeNode* root,bool& ans,int& tar){
        if(root==NULL){
            return ;
        }
        tar-=root->val;
//         check if it is a leaf node or not
        if(!root->left && !root->right){
            if(tar==0){
                ans = true;
                return;
            }
        }
        else{
            dfs(root->left,ans,tar);
            dfs(root->right,ans,tar);
        }
        tar+=root->val;
        
    }
};