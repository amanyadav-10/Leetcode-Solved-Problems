class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
//         I can use priority queu
        vector<int> val;
        int n=weights.size();
        if(k==1 || k==n){
            return 0;
        }
        for(int i=0;i<n-1;i++){
            val.push_back(weights[i]+weights[i+1]);
        }
        sort(val.begin(),val.end());
        long long min_sum = 0;
        long long max_sum = 0;
        for(int i=0;i<k-1;i++){
            min_sum+=val[i];
            max_sum+=val[n-i-2];
        }
        return max_sum-min_sum;
        
        
    }
};