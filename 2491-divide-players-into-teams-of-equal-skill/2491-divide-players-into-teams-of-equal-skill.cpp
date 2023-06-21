class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(),skill.end());
        long long val = skill[0]+skill[n-1];
        int i=1;
        if(n%2) return -1;
        while(i<n-1){
            if(val!=skill[i]+skill[n-i-1]){
                return -1;
            }
            i++;
        }
        
        long long ans = 0;
        for(int i=0;i<n/2;i++){
            ans+=skill[i]*skill[n-i-1];
        }
        return ans;
    }
};