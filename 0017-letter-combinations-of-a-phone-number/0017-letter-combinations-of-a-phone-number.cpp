class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        
        vector<string> pad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        vector<string> output;
        
        string temp;
        
        helper(digits,output,temp,pad,0);
        
        return output;
        
    }
    
    void helper(string dig,vector<string>& out,string temp,vector<string>& pad,int index){
        if(index==dig.size()){
            out.push_back(temp);
            return ;
        }
        
        string val = pad[dig[index]-'0'];
        
        for(int i=0;i<val.size();i++){
            temp.push_back(val[i]);
            helper(dig,out,temp,pad,index+1);
            temp.pop_back();
        }
    }
};

// this is an important recursive problem and teaches us the concept od the 
