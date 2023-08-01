class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        vector<vector<int>> ans;
        vector<int> val;
        helper(0,k,ans,val,nums);
        return ans;
        
    }
    
    void helper(int i,int k,vector<vector<int>>& ans,vector<int>& val,vector<int> & nums){
        if(i==nums.size()){
            if(val.size()==k){
                ans.push_back(val);
            }
            return ;
        }
        if(val.size()<k){
            val.push_back(nums[i]);
            helper(i+1,k,ans,val,nums);
            val.pop_back();
        }
        helper(i+1,k,ans,val,nums);
        
        
    }
};

