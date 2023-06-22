class Solution {
public:
    int atMost(vector<int>& ans,int k){
        int left =0;
        int res = 0;
        int cnt = 0;
        int n = ans.size();
        for(int i=0;i<n;i++){
            cnt+=ans[i];
            while(cnt>k){
                cnt-=ans[left];
                left++;
            }
            res+=i-left+1; //count the number of subarrays 
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
//         simply change the array to binary array and solve the problem easily
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                nums[i]=1;
            }
            else{
                nums[i]=0;
            }
        }
        return atMost(nums,k)-atMost(nums,k-1);
    }
    
    
};