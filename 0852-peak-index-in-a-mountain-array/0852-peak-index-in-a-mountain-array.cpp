class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
           int l=1;
        int h=nums.size()-2;
        int ans;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                ans=mid;
                break;
            }
            else if(nums[mid]<nums[mid+1]){
                l=mid+1;
            }
            else if(nums[mid]<nums[mid-1]){
                h=mid-1;
            }
        }
        return ans;
        
    }
        
    
};