class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a = helper(s);
        string b = helper(t);
        return a==b;
        
    }
    string helper(string s){
        string a = "";
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(st.empty()){
                    continue;
                }
                else{
                    st.pop();
                    // i++;
                }
                // continue;
            }
            else{
                st.push(s[i]);
                // i++;
            }
            
        }
        
        while(!st.empty()){
            a+=st.top();
            st.pop();
        }
        return a;
    }
    
};

// this is a Question of stack and string 