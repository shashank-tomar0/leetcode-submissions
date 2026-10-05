class Solution {
public:
    int scoreOfParentheses(string s) {
        int len = 0;
        int depth = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(')
                depth++;
            else{
                depth--;
                if(s[i - 1] == '(')
                    len+= (1 << depth);
            }
        }
        return len;
    }
};