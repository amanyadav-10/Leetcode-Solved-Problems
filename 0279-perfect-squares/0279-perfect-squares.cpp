class Solution {
public:
    int numSquares(int n) {
//         we can create a vector containing the sqrt of the numbers till n;
        vector<int> nums;
        int p =1;
        int cur = 1;
        while(cur<=n){
            cur = pow(p,2);
            nums.push_back(cur);
            p++;
        }
        int s = nums.size();
        
        vector<vector<int>> dp(s+1,vector<int>(n+1,0));
        for(int i=0;i<=s;i++){
            dp[i][0] = 0;//if the size is zero
        }
        for(int j =0;j<=n;j++){
            dp[0][j] = INT_MAX-1; // if the value is zero the answer will be infinte
        }
        
        for(int i=1;i<=s;i++){
            for(int j=1;j<=n;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = min((dp[i][j-nums[i-1]]+1),dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[s][n];
    }
};