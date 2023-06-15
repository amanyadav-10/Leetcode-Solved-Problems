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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*> q;
        int max_sum = INT_MIN;
        int level = 0;
        int ans_level = 0;
        q.push(root);
        while(!q.empty()){
            ++level;
            int ans = 0;
            int len = q.size();
            for(int i=0;i<len;i++){
                TreeNode* ptr = q.front();
                q.pop();
                ans+=ptr->val;
                if(ptr->left){
                    q.push(ptr->left);
                }
                if(ptr->right){
                    q.push(ptr->right);
                }
            }
            if(ans>max_sum){
                max_sum = ans;
                ans_level = level;
            }
        }
        
        return ans_level;
    }
};