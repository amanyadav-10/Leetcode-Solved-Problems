class Solution {
public:
    int rob(vector<int>& nums) {
        int val = 0;
        for(auto x : nums ){
            val+=x;
        }
        vector<vector<int>> dp(nums.size()+1,vector<int>(val+1,-1));
        return helper(0,nums,0,dp);
    }
    int helper(int i,vector<int> &nums,int val,vector<vector<int>> &dp){
        if(i>=nums.size()){
            return val;
        }
        if(dp[i][val]!=-1){
            return dp[i][val];
        }
        int take = 0;
        int not_take = 0;
        take = helper(i+2,nums,val+nums[i],dp);
        not_take = helper(i+1,nums,val,dp);
        
        return dp[i][val] = max(take,not_take);
    }
    
};