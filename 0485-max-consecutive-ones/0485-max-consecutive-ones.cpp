class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ct = 0;
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                ct++;
                ans=max(ct,ans);
            }
            else{
                ct=0;
            }
        }
        return ans;
        
    }
};