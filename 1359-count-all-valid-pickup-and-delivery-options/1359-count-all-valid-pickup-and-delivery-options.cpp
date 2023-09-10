class Solution {
public:
    int mod = 1e9+7;
    int dp[501];
    int countOrders(int n) {
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        dp[1]=1;
        dp[2]=6;
        for(int i=3;i<=n;i++){
            long long   x = (i*(2*i-1))%mod;
            dp[i] = ((dp[i-1]%mod)*(x%mod))%mod;
        }
        int ans = dp[n]%mod;
        return ans;
        
    }
};