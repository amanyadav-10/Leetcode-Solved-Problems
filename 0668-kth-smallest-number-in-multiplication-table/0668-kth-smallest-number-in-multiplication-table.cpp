class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 1;
        int hi = m*n;
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(condition(mid,k,m,n)){
                hi  =mid;
            }
            else{
                lo = mid+1;
            }
            
        }
        return lo;
        
    }
    
    bool condition(int mid,int k,int m,int n){
        int ct = 0;
        for(int i=1;i<=m;i++){
            ct+=min(n,mid/i);
        }
        return ct>=k; // if we get true we have to check further because we have find the minimum true;
    }
};