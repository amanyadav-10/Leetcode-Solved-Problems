class Solution {
public:
    int majorityElement(vector<int>& nums) {
//         Moore voting algorithm
        int count =1;
        int res=nums[0];
//         candidate for majority element
        for(int i=1;i<nums.size();i++){
            if(count==0){
                res=nums[i];
                count++;
                continue;
            }
            if(nums[i]!=res){
                count -=1;
            }          
            else{
                count+=1;
            }
        }
        return res;
    }
};