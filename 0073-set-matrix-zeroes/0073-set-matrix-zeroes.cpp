class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
//         most optimal solution using the using constant space to solve the problem 
        int n = matrix.size();
        int m = matrix[0].size();
        bool frstrow = false;
        bool frstcol = false;
        
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0){
                frstcol = true; // we will mark the first column in the end to be zero
            }
        }
        
        for(int j=0;j<m;j++){
            if(matrix[0][j]==0){
                frstrow = true;
            }
        }
        
        
//         we will use the first row and the first col to track the rows and the columns that we have to convert to 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        
//         we will use this information to use 
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                } 
            }
        }
        
        if(frstrow){
            for(int j = 0;j<m;j++){
                matrix[0][j] = 0;
            }
        }
        
        if(frstcol){
            for(int i=0;i<n;i++){
                matrix[i][0] = 0;
            }
        }
         return ;
    }
};