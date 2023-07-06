class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
//         We have to solve it using the O(n) solution and O(nlogn) solution 
        int l=0;
        int l1=0;
        int sum=0;
        int ans=INT_MAX;
        // int ans=1;
        while(l1<nums.size()){
            // This  array can stil be o(n because each element will be visited once in the algorithm )
            sum+=nums[l1++];
            // count++;
            while(sum>=target){
                ans=min(ans,l1-l);
                sum-=nums[l++];
            }
            
            
            
        }
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
        
        
        
    }
};