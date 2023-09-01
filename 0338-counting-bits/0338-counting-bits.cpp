class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0){
            return {0};
        }
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        
        int p = 1;
        for(int i=2;i<=n;i++ ){
            if( (i&(i-1))==0){
                dp[i]=1;
                p = i;
            }
            else{
                dp[i] = 1 + dp[i-p];
            }
        }
        return dp;
    }
};