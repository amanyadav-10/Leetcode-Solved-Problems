//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        
    // this is the standard problem of the sliding window template 2
        int lo = 0;
        long long pro = 1;
        int ans = 0;
        for(int i =0;i<n;i++){
            pro*=a[i];
            while(lo<=i && pro>=k){
                pro/=a[lo];
                lo++;
            }
            ans+=i-lo+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends