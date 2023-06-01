class Solution {
public:
    int dp[101][101];
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        memset(dp,-1,sizeof(dp));
        return helper(n-1,m-1,obstacleGrid);
        
    }
    
    int helper(int i,int j, vector<vector<int>>& grid){
        
        if(i==0 && j==0){
            if(grid[i][j]==1){
                return 0;
            }
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(grid[i][j] == 1){
            return 0; // there is an obstacle
        }
        
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        return dp[i][j] =  helper(i-1,j,grid) + helper(i,j-1,grid);
        
    }
};