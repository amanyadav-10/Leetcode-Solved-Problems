class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        queue<pair<int,int>> q;
        
        int n = mat.size();
        
        int m = mat[0].size();
        
        vector<vector<int>> v(n,vector<int> (m,-1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    v[i][j] = 0;
                }
            }
        }
        
        vector<pair<int,int>> vec = {{-1,0},{1,0},{0,-1},{0,1}};
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(auto it: vec){
                int i = it.first;
                int j = it.second;
                
                int nx = x+i;
                int ny = y+j;
                if(ny>=0 && ny<m && nx>=0 && nx<n && v[nx][ny]==-1){
                    v[nx][ny] = v[x][y] + 1;
                    q.push({nx,ny});
                }
            }
            
        }
        
        return v;
        
        
    }
};