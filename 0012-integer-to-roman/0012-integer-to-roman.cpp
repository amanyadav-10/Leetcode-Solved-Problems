class Solution {
public:
    string intToRoman(int num) {
        string one[]  ={"","I","II","III","IV","V","VI","VII","VIII","IX","X"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hund[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thous[] = {"","M","MM","MMM"};
        
        string ans = thous[(num)/1000] + hund[(num%1000)/100] + tens[(num%100)/10] + one[(num%10)] ;
        
        return ans;
        
    }
};
