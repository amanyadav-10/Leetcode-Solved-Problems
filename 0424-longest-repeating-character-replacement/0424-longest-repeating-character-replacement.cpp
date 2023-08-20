class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans  = 0;
        int n = s.size();
        int left = 0;
        int maxVal = 0;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            maxVal = max(maxVal,mp[s[i]]);
            while(i-left+1-maxVal>k){
                mp[s[left]]--;
                left++;
            }
            ans = max(ans,i-left+1);
        }
        return ans;
    }
};