class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[301][5001];
        memset(dp,-1,sizeof(dp));
        return helper(0,amount,coins,dp);
    }
    
    int helper(int i,int amt,vector<int> & coins,int dp[301][5001]){
        
        if(amt==0){
            return 1;
        }
        if(amt<0 || i>=coins.size()){
            return 0;
        }
        if(dp[i][amt]!=-1){
            return dp[i][amt];
        }
        
        if(coins[i]<=amt){
            return dp[i][amt] = helper(i,amt-coins[i],coins,dp) + helper(i+1,amt,coins,dp);
        }
        else{
            return dp[i][amt]=  helper(i+1,amt,coins,dp);
        }
        
    }
};


