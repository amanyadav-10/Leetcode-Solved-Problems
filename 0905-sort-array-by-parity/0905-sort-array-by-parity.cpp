class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> val;
        vector<int> ans;
        for(auto x: nums){
            if(x%2==0){
                ans.push_back(x);
            }
            else{
                val.push_back(x);
            }
        }
        for(auto x: val){
            ans.push_back(x);
        }
        return ans;
    }
};