class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int pro = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                pro+=nums[i+1]-nums[i];
            }
        }
        return pro;
    }
    
};