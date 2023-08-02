class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> val;
        helper(0,n,nums,ans,val);
        return ans;
    
        
    }
    
    void helper(int i,int n,vector<int>& nums,vector<vector<int>> & ans,vector<int> &val){
        if(i==n){
            ans.push_back(nums);
        }
        for(int j=i;j<n;j++){
            swap(nums[i],nums[j]);
            helper(i+1,n,nums,ans,val);
            swap(nums[i],nums[j]);
        }
    }
};