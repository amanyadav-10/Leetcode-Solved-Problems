
class Solution {
#define ll long long int
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        // vector<int> vis(n,0);
        int n = bombs.size();
        vector<int> adj[n];
        
        // we will make the adjacency list 
        for(int i=0;i<n;i++){
            ll x = bombs[i][0];
            ll y = bombs[i][1];
            ll z = bombs[i][2];
            for(int j=0;j<n;j++){
                if(i!=j){
                    ll valx = abs(x-bombs[j][0]);
                    ll valy = abs(y-bombs[j][1]);
                    if(valx*valx+valy*valy <=z*z){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            int ct = 0;
            vector<int> vis(n,0); //we have to create this because we do it for every node it is kind of multisource dfs
            
            dfs(i,adj,vis,ct);
            ans = max(ans,ct);
        }
        return ans;
    }
    
    
    void dfs(int node,vector<int> adj[],vector<int>& vis,int& ct){
        vis[node] = 1;
        ct++;
        for(auto x : adj[node]){
            if(!vis[x]){
                dfs(x,adj,vis,ct);
            }
        }
    }
};