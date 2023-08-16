class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // here I can use the concept of the pair of priority Queue
        priority_queue<pair<int,int>> que;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<k;i++){
            que.push({nums[i],i});
        }
        ans.push_back(que.top().first);
        for(int i=k;i<n;i++){
            while(!que.empty() && que.top().second<=i-k){
                que.pop();
            }
            que.push({nums[i],i});
            ans.push_back(que.top().first);
        }
        
        return ans;
    }
};
