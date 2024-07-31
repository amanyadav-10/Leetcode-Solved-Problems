class Solution {
public:
    int dp[201][201];
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        memset(dp,-1,sizeof(dp));
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,helper(i,j,n,m,matrix,-1));
            }
        }
        return ans;
        
    }
    int helper(int i,int j,int n,int m,vector<vector<int>> &grid,int p){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]<=p){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int rt =  helper(i,j+1,n,m,grid,grid[i][j]);
        int lt =  helper(i,j-1,n,m,grid,grid[i][j]);
        int bt =  helper(i+1,j,n,m,grid,grid[i][j]);
        int up =  helper(i-1,j,n,m,grid,grid[i][j]);
        
        return dp[i][j] = 1 + max(rt,max(lt,max(bt,up)));
    }
};