class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1){
            return nums.size();
        }
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int count = 0;
        int ans= 0;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]==nums[i]){
                continue;
            }
            if(nums[i+1]-nums[i]==1){
                count++;
            }else{
                count = 0;
            }
            ans=max(count,ans);
            
        }
        return ans+1;
        
    }
};

