class Solution {
public:
    int mod = 1e9+7;
    int numMusicPlaylists(int n, int g, int k) {
        vector<vector<int>> dp(101,vector<int> (101,-1));
        return helper(0,g,k,n,dp);
    }
    
    long long  helper(int i,int g,int k,int n,vector<vector<int>> & dp){
        if(g==0){
            if(i==n){
                return 1;
            }
            else{
                return 0;
            }
            
        }
        
        if(dp[i][g]!=-1){
            return dp[i][g];
        }
        long long old = 0;
        long long new_song = (helper(i+1,g-1,k,n,dp)*(n-i))%mod;
        // int old_song = (helper(i,g-1,k,n,dp)*max(0,i-k)*1LL)%mod;
        if(i>=k){
            old = (helper(i,g-1,k,n,dp)*1LL*(i-k))%mod;
        }
        return dp[i][g] = (new_song+old)%mod;
    }
};

