class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long > ans;
        num-=3;
        if(num%3==0){
            num=num/3;
        }
        else{
            return {};
        }
        for(int i=0;i<3;i++){
            ans.push_back(num+i);
        }
        return ans;
        
    }
};