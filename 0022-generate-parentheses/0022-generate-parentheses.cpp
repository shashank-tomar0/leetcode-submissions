#include <vector>
#include <string>

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current_string = "";
        backtrack(0, 0, n, current_string, result);
        return result;
    }

private:
    void backtrack(int open_count, int close_count, int n, string& current_string, vector<string>& result) {
        if (current_string.length() == 2 * n) {
            result.push_back(current_string);
            return;
        }
        if (open_count < n) {
            current_string.push_back('(');                                      
            backtrack(open_count + 1, close_count, n, current_string, result);  
            current_string.pop_back();                                          
        }
        if (close_count < open_count) {
            current_string.push_back(')');                                      
            backtrack(open_count, close_count + 1, n, current_string, result); 
            current_string.pop_back();                                          
        }
    }
};