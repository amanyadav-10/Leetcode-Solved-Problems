class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int ans = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(mp[0]>1){
                mp[nums[left]]--;
                left++;
            }
            ans = max(ans,i-left+1);
        }
        if(ans==0){
            return 0;
        }
        return ans-1;
        
    }
};