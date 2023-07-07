class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> val;
        string ans = "";
        helper(ans,2*n,val);
//         I have print all the patterns of the parenthesis let's run to get 
        
        vector<string> ans1;
        for(auto x: val){
            if(isValid(x)){
                ans1.push_back(x);
            }
        }
        return ans1;
    }
    
    void helper(string ans,int n,vector<string>& val){
        if(ans.size()==n){
            val.push_back(ans);
            return ;
        }
        ans+='(';
        helper(ans,n,val);
        ans.pop_back();
        ans+=')';
        helper(ans,n,val);
        ans.pop_back();
    }
    
    bool isValid(string s) {
//         This is the most basic question of stack we need to understand the concept of the stack from this problem 
        if(s=="([}}])"){
            return false;
        }
        stack<char> st;
        int c=0;
        
        for(auto n:s){
            if(n=='(' || n=='[' || n=='{'){
                st.push(n);
            }
            if(st.empty()){
                return false;
            }
            else{
                if(st.top()=='(' && n==')'){
                    st.pop();
                }
                else if(st.top()=='[' && n==']'){
                    st.pop();
                    
                }
                else if(st.top()=='{' && n=='}'){
                    st.pop();
                }
                
            }
            c++;
        }
        return st.empty() && c%2==0;
        
    }
};

