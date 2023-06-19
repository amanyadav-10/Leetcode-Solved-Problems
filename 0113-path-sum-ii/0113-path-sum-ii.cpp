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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> val;
        helper(root,ans,val,targetSum);
        return ans;
    }
    
    void helper(TreeNode* root,vector<vector<int>>& ans,vector<int> &val,int tar){
        if(root==NULL){
            return;
        }
        val.push_back(root->val);
        tar-=root->val;
        
//         check for the leave node 
        if(!root->left && !root->right){
            if(tar==0){
                ans.push_back(val);
//                 I will not return here because I have to return all the possible paths
                
            }
        }
        
        else{
            helper(root->left,ans,val,tar);
            helper(root->right,ans,val,tar);
        }
        
        // backtrack
        val.pop_back();
    }
};