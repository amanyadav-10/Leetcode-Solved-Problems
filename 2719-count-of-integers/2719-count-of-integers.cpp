#define ll long long 
class Solution {
public:
    int mod = 1e9+7;
    ll dp[23][2][2][401];
    int count(string nums1, string nums2, int min_sum, int max_sum) {
        string nums1new = "";
        int n = nums1.size();
        int m = nums2.size();
        int x = m-n;
        while(x--){
            nums1new+='0';
        }
        nums1new+=nums1;
        memset(dp,-1,sizeof(dp));
        ll a = helper(0,1,1,max_sum,nums1new,nums2);
        memset(dp,-1,sizeof(dp));
        ll b = helper(0,1,1,min_sum-1,nums1new,nums2);
        ll ans = (a-b)%mod;
        return (ans<0)?ans+mod:ans;
    
    }
    
    ll helper(int i,bool tight1,bool tight2,int sum,string &nums1,string &nums2){
        if(sum<0){
            return 0;
        }
        
        if(i==nums2.size()){
            return 1;
        }
        if(dp[i][tight1][tight2][sum]!=-1){
            return dp[i][tight1][tight2][sum];
        }
        
        ll lo = ((tight1==1)?nums1[i]-'0':0);
        ll hi = ((tight2==1)?nums2[i]-'0':9);
        
        ll ans = 0;
        for(int id = lo;id<=hi;id++){
            ans = (ans%mod + helper(i+1,tight1&(lo==id),tight2&(id==hi),sum-id,nums1,nums2)%mod)%mod;
        }
        
        return dp[i][tight1][tight2][sum] = ans%mod;
        
    }
    
    
};