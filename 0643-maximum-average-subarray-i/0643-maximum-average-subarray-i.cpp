class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // max length subarray
        
        double sum = 0;
        int i=0;
        int n = nums.size();
        double ans = INT_MIN;
        while(i<n){
            if(i<k){
                sum+=nums[i];
            }
            else{
                ans=max(ans,sum);
                sum-=nums[i-k];
                sum+=nums[i];
                
            }
            i++;
        }
        ans = max(ans,sum);
        return ans/k;
        
    }
};