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
    // make the indegree lsit here
    vector<int> indegree(n,0);
    for(auto x: edge){
        if(x!=-1){
            indegree[x]++;
        }
    }
    
    queue<int> q;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            vis[i]=1;
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(edge[node]==-1){
            continue;
        }
        --indegree[edge[node]];
        if(indegree[edge[node]]==0){
            vis[edge[node]]=1;
            q.push(edge[node]);
        }
    }
    
    int ans = -1;
    for(int i=0;i<n;i++){
        if(vis[i]){
            continue;
        }
        int val = 0;
        for(int st=i;vis[st]==0;st=edge[st]){
            vis[st]=1;
            val+=st;
        }
        ans=max(ans,val);
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