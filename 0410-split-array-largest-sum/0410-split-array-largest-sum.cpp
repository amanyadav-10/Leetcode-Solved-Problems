class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        
        int lo = INT_MIN;
        int hi = 0;
        for(auto x : nums){
            lo = max(lo,x);
            hi+=x;
        }
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(condition(mid,nums,k)){
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }
        return lo;
        
    }
    
    
    bool condition(int mid,vector<int>& ans,int k){
//         if max sum is mid can we didvide the array into k arrays
        int no = 1;
        int sum  = 0;
        for(auto x : ans){
            sum+=x;
            if(sum>mid){
                no++;
                sum = x;
            }
        }
        return no<=k;
    }
};
