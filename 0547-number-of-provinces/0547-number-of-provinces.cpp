class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
//        vectorMutn
        int ans =0;
        
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                ans++;
            }
        }
        return ans;
        
        
    }
    
    void dfs(int i,vector<int>& vis,vector<int> adj[]){
        vis[i]=1;
        for(auto x : adj[i]){
            if(!vis[x]){
                dfs(x,vis,adj);
            }
        }
    }
};