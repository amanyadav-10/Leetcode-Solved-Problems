class Solution {
public:
    int dp[2501];
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<=n;i++){
            dp[i] = -1;
        }
        int val = 0;
        for(int i=0;i<n;i++){
            val = max(val,helper(i,nums));
        }
        
        return val;
    }
    
    int helper(int n,vector<int>& nums){
        int maxi = 1;
        if(dp[n]!=-1){
            return dp[n];
        }
        for(int j=0;j<n;j++){
            if(nums[n]>nums[j]){
                maxi = max(maxi,helper(j,nums)+1);
            }
        }
        return dp[n] = maxi;
    }
};