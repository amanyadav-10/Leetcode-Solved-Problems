class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int m = offers.size();
        sort(offers.begin(),offers.end());
        vector<int> dp(m,-1);
        return helper(0,offers,dp);
    }
    
    int helper(int i,vector<vector<int>> &offers,vector<int>& dp){
        if(i==offers.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int not_take = helper(i+1,offers,dp);
//         i will not add profit in this case here
        int nxt_idx = offers.size();
        int lo = i+1;
        int hi = offers.size()-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(offers[i][1]<offers[mid][0]){
                nxt_idx = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1; // we have to get the index with greater value , we cannot buy one house twice
            }
        }
        
        int take = offers[i][2] + helper(nxt_idx,offers,dp);
        return dp[i] = max(take,not_take);
    }
};