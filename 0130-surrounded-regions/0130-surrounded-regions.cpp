class Solution {
public:
    void solve(vector<vector<char>>& board) {
//      
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(board[i][j]=='O'){
                        dfs(i,j,board);
                    }
                    
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j]=='Y'){
                    board[i][j]='O';
                }
            }
        }
        
    }
    
    void dfs(int i,int j,vector<vector<char>>& mat){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || mat[i][j]!='O'){
            return ;
        }
        mat[i][j] = 'Y';
        dfs(i+1,j,mat);
        dfs(i,j+1,mat);
        dfs(i-1,j,mat);
        dfs(i,j-1,mat);
    }
};