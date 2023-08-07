class Solution {
public:
    vector<int> par;
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(auto x : connections){
            unionfind(x[0],x[1]);
        }
        int ans = 0 ;
        for(int i=0;i<n;i++){
            if(par[i]==i){
                ans++;
            }
        }
        return ans-1;
        
    }
    
    int findPar(int u){
        if(par[u]==u){
            return u;
        }
        return par[u] = findPar(par[u]);
    }
    
    void unionfind(int u,int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if(ulp_u!=ulp_v){
            par[ulp_u] = ulp_v;
        }
    }
};