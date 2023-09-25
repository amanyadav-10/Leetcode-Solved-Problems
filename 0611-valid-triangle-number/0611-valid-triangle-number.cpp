class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int ans  = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int lo = 0;
            int hi = i-1;
            while(lo<hi){
                if(nums[lo]+nums[hi]>nums[i]){
                    ans+=hi-lo;
                    hi--;
                }
                else{
                    lo++;
                }
            }
        }
        return ans;
    }
    
};