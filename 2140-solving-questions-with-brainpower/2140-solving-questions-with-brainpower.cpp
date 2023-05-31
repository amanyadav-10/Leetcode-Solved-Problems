class Solution {
public:
    long long dp[100001];
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        for(int i=0;i<n;i++){
            dp[i]=-1;
        }
        return helper(0,questions);
        
        
    }
    
    long long helper(int i,vector<vector<int>>& nums){
        if(i>=nums.size()){
            return 0;
        }
//         two options 
        // skip it or take it
        if(dp[i]!=-1){
            return dp[i];
        }
        long long skip = helper(i+1,nums);
        long long take = nums[i][0] + helper(i+1+nums[i][1],nums);
        return dp[i] = max(skip,take);
    }
    
};