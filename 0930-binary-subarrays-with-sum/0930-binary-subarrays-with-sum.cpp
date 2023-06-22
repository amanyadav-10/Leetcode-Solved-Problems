class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
    int atMost(vector<int>& nums,int goal){
        if(goal<0){
            return 0;
        }
        int sum = 0;
        int left = 0;
        
        int res = 0;
        
        int n= nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            res+=i-left+1;
        }
        return res;
    }
};