
class Solution {
public:

    #define ll long long 

    ll minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();

        vector<pair<ll, ll>> v; 
        vector<ll> pre(n), suf(n);
        for(int i = 0; i < n; i++) {
            ll num = (ll)nums[i];
            ll c = (ll)cost[i];
            v.push_back({num, c});
        }

        sort(v.begin(), v.end()); 
        for(int i = 0; i < n; i++) {
            pre[i] = v[i].second; 
            suf[i] = v[i].second; 
            if(i) pre[i] += pre[i-1]; 
        }

        for(int i = n-2; i >= 0; i--) {
            suf[i] += suf[i+1];
        }
        vector<ll> dp1(n, 0), dp2(n, 0);

        for(int i = 1; i < n; i++) {
            int diff = v[i].first - v[i-1].first;
            dp1[i] = dp1[i-1] + diff*pre[i-1]; 
        }

        for(int i = n-2; i >= 0; i--) {
            int diff = v[i+1].first - v[i].first;
            dp2[i] = dp2[i+1] + diff*suf[i+1];
        }

        ll ans = 1e18; 

        for(int i = 0; i < n; i++) {
            ans = min(ans, dp1[i] + dp2[i]);
        }
        return ans;
    }
};