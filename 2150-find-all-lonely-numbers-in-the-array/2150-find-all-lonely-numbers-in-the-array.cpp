class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto x : nums){
            mp[x]++;
        }
        for(auto x: nums){
            if(mp[x-1]==0 && mp[x+1]==0 && mp[x]==1){
                ans.push_back(x);
            }
        }
        return ans;
    }
};