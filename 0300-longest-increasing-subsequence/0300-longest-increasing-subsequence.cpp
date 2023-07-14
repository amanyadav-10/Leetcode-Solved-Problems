class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(2502,vector<int>(2503,-1));
        
        return helper(0,-1,nums,dp);
    }
    
    int helper(int i,int prev,vector<int>& ans,vector<vector<int>>& dp){
        if(i==ans.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int not_take = helper(i+1,prev,ans,dp);
        int take = 0;
        if(prev == -1 || ans[i] > ans[prev]){
            take = 1+ helper(i+1,i,ans,dp);
        }
        return dp[i][prev+1]=max(take,not_take);
    }
};

// the solution is passing for the
// we will write the dp solution to the problem 
// we have two state here that is the index and the prev element 