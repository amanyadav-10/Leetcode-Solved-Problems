class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int ans = 0;
        int n = fruits.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
//             update
            mp[fruits[i]]++;
            while(mp.size()>2){
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0){
                    mp.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans,i-left+1);
        }
        return ans;
    }
    
//     it gets reduced to the basic sliding window problem of maximum length window with at most 
};