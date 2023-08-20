class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int ans = 0;
        int maxf = 0;
        int left  = 0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            maxf = max(maxf,mp[nums[i]]);
            while(i-left+1-maxf>k){
                mp[nums[left]]--;
                left++;
            }
        }
        return maxf;
        
        
    }
};