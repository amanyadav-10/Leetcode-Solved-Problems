class Solution {
public:
    int mod = 1e9+7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (k, -1)));
        return dfs(0,0,grid,k,n,m,ans,dp);
    }
    
    int dfs(int i,int j,vector<vector<int>>& grid,int k,int n,int m,int ans,vector<vector<vector<int>>>& dp){
        if(i<0 || j<0 || i>=n || j>=m){
            return 0;
        }
        // ans+=grid[i][j];
        if(i==n-1 && j==m-1 && (ans +grid[i][j])%k==0){
            return 1;
        }
        if(dp[i][j][ans]!=-1){
            return dp[i][j][ans];
        }
        
        int r = dfs(i+1,j,grid,k,n,m,(ans+grid[i][j])%k,dp);
        int d = dfs(i,j+1,grid,k,n,m,(ans+grid[i][j])%k,dp);
        return dp[i][j][ans] =  (r+d)%mod;
    }
};

