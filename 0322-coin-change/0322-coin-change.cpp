class Solution {
public:
    int solve(int i,int t,vector<vector<int>> &memo, vector<int> coins)
    {
        if(i==0)
        {
            if(t%coins[0]==0)
            {
                return t/coins[0];
            }
            else
            {
                return 1e9;
            }
        }
        if(memo[i][t]!=-1)
        {
            return memo[i][t];
        }
        int np=0+solve(i-1,t,memo,coins);
        int p=1e9;
        if(t>=coins[i])
        {
            p=1+solve(i,t-coins[i],memo,coins);
        }
        return memo[i][t]=min(np,p);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> memo(coins.size()+1,vector<int>(amount+1,-1));
        int ans=solve(coins.size()-1,amount,memo,coins);
        if(amount==0) return 0;
        if(ans==0 or ans==1e9) return -1;
        else return ans;
    }
};