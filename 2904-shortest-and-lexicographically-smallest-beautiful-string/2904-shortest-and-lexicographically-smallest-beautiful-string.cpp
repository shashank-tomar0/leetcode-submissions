class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int ones = 0;
        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            if (s[right] == '1')
                ones++;
            while (ones == k) {
                while (left <= right && s[left] == '0') {
                    left++;
                }
                string curr = s.substr(left , right -left+1);
                 if (ans.empty() || curr.length() < ans.length() || (curr.length() == ans.length() && curr < ans)) {
                ans = curr;
                }
            ones--;
            left++;
        }
    }
        return ans;
    }
};