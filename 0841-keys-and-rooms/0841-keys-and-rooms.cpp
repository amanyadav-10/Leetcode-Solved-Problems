class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int ct = 0;
        int n = rooms.size();
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,rooms);
                ct++;
            }
        }
        return ct==1;
    }
        
        
        void dfs(int i,vector<int>& vis,vector<vector<int>>& rooms){
            vis[i] = 1;
            for(auto x : rooms[i]){
                if(!vis[x]){
                    dfs(x,vis,rooms);
                }
            }
        }
        
};