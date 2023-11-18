class Solution {
public:
    
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left = 0;
        // int i = 0;
        int ans = 0;
        long long sum = 0;
        for(int i = 0;i<nums.size();i++){
            long long cur = nums[i];
            sum+=cur;
            
            while((i-left+1)*cur - sum > k){
                sum-=nums[left];
                left++;
            }
            ans = max(ans,i-left+1);
        }
        return ans;
        
    }
};

