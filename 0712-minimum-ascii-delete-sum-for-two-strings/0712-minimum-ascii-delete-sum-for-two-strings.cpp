class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(1001,vector<int> (1001,0));
        int n = s1.size();
        int m = s2.size();
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<m;j++){
            dp[0][j]= 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = s1[i-1] + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int ans = dp[n][m];
        int sum = 0;
        for(auto x: s1){
            sum+=x;
        }
        for(auto x: s2){
            sum+=x;
        }
        return sum-2*ans;
    }
};
// how to solve the problem using the space optimization