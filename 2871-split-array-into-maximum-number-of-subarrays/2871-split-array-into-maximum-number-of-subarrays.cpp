class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int andd = INT_MAX;
        for(int i=0;i<nums.size();i++){
            andd&=nums[i];
        }
        if(andd>0){
            return 1;
        }
        
        int ans = 0;
        int val = INT_MAX;
        for(int i=0;i<nums.size();i++){
            val&=nums[i];
            if(val==0){
                ans++;
                val=INT_MAX;
            }
        }
        return ans;
        
    }
};