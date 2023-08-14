class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(m,0);
        for(int i=0;i<m;i++){
            ans[i] = helper(0,i,grid,n,m);
        }
        return ans;
    }
    
    int helper(int i,int j,vector<vector<int>>& grid,int n,int m){
        if(i==n){
            return j;
            
        }
        
        if(grid[i][j]==1){
            if(j+1<m && grid[i][j+1]==1){
                return helper(i+1,j+1,grid,n,m);
            }
            
        }
        
        else if(grid[i][j]==-1){
            if(j-1>=0 && grid[i][j-1]==-1)
                return helper(i+1,j-1,grid,n,m);
        }
        return -1;
    }
};