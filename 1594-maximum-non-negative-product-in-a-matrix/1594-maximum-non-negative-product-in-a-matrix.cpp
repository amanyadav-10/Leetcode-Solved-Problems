class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
//         we can do the reverse traversal of the grid and get the solution
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long int >> dp(n,vector<long long int>(m));
        vector<vector<long long int >> dp_min(n,vector<long long int>(m));
        dp[n-1][m-1] = grid[n-1][m-1];
        dp_min[n-1][m-1] = grid[n-1][m-1];
        
        for(int i=n-2;i>=0;i--){
            dp[i][m-1] = dp[i+1][m-1]*grid[i][m-1];
            dp_min[i][m-1] = dp_min[i+1][m-1]*grid[i][m-1];
        }
        for(int j=m-2;j>=0;j--){
            dp[n-1][j] = dp[n-1][j+1]*grid[n-1][j];
            dp_min[n-1][j] = dp[n-1][j+1]*grid[n-1][j];
        }
        
        
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(grid[i][j]>=0){
                    dp[i][j] = max((long long int)dp[i+1][j]*grid[i][j],(long long int)dp[i][j+1]*grid[i][j]);
                    dp_min[i][j] = min((long long int)dp_min[i+1][j]*grid[i][j],(long long int)dp_min[i][j+1]*grid[i][j]);
                }
                else{
                    dp[i][j] = max((long long int)dp_min[i][j+1]*grid[i][j],(long long int)dp_min[i+1][j]*grid[i][j]);
                    dp_min[i][j] = min((long long int)dp[i][j+1]*grid[i][j],(long long int)dp[i+1][j]*grid[i][j]);
                }
            }
        }
        
        return dp[0][0]<0?-1:dp[0][0]%1000000007; 
        
    }
};