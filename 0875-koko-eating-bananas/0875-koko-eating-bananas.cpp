class Solution {
public:
    bool predicate(int k,int h,vector<int>& piles){
        int total =0;
        for(auto x: piles){
            total += (x+k-1)/k; // it is the formula for the lower limit of a division
            
        }
        return total<=h;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = 0;
        for(auto x: piles){
            hi = max(hi,x);
        }
        
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(predicate(mid,h,piles)){
                hi=mid;
            }
            else{
                lo = mid+1;
            }
        }
        
        return lo;
        
    }
};


// in this Question also we had to understand how to write the predicate function and then we could easily write the binary search on answer on this problem