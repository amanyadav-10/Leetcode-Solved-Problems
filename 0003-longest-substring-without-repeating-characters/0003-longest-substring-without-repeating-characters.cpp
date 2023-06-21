class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int left = 0;
        int n = s.size();
        int res = 0;
        for(int r=0;r<n;r++){
//             update the right pointer
            mpp[s[r]]++;
            while(mpp[s[r]]>1){ // repeating character the condition is false
                mpp[s[left]]--;
                left++; // move the pointer
            }
            res = max(res,r-left+1);
//             update the res
        }
        return res;
        
        
    }
};