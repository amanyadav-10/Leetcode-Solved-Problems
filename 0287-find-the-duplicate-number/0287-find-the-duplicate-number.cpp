class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//         marking the index negative and solve the problem 
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]<0){
                return abs(nums[i]);//we have to return the value 
            }
            else{
                nums[abs(nums[i])-1]*=-1;
            }
        }
        return 0;
    }
};