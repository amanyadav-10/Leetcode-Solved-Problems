class Solution {
public:
    
    unordered_map<int,int> mp;
    int dp[2000][2000];
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]!=1)
            return false;
        int n = stones.size();
        for(int i =0;i<n;i++){
            mp[stones[i]]=i;
        }
        
        memset(dp,-1,sizeof(dp));
        return helper(1,1,stones);
    }
    
    bool helper(int i,int k,vector<int> &nums){
        if(i==nums.size()-1){
            return true;
        }
        
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        bool ko = false;
        bool k1 = false;
        bool k2 = false;
        
        if(mp.find(nums[i]+k)!=mp.end()){
            ko = helper(mp[nums[i]+k],k,nums);
        }
        if(k > 1 && mp.find(nums[i]+k-1)!=mp.end()){
            k1 = helper(mp[nums[i]+k-1],k-1,nums);
        }
        if(mp.find(nums[i]+k+1)!=mp.end()){
            k2 = helper(mp[nums[i]+k+1],k+1,nums);
        }
        return dp[i][k] =  k1||k2||ko;
    }
};