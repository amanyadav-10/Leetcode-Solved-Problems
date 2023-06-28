#define ll long long

class Solution {
public:
    int MOD  =1e9+7;
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll,ll>> arr[n];
        int x =roads.size();
        for(int i=0;i<x;i++){
            arr[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            arr[roads[i][1]].push_back({roads[i][0],roads[i][2]});
            
        }
//         we have made the adjacency list 
        vector<ll> dis(n,LONG_MAX);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
//         the minimum prriority queue required for dijkstra algorithm
        vector<ll> count(n);
        dis[0] = 0;
        pq.push({0,0});
        count[0]=1;
        
        while(!pq.empty()){
            auto a = pq.top().first;
            auto b = pq.top().second;
            pq.pop();
            if(a>dis[b]) continue;
            for(auto x : arr[b]){
                auto node = x.first;
                auto wt = x.second;
                
                if(dis[node]>a+wt){
                    dis[node] = a+wt;
                    pq.push({dis[node],node});
                    count[node] = count[b];
                }
                else if(dis[node] == a + wt){
                    count[node] = (count[node]+count[b])%MOD;
                }
            }
        }
        
        return count[n-1];
        
    }
};