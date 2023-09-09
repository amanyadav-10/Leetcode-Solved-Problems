class Solution {
public:
    
    int dp[1001];
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return helper(target,nums);
    }
    
    
    int helper(int tar,vector<int> &nums){
        if(tar==0){
            return 1;
        }
        if(tar<0){
            return 0;
        }
        if(dp[tar]!=-1){
            return dp[tar];
        }
        int res = 0;
        for(auto x :nums){
            if(x<=tar){
                res+=helper(tar-x,nums);
            }
        }
        return dp[tar] = res;
    }
};