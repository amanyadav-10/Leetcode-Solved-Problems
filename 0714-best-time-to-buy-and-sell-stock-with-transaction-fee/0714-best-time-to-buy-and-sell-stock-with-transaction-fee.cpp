class Solution {
    
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return helper(prices,0,1,dp,fee);
    }
    
    int helper(vector<int>& price,int i,int fl,vector<vector<int>>& dp,int fee){
        if(i==price.size()){
            return 0;
        }
        
        if(dp[i][fl]!=-1){
            return dp[i][fl];
        }
        int ans = 0;
        if(fl){
            ans = max((-price[i]+helper(price,i+1,!fl,dp,fee)),(helper(price,i+1,fl,dp,fee)));
        }
        else{
            ans = max((price[i]+helper(price,i+1,!fl,dp,fee)-fee),helper(price,i+1,fl,dp,fee));
        }
        return dp[i][fl] = ans;
    }
};