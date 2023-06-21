class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
//         length of the maximum window substr with at most k zeroes
        int left = 0;
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++; //update
            while(mp[0]>k){
                mp[nums[left]]--;
                left++;
            }
            ans = max(ans,i-left+1);
        }
        return ans;
        
    }
};