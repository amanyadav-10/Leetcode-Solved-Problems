class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> eff(n,vector<int> (m,INT_MAX));
        eff[0][0] = 0;
        pq.push({0,{0,0}});
//         we will start the dijkstra , we 
        while(!pq.empty()){
            auto x = pq.top();
            int val = x.first;
            int i = x.second.first;
            int j = x.second.second;
            pq.pop();
            if(i==n-1 && j==m-1){
                return val;
            }
            
            for(int k=0;k<4;k++){
                int nx = i+ dx[k];
                int ny = j+dy[k];
                if(!check(nx,ny,heights)){
                    continue;
                }
                
                int cost = abs(heights[nx][ny] - heights[i][j]);
                int new_eff = max(cost,val);
                if(new_eff<eff[nx][ny]){
                    eff[nx][ny] = new_eff;
                    pq.push({eff[nx][ny],{nx,ny}});
                }
            }
            
        }
        return eff[n-1][m-1];
        
        
    }
    
    bool check(int i,int j,vector<vector<int>> & mat){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size()){
            return false;
        }
        else{
            return true;
        }
    }
};
