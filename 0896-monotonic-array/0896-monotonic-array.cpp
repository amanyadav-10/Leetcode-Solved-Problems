class Solution {
public:

    bool isIncreasing(vector<int> &nums){
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]<=nums[i+1]){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool isDecreasing(vector<int> &nums){
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>=nums[i+1]){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool isMonotonic(vector<int>& nums) {
        if(isIncreasing(nums) || isDecreasing(nums)){
            return true;
        }
        return false;
    }
};