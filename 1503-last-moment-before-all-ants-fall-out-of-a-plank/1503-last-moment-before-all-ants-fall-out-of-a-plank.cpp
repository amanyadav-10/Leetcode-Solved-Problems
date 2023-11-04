class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int ans = 0;
        for(auto x: left){
            ans = max(ans,x);
        }
        for(auto x : right){
            ans = max(ans,n-x);
        }
        return ans;
        
    }
};
// this is a problem of brain teaser and simulation and not basically the questoin of DSA
