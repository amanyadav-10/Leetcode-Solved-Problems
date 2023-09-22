class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s=="") return true;
        int val =0;
        int lo =0;
        int n = t.size();
        while(lo<n){
            if(s[val]==t[lo]){
                val++;
                if(val==s.size()){
                    return true;
                }                
            }
            lo++;
        }
        return false;
    }
};

