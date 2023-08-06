class Solution {
public:    
    // vector<int> par;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        vector<int> par(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1){
                    unionfind(i,j,par);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(par[i]==i){
                ans++;
            }
        }
        return ans;
    }
    
    int findPar(int u,vector<int>& par){
        if(par[u]==u){
            return u;
        }
        return par[u] = findPar(par[u],par);
    }
    
    void unionfind(int u,int v,vector<int> &par){
        int ulp_u = findPar(u,par);
        int ulp_v = findPar(v,par);
        if(ulp_u!=ulp_v){
            par[ulp_u]=ulp_v;
        }
    }
};