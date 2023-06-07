class Solution {
public:
    int minFlips(int a, int b, int c) {
        const int n = 32;
        string bin_a = std::bitset<n>(a).to_string();
        string bin_b = std::bitset<n>(b).to_string();
        string bin_c = std::bitset<n>(c).to_string();
        
//         this is the function to convert the given binary number into a string
        int ans = 0;
        for(int i=0;i<n;i++){
            if(bin_c[i]=='1'){
                if(bin_a[i]=='0' && bin_b[i]=='0'){
                    ans++;
                }
            }
            else{
                if(bin_a[i]=='0' && bin_b[i]=='0'){
                    continue;
                }
                else if(bin_a[i]=='1' && bin_b[i]=='1'){
                    ans+=2;
                }
                else{
                    ans+=1;
                }
            }
        }
        return ans;
        
    }
};