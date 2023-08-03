//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<int>> adj[N];
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            // adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dis(N,INT_MAX);
        dis[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto x = pq.top();
            int dist = x.first;
            int node = x.second;
            pq.pop();
            for(auto a : adj[node]){
                int adjNode = a[0];
                int wt = a[1];
                if(dis[adjNode]>dist+wt){
                    dis[adjNode]=dist+wt;//if the current distanve is less than the prev distance
                    pq.push({dis[adjNode],adjNode});
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dis[i]==INT_MAX){
                dis[i]=-1;
            }
        }
        return dis;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends