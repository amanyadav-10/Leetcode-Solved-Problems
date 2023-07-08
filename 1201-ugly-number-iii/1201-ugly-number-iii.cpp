

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long lo=1;
        long long hi = 2e9;
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            if(condition(n,mid,a,b,c)){
                hi = mid;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
    }
    
    bool condition(long long val,long long n,long long a,long long b,long long c){
        long long ct = 0;
        ct = (int)n/a + n/b + n/c -n/lcm(a,b) - n/lcm(a,c) -n/lcm(c,b) + n/lcm(lcm(a,b),c);
        return ct>=val;
    }
    
    long long gcd(long long a, long long b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
    long long lcm(long long a, long long b) {
        return a * b / gcd(a, b);
    }
};