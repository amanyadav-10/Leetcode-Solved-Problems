class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
//         here we are given that the first element of each row is more than the last element of the previous row
        int n = mat.size();
        int m = mat[0].size();
        
        int lo = 0;
        int hi = (m*n)-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(mat[mid/m][mid%m]==target){
                return true;
            }
            else if(mat[mid/m][mid%m]<target){
                lo=mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return false;
    }
};