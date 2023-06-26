class Solution {
public:
    int maximumScore(int a, int b, int c) {
        
        int ans = 0;
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        while(true){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(y<=0){
                return ans;
            }
            x--;
            y--;
            ans++;
            pq.push(x);
            pq.push(y);
        }
        return ans;
        
    }
};