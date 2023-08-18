class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<vector<int>> vis(n,vector<int> (n,0));
        vector<int> vec(n);
        for(auto x: roads){
            vec[x[1]]++;
            vec[x[0]]++;
            vis[x[1]][x[0]] = vis[x[0]][x[1]] = 1;
        }
        
        int ans = 0;
        int max_Sum = INT_MIN;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i==j){
                    continue;
                }
                ans=vec[i]+vec[j];
                if(vis[i][j]==1){
                    ans-=1;
                    vis[j][i] = 0;
                }
                max_Sum = max(max_Sum,ans);
            }
        }
        
        return max_Sum;
    }
};


// this question is using the concept of the degree of a graph 