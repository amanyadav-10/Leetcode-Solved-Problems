//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0){
            return -1;
        }
        if(X==0 && Y==0){
            return 0;
        }
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},0});
        int ans = INT_MAX;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};
        
        vector<vector<int>> vis(N,vector<int>(M,0));
        vis[0][0]=1;
        
        
        while(!q.empty()){
            auto z = q.front();
            q.pop();
            int i = z.first.first;
            int j = z.first.second;
            int ct = z.second;
            
            if(i==X && Y==j){
                return ct;
            }
        
            
            for(int k=0;k<4;k++){
                int x = i+dx[k];
                int y = j+dy[k];
                if(x>=0 && y>=0 && x<N&& y<M && A[x][y]==1 && vis[x][y]==0){
                    q.push({{x,y},ct+1});
                    vis[x][y]=1;
                }
            }
        }
        return -1;
    }
};
// shortest path in the matrix problems cannot be solved using the dfs we need to use bfs to solve these kinds of problems anyways



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends