class Solution {
public:
    int dp[501][501];
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,nums1,nums2);
        
    }
    
    int helper(int i,int j,vector<int> &a,vector<int> &b){
        if(i>=a.size() || j>=b.size()){
            return INT_MIN;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int temp = helper(i+1,j+1,a,b);
        int take_i = helper(i,j+1,a,b);
        int take_j = helper(i+1,j,a,b);
        
        if(temp==INT_MIN){
            temp = (a[i]*b[j]);
        }
        else{
            temp = (a[i]*b[j])+temp;
        }
        return dp[i][j] = max({take_i,take_j,temp,a[i]*b[j]});
        
    }
};