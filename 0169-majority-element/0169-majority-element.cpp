class Solution {
public:
    int majorityElement(vector<int>& nums) {
//         the moore voting algorithm solution to the problem 
        int n = nums.size();
        int count = 1;
        int res  = nums[0];
        for(int i=1;i<n;i++){
            if(res==nums[i]){
                count++;
                
            }
            else{
                count--;
            }
            if(count ==0){
                res = nums[i]; 
                count = 1;
                // new element is potentially the majority element now
            }
        }
        return res;
        
    }
};