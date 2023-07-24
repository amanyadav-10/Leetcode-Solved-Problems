class Solution {
public:
    
//     the solution to the problem is actually bit manipulation
    double myPow(double x, int n) {
        if(n<0){
            x=1/x;
        }
        long long d = labs(n);
        
        double pow = 1;
        while(d){
            if(d&1){
                pow = pow*x;
            }
            
            x*=x;
            d>>=1; /// left shift operator
        }
        
        return pow;
    }
};