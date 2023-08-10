class Solution {
public:
    bool search(vector<int>& nums, int target) {
//         It is also a modified question of the rotated sorted array atopic
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return true;
            }
//          if the left part of the array is sorted then 
            if(nums[low]<=nums[mid]){
                if(nums[mid]==nums[low]){
                    for(int i=0;i<mid;i++){
                        if(target==nums[i]){
                            return true;
                        }
                    }
                }
                if(nums[mid]<=target && target<nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            
            else{
                if(nums[mid]<target && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            
        }
        
        return false;
        
    }
};
// We have to check that if the mid is equal to low then we had to do the o(n) complexity check

