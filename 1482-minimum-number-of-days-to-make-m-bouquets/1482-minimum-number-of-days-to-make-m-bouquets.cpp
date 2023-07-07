class Solution {
public:
    int minDays(vector<int>& bloomDay, long long m, long long  k) {
        
//         if the number of flowers we require is less than the condition we do not need it 
        long long  n = bloomDay.size();
        if(m*k > n) return -1;
        int lo = INT_MAX;
        int hi = INT_MIN;
        for(auto x : bloomDay){
            lo = min(lo,x);
            hi = max(hi,x);
        }
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(condition(bloomDay,m,k,mid)){
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }
        return lo;
        
        
    }
    
    bool condition(vector<int>& ans,long long  m,long long k,int mid){
        int sum = 0;
        int val = 0;
        int n = ans.size();
        for(int i=0;i<n;i++){
            if(ans[i]<=mid){
                sum++;
            }
            else{
                sum=0;
            }
            if(sum==k){
                val++;
                sum = 0; 
            }
        }
        
        return val>=m;
    }
};
