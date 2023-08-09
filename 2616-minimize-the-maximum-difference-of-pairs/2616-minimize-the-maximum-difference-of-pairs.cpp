class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        
        sort(nums.begin(),nums.end());
        
        int lo =0;
        int hi = nums.back()-nums[0];
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(solve(nums,mid,p)){
                hi = mid;
            }
            else{
                lo =mid+1;
            }
        }
        return lo;
        
        
//         this is the formal template of the binary search problem 
    }
    
    bool solve(vector<int>& nums,int d,int p){
        int n=nums.size();
        int c=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]<=d){
                c++;
                i++;
            }
        }
        if(c>=p){
            return true;
        }
        return false;
        
    }
};



