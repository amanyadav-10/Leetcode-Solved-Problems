//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  long long largestSumCycle(int n, vector<int> edge)
  {
   
    
    // cnt vector will count the Indegree of each Node    
    vector<int> cnt(n,0);
    
    for(auto i : edge){
        if(i != -1) cnt[i]++;
    }
    
    queue<int> q;
    
    /*
    
    Fact that a Node with indegree = 0 is out of cycle.
    We'll mark that node visited and cut that node from the graph.
    To do so, find the edge from that node and decrease the indegree of edge[node] by 1.
    
    */
    
    vector<int> vis(n,0);
    for(int i = 0; i<n; i++){
        if(cnt[i]==0){
            vis[i] = 1;
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int node = q.front(); q.pop();
        if(edge[node] == -1) continue;
        --cnt[edge[node]];
        if(cnt[edge[node]] == 0){
            vis[edge[node]] = 1;
            q.push(edge[node]);
        }
    }
    
    int ans = -1;
    
    for(int i = 0; i<n; i++){
        if(vis[i]) continue;
        int val = 0;
        for(int st = i; vis[st] == 0; st = edge[st]){
            vis[st] = 1;
            val += st;
        }
        ans = max(ans,val);
    }
    
    return ans;
    
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends