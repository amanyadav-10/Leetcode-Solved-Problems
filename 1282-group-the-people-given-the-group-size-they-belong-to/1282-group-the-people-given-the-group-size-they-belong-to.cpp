class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        vector<pair<int,int>> val;
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            val.push_back({nums[i],i});
        }
        sort(val.begin(),val.end());
        
        vector<vector<int>> ans;
        vector<int> vec;
        for(auto x: val){
            vec.push_back(x.second);
            if(vec.size()==x.first){
                ans.push_back(vec);
                vec.resize(0);
            }
            
        }
        return ans;
    }
};

