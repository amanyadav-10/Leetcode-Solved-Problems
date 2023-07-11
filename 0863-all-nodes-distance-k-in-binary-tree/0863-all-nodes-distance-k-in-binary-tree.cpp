/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent_map(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &par){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto ptr=q.front();
            q.pop();
            if(ptr->left){
                par[ptr->left] = ptr;
                q.push(ptr->left);
            }
            if(ptr->right){
                par[ptr->right]=ptr;
                q.push(ptr->right);
            }
        }   
    }
    // above we have written the function to update the node of each map with it' parent


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        parent_map(root, parent);
        unordered_set<TreeNode*> st;
        queue<TreeNode*> q;
        q.push(target);
        st.insert(target);
        int cunt=0;
        while(!q.empty()){
            int s=q.size();
            
            if(cunt==k) break;
            cunt++;
            for(int i=0;i<s;i++){
                auto ptr=q.front();
                q.pop();
                if(ptr->left && !st.count(ptr->left)){
                    q.push(ptr->left);
                    st.insert(ptr->left);
                }
                if(ptr->right && !st.count(ptr->right)){
                    q.push(ptr->right);
                    st.insert(ptr->right);
                }
                // for going upward 
                if(parent[ptr] && !st.count(parent[ptr])){
                    q.push(parent[ptr]);
                    st.insert(parent[ptr]);
                }
            }
        }
      
        vector<int> ans;
        while(!q.empty()){
            auto px=q.front();
            q.pop();
            ans.push_back(px->val);
        }
        return ans;

        
    }
};