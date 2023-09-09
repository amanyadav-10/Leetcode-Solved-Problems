class Solution {
public:
    int mod = 1e9+7;
    int dp[301][301];
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        vector<int> ans;
        int i=1;
        while(pow(i,x)<=n){
            ans.push_back(pow(i,x));
            i++;
        }
        cout<<ans.size()<<endl;
        
        return helper(0,n,ans);
        
    }
    
    int helper(int i,int n,vector<int> &nums){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][n]!=-1){
            return dp[i][n];
        }
        int pick = 0;
        int nt = 0;
        if(n>=nums[i]){
            pick = helper(i+1,n-nums[i],nums)%mod;
        }
        
        nt = helper(i+1,n,nums)%mod;
        return dp[i][n] = (pick+nt)%mod;
    }
};