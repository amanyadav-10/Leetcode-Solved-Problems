class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> indegree(n);
        queue<int> st;
        vector<int> ad[n];
        for(auto x:pre){
            ad[x[1]].push_back(x[0]);
        }
        for(auto x: pre){
            indegree[x[0]]++;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                st.push(i);
            }
        }
        vector<int> topo;
        while(!st.empty()){
            int val = st.front();
            st.pop();
            topo.push_back(val);
            for(auto x : ad[val]){
                indegree[x]--;
                if(indegree[x]==0){
                    // topo.push_back(a);
                    st.push(x);
                }
            }
        }
        if(topo.size()==n){
            return true;
        }
        return false;
        
        
        
        
    }
};
// if we write it using the BFS the first thing we do is we find the indegree for the graph
