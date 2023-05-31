class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                int ct =1;
                while(i<n &&(nums[i]>nums[i-1])){
                    ct++;
                    i++;
                    ans = max(ans,ct);
                }
            }
        }
        return ans;
    }
};