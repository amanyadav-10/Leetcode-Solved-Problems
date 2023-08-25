class Solution {
public:
    int dp[1001][1001];
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        memset(dp,-1,sizeof(dp));
        helper(0,0,nums1,nums2);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans= max(ans,dp[i][j]);
            }
        }
        return ans;
    }
    int helper(int i,int j,vector<int> &a,vector<int> &b){
        if(i>=a.size() || j>=b.size()){
            return 0;
        }    
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        helper(i+1,j,a,b);
        helper(i,j+1,a,b);
        if(a[i]==b[j]){
            return dp[i][j] = 1+helper(i+1,j+1,a,b);
        }
        else{
            return dp[i][j] = 0;
        }
        
    }
};