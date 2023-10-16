class Solution {
public:
    int mod =1e9+7;
    int dp[3505][3505];
    int t = 2000;
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        return helper(k,startPos,endPos);
    }
    int helper(int st,int sp,int ep){
        if(sp==ep && st==0 ){
            return 1;
        }
        if(abs(ep-sp)>st){
            return 0;
        }
        if(dp[t+st][t+sp]!=-1){
            return dp[t+st][t+sp];
        }
        int lt = helper(st-1,sp-1,ep)%mod;
        int rt = helper(st-1,sp+1,ep)%mod;
        return dp[t+st][t+sp] = (lt+rt)%mod;
    }
};