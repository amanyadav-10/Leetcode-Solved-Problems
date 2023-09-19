class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x: nums){
            if(mp[x]==1){
                return x;
            }
            mp[x]++;
        }
        return 0;
        
    }
};