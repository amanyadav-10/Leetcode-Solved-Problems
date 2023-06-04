class Solution {
public:
    int findCircleNum(vector<vector<int>>& iscon) {
        int n= iscon.size();
        int ans=0;
//         make the vis list 
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,iscon,n);
                ans++;
            }
        }
        return ans;
    }
    
//     we will directly write the DFS on the adjacency matrix
    // and count number of times the dfs has been called to get the solution of the problem 
    
    void dfs(int i,vector<int>& vis,vector<vector<int>>& arr,int n){
        vis[i]=1;
        for(int j=0;j<n;j++){
            if(arr[i][j]==1 && !vis[j]){
                dfs(j,vis,arr,n);
            }
        }
    }
    
};