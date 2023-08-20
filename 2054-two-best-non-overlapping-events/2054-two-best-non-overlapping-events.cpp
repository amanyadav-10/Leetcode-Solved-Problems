class Solution {
public:
    long long dp[100005][3];
    int maxTwoEvents(vector<vector<int>>& events) {
        memset(dp,-1,sizeof(dp));
        sort(events.begin(),events.end());
        return helper(0,events,2);
    }
    
    int helper(int i,vector<vector<int>> &events,int k){
        if(i==events.size() || k==0){
            return 0;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
            
        }
        int not_take = helper(i+1,events,k);
        
        int nxt_idx = events.size();
        int lo = i+1;
        int hi = events.size()-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(events[mid][0]>events[i][1]){
                nxt_idx = mid;
                hi =mid-1;
             }
            else{
                lo = mid+1;
            }
        }
        int take = events[i][2] + helper(nxt_idx,events,k-1);
        return dp[i][k] = max(not_take,take);
        
    }
    
    
};