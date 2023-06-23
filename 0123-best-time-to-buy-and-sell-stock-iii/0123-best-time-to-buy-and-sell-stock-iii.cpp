class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,
                                    vector<vector<int>> 
                                            (2,vector<int>(2+1,-1)));
        return helper(prices,0,1,2,dp);
    }
    
    int helper(vector<int>& p,int i,int flag,int k,vector<vector<vector<int>>>& dp){
        int n = p.size();
        if(i==n || k==0){
            return 0;
        }
        
        if(dp[i][flag][k]!=-1){
            return dp[i][flag][k];
        }
        
//         we will check if the current stock is already bought or not and accordingly have two options
        int ans = 0;
        int tran = 0;
        int not_tran= 0;
        if(flag){ //we have not bought
            tran = -p[i] + helper(p,i+1,!flag,k,dp);
            not_tran = 0 + helper(p,i+1,flag,k,dp);
            // ans = max(buy,not_buy);
        }
        else{//we can sell or not sell here
            tran = p[i] + helper(p,i+1,!flag,k-1,dp);
            not_tran = 0 + helper(p,i+1,flag,k,dp);
            // ans = max(sell,not_sell);
        }
        ans = max(tran,not_tran);
        return dp[i][flag][k] = ans;
        
    }
};

// this problem is based on three dimensional dp we have to keep track of the things that we have