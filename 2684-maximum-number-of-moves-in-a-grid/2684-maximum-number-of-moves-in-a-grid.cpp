class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        int m = grid[0].size();
        
        int ans = 0;
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            dp[i][m-1] = 0;
        }
        
        for(int j=m-2;j>=0;j--){
            for(int i=0;i<n;i++){
                int r = 0;
                int rt =0;
                int rb =0;
                if(i>0 && j<m-1 && grid[i][j]<grid[i-1][j+1]){
                    rt = 1 + dp[i-1][j+1];
                }
                if(j<m-1 && grid[i][j]< grid[i][j+1]){
                    r = 1+ dp[i][j+1];
                }
                if(i<n-1 && j<m-1 && grid[i][j]<grid[i+1][j+1]){
                    rb = 1 + dp[i+1][j+1];
                }
                dp[i][j] = max(r,max(rt,rb)); 
            }
        }
        
        
        for(int i =0;i<n;i++){
            ans = max(ans,dp[i][0]);
        }
        
        return ans;
    }
    
    
//     this is the recursion for the problem we have used the recursion to write the bottom solution for the problem
    
//     int helper(int i,int j,vector<vector<int>>& grid){
//         int n = grid.size();
//         int m = grid[0].size();
//         if(j==n-1){
//             return 0; // this is the base case of the solution
//         }
        
//         int r =0;
//         int rt =0;
//         int rb =0;
//         if(i>0 && j<n-1 && grid[i][j]<grid[i-1][j+1]){
//             rt = 1+ helper(i-1,j+1,grid);
//         }
//         if(i<n-1 && j<n-1 && grid[i][j]<grid[i+1][j+1]){
//             rb = 1+helper(i+1,j+1,grid);
//         }
//         if(j<n-1 && grid[i][j]<grid[i][j+1]){
//             r = 1+helper(i,j+1,grid);
//         }
//         return max(rt,rb,r);
        
//     }
};