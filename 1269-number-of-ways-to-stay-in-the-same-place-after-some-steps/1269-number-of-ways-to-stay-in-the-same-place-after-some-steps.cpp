class Solution {
public:
    int dp[501][501];  
    int mod = 1e9+7;
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof(dp));
        return helper(0,steps,arrLen);
    }
    
    int helper(int i,int st,int sz){
        if(i==0 && st==0){
            return 1;
        }
        if(i<0 || st==0 || i>=sz || i>st){
            return 0;
        }
        if(dp[i][st]!=-1){
            return dp[i][st];
        }
        
        
        long long  lt = 0;
        long long rt = 0;
        long long stp = 0;
        lt = helper(i-1,st-1,sz)%mod;
        rt = helper(i+1,st-1,sz)%mod;
        stp = helper(i,st-1,sz)%mod;
        return dp[i][st] = (lt+rt+stp)%mod;
    }
};