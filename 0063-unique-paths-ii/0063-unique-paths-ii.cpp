class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        
        int n = Grid.size();
        int m = Grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        
        return helper(0,0,dp,Grid,n,m);
    }
    
    int helper(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& grid,int n,int m){
        
        if(i>n-1 || j>m-1 || grid[i][j]==1){
            return 0;
        }
        
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        return dp[i][j] =  helper(i+1,j,dp,grid,n,m) + helper(i,j+1,dp,grid,n,m);
    }
    
};