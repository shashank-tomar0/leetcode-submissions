class Solution {
public:
    string removeOuterParentheses(string str) {
        int count = 0;
        string s;
        for(char ch : str){
            if(ch == '('){
                if(count > 0)
                    s += ch;
                count++;
            }
            else{
                count--;
                if(count > 0)
                    s+= ch;
            }
        }
        return s;
    }
};