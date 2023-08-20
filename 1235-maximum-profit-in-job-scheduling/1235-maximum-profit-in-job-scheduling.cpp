class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> vec(n);
        for(int i=0;i<n;i++){
            vec[i] = {startTime[i],endTime[i],profit[i]};
        }
        sort(vec.begin(),vec.end());
        vector<int> dp(n,-1);
        return helper(0,vec,dp);
        
    }
    
    int helper(int i,vector<vector<int>>& arr,vector<int>  &dp){
        if(i==arr.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int not_take = helper(i+1,arr,dp);
//        for the take case 
        int nxt_idx = arr.size();
//         Binary search to find the next probable index 
        int lo = i+1;
        int hi = arr.size()-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(arr[i][1]<=arr[mid][0]){
                nxt_idx = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }     
        int take = arr[i][2] + helper(nxt_idx,arr,dp);
        return dp[i] =  max(take,not_take);
    }
};