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
    vector<TreeNode*> solve(int start, int end) {
        vector<TreeNode*> trees;
        if(start > end) {
            trees.push_back(NULL);
            return trees;
        }
        if(start == end) {
            trees.push_back(new TreeNode(start));
            return trees;
        }
        
        for(int i=start; i<=end; i++) {
            vector<TreeNode*> leftTree = solve(start, i-1);
            vector<TreeNode*> rightTree = solve(i+1, end);
            
            for(int j=0; j<leftTree.size(); j++) {
                for(int k=0; k<rightTree.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree[j];
                    root->right = rightTree[k];
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};