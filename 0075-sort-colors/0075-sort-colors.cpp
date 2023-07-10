class Solution {
public:
    void sortColors(vector<int>& nums) {
//         Dutch National Flag Algorithm 
        int lo = 0;
        int mid =0;
        int hi = nums.size()-1;
        
        while(mid<=hi){
            if(nums[mid]==0){
                swap(nums[lo],nums[mid]);
                lo++;
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[hi]);
                hi--;
            }
            else{
                mid++;
            }
        }
    }
};