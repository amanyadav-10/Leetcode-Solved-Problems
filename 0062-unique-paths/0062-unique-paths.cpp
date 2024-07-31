class Solution {
public:
    int dp[101][101];
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,m,n);
        
    }
    
    int helper(int i,int j,int n,int m){
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(i>=n || j>=m || i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int rt = helper(i,j+1,n,m);
        int bt = helper(i+1,j,n,m);
        return dp[i][j] = rt+bt;
    }
};