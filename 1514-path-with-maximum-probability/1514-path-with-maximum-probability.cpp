class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
//         Lets first make the adjacency matrix and solve the problem 
        int x = edges.size();
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<x;i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        vector<double> dis(n,INT_MIN);
        dis[start] = 1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1,start});
        while(!pq.empty()){
            auto a = pq.top().first;
            auto b = pq.top().second;
            pq.pop();
            if(b==end){
                return a;
            }
            
            for(auto x : adj[b]){
                auto node = x.first;
                auto wt = x.second;
                if(dis[node]<a*wt){
                    dis[node]=a*wt;
                    pq.push({dis[node],node});
                    
                }
            }
        }
        return 0.0;
    }
};