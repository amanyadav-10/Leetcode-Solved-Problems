class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> adjRev[n];
        vector<int> indegree(n,0);
        queue<int> q;
        vector<int> ans;
        for(int i =0;i<n;i++){
            for(auto x : graph[i]){
                adjRev[x].push_back(i);
                indegree[i]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int val = q.front();
            q.pop();
            ans.push_back(val);
            for(auto x: adjRev[val]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

