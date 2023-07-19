//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        string B = A;
        reverse(A.begin(),A.end());
        int n = B.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        
        return helper(0,0,A,B,n,dp);
    }
    
    int helper(int i,int j,string s1,string s2,int n,vector<vector<int>> &dp){
        if(i>=n || j>=n){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j] = 1+helper(i+1,j+1,s1,s2,n,dp);
        }
        else{
            return dp[i][j] = max(helper(i+1,j,s1,s2,n,dp),helper(i,j+1,s1,s2,n,dp));
        }
    }
    
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends