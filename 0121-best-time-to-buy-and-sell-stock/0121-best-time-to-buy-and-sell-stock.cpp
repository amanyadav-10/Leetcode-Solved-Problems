class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = 0;
        int cst = nums[0];
        for(int i=1;i<n;i++){
            
            cst = min(nums[i],cst);
            dp[i] = max(nums[i]-cst,dp[i-1]);
            cout<<dp[i]<<endl;
        }
        return dp[n-1];
        
    }
};