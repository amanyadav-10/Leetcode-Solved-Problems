class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        string t = answerKey;
        int val1 = helper(t,k,'T');
        int val2 = helper(t,k,'F');
        return max(val1,val2);
    }
    
    int helper(string s,int k,char a){
        int n = s.size();
        int left = 0;
        int ans = 0;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp[a]>k){
                mp[s[left]]--;
                left++;
            }
            ans = max(ans,i-left+1);
        }
        return ans;
    }
};