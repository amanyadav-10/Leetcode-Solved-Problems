class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int ans = 0;
        int maxOccur = 0;
        unordered_map<char,int> mp;
        
        int n = s.size();
        
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            
            maxOccur = max(maxOccur,mp[s[i]]);
            
            while(i-left+1-maxOccur>k){
                
                mp[s[left]]--;
                left++;
            }
            ans=max(ans,i-left+1);
            
        }   
        return ans;
    }
};