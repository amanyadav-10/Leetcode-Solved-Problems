class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(),grades.end());
        int n = grades.size();
        int prev_sum =0;
        int prev_l = 0;
        int cur_sum = 0;
        int cur_l = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            cur_sum+=grades[i];
            cur_l++;
            if(cur_sum>prev_sum && cur_l>prev_l){
                ans++;
                prev_sum = cur_sum;
                prev_l = cur_l;
                cur_sum = 0;
                cur_l = 0;
            }
        }
        return ans;
    }
};