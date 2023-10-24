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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> pq;
        if(root== NULL){
            return ans;
        }
        pq.push(root);
        while(!pq.empty()){
            priority_queue<int> q;
            int s = pq.size();
            for(int i = 0;i<s;i++){
                auto node = pq.front();
                // pq.pop();
                pq.pop();
                if(node!=NULL){
                    q.push(node->val);
                }
                if(node->left){
                    pq.push(node->left);
                    // q.push(node->left->val);
                }
                if(node->right){
                    pq.push(node->right);
                    // q.push(node->right->val);/
                }
                
            }
            ans.push_back(q.top());
        }
        return ans;
    }
};