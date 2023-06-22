class Solution {
public:
//     exactly k = atmost(k)-atMost(k-1)
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
    
    int atMost(vector<int>& ans,int k){
        int res = 0;
        int left = 0;
        int n = ans.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[ans[i]]++;
            while(mp.size()>k){
                mp[ans[left]]--;
                if(mp[ans[left]]==0){
                    mp.erase(ans[left]);
                }
                left++;
            }
            
            res+=i-left+1;
        }
        return res;
//         i have to count here not find max length
    }
};
