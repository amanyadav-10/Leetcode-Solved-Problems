class Solution {
public:
    
    // long long dp[1003][1003];
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
        sort(events.begin(),events.end());
        
        return helper(0,events,k, n,dp);
    }
    
    int helper(int i,vector<vector<int>>& events,int k,int n,vector<vector<int>> & dp){
        if(i==events.size() || k==0){
            return 0;
        }
        
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        
        int not_take = helper(i+1,events,k,n,dp);
        
//         if we decide to take we have to find the next possible index that we can take 
        int lo = i+1;
        int hi = events.size()-1;
        int nxt_idx = events.size();
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(events[mid][0]>events[i][1]){
                nxt_idx = mid;
                hi = mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        
        int take = events[i][2] + helper(nxt_idx,events,k-1,n,dp);
        
        dp[i][k] =  max(take,not_take);
        // cout<<dp[i]<<endl;
        return dp[i][k];
    }
};


