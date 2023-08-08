class Solution {
public:
    int search(vector<int>& nums, int tar) {
//         we have to return the index of the value in the array if it is there else -1;
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(tar == nums[mid]){
                return mid;
            }
//             we have to check for the sorted part in the array
            if(nums[lo]<=nums[mid]){
                if(nums[lo]<=tar && nums[mid]>tar){
                    hi = mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
            else if(nums[mid]<nums[hi]){
                if(nums[mid]<tar && nums[hi]>=tar ){
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
        }
        return -1;
        
    }
};
