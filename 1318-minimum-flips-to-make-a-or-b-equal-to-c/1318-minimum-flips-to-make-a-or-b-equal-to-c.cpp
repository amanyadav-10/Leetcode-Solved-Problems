class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while(c || b || a){
            if(c&1){//if it is one we have to keep any of b or a as 1
                if(!(a&1) && !(b&1)){
                    ans++;
                }
            }
            else{
//                 if c is zero we can have 1 0 01 or  0 0
                
                if(a&1 && b&1){
                    ans+=2;
                }
                else if(a&1 || b&1){
                    ans++;
                }
                
            }
            c=c>>1;
            b=b>>1;
            a=a>>1;
        }
        return ans;
    }
    
    // this is the bitwise solution of the problem
    
};