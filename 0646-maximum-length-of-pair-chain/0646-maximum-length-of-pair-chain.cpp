class Solution {
public:
    int dp[1001][1005];
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp,-1,sizeof(dp));
        int n = pairs.size();
        sort(pairs.begin(),pairs.end());
        return helper(0,pairs,-1);
    }
    
    int helper(int i,vector<vector<int>> &pairs,int prev){
        if(i==pairs.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int take = INT_MIN;
        
        if( prev==-1 || pairs[prev][1]<pairs[i][0]){
            take = 1+helper(i+1,pairs,i);
        }
        int not_take = helper(i+1,pairs,prev);
        
        return dp[i][prev+1] = max(take,not_take);
    }
};