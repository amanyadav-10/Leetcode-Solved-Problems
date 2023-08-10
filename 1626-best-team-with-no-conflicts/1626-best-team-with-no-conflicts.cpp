class Solution {
public:
    int bestTeamScore(vector<int>& score, vector<int>& age) {
        int n = score.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({age[i],score[i]});
        }
        int dp[1001][1002];
        memset(dp,-1,sizeof(dp));
        sort(v.begin(),v.end());
        return helper(0,v,-1,dp);
        
    }
    
    int helper(int i,vector<pair<int,int>>& v,int prev,int dp[1001][1002]){
        if(i>=v.size()){
            return 0;
        }
        
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int take = 0;
        int not_take = 0;
        if(prev==-1 || (v[i].second>=v[prev].second)){
            take = v[i].second + helper(i+1,v,i,dp);
        }
        not_take = helper(i+1,v,prev,dp);
        return dp[i][prev+1] =  max(take,not_take);
    }
};


