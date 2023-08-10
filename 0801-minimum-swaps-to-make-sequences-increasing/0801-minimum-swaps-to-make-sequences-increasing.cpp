class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int dp[100005][2];
        memset(dp,-1,sizeof(dp));
        
        return helper(0,-1,-1,nums1,nums2,dp,0);
        
        
    }
    
    int helper(int i,int p1,int p2,vector<int>& n1,vector<int>& n2,int dp[100005][2],bool swap)
    {
        if(i>=n1.size()){
            return 0;
        }
        
        if(dp[i][swap]!=-1){
            return dp[i][swap];
        }
        int sp = INT_MAX;
        int n_sp = INT_MAX;
//         if swap is possible 
        if(n1[i]>p2 && n2[i]>p1){
            sp = min(sp,1+helper(i+1,n2[i],n1[i],n1,n2,dp,1));
        } 
        
//         if swap is possible but not required 
        
        if(n1[i]>p1 && n2[i]>p2){
            n_sp = min(n_sp,helper(i+1,n1[i],n2[i],n1,n2,dp,0));
        }
        return dp[i][swap] =  min(sp,n_sp);
    }    
    
};


