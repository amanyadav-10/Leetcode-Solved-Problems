class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        vector<int> nums1(nums.begin(),nums.end()-1);
        vector<int> nums2(nums.begin()+1,nums.end());
        return max(helper(nums1),helper(nums2));
    }
    
    int helper(vector<int>& nums){
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            cout<<dp[i]<<endl;
            dp[i] =  max(dp[i-1],dp[i-2]+nums[i]); // we can choose to rob previous one or this one .
            
        }
        return dp[n-1];
    }
};