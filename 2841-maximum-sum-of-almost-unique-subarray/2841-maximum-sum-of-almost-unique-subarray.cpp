class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
//         sliding window pattern problem 
        unordered_map<int,int> mp;
        int left  = 0;
        long long ans = 0;
        int n = nums.size();
        long long sum  =0;
        int d = 0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            sum+=nums[i];
            d++;
            while(d>k){
                sum-=nums[left];
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
                d--;
            }
            if(mp.size()>=m){
                ans= max(ans,sum);
            }
            
        }
        return ans;
        
    }
};