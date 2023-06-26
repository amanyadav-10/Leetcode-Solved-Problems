class Solution {
struct Compare{
bool operator() (const pair<int,string> &p1, const pair<int,string> &p2) {
        if(p1.first == p2.first) return p1.second > p2.second;
  
        return p1.first < p2.first;
        }
};

//     this is the comparator that we have create
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto x: words){
            mp[x]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        for(auto x: mp){
            pq.push({x.second,x.first});
        }
        
        vector<string> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
